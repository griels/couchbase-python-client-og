#include "pycbc.h"
#include "oputil.h"
#include "pycbc_http.h"
#include <libcouchbase/ixmgmt.h>
static void
n1ql_row_callback(lcb_t instance, int ign, const lcb_RESPN1QL *resp)
{
    pycbc_MultiResult *mres=NULL;
    lcb_respn1ql_cookie(resp, (const void **) &mres);
    pycbc_Bucket *bucket = mres->parent;
    pycbc_ViewResult *vres;
    const char * const * hdrs = NULL;
    short htcode = 0;
    const lcb_RESPHTTP* htresp=NULL;

    PYCBC_CONN_THR_END(bucket);
    vres = (pycbc_ViewResult *)PyDict_GetItem((PyObject*)mres, Py_None);
    lcb_respn1ql_http_response(resp,&htresp);
    if (htresp) {
        lcb_resphttp_headers(htresp, &hdrs);
        htcode=lcb_resphttp_status(htresp);
    }

    {
        const char *rows=NULL;
        size_t row_count=0;
        lcb_respn1ql_row(resp, &rows, &row_count);
        if (lcb_respn1ql_is_final(resp)) {
            pycbc_httpresult_add_data(mres, &vres->base, rows, row_count);
        } else {
            /* Like views, try to decode the row and invoke the callback; if we can */
            /* Assume success! */
            pycbc_viewresult_addrow(vres, mres, rows, row_count);
        }
    }
    pycbc_viewresult_step(vres, mres, bucket, lcb_respn1ql_is_final(resp));

    if (lcb_respn1ql_is_final(resp)) {
        pycbc_httpresult_complete(&vres->base, mres, lcb_respn1ql_status(resp), htcode, hdrs);
    } else {
        PYCBC_CONN_THR_BEGIN(bucket);
    }
}

TRACED_FUNCTION(LCBTRACE_OP_REQUEST_ENCODING,
                static,
                PyObject *,
                query_common,
                pycbc_Bucket *self,
                const char *params,
                unsigned nparams,
                const char *host,
                int is_prepared,
                int is_xbucket)
{
    PyObject *ret = NULL;
    pycbc_MultiResult *mres;
    pycbc_ViewResult *vres;
    lcb_error_t rc;
    lcb_CMDN1QL* cmd = NULL;
    if (-1 == pycbc_oputil_conn_lock(self)) {
        return NULL;
    }
    if (self->pipeline_queue) {
        PYCBC_EXC_WRAP(PYCBC_EXC_PIPELINE, 0,
                       "N1QL queries cannot be executed in "
                       "pipeline context");
    }

    mres = (pycbc_MultiResult *)pycbc_multiresult_new(self);
    vres = pycbc_propagate_view_result(context);
    pycbc_httpresult_init(&vres->base, mres);
    vres->rows = PyList_New(0);
    vres->base.format = PYCBC_FMT_JSON;
    vres->base.htype = PYCBC_HTTP_HN1QL;
    {
        lcb_cmdn1ql_create(&cmd);
        lcb_cmdn1ql_callback(cmd,n1ql_row_callback);
        lcb_cmdn1ql_query(cmd, params, nparams);
        //lcb_cmdn1ql_payload()
        //cmd.content_type = "application/json";
        lcb_cmdn1ql_handle(cmd,&vres->base.u.nq);
        //cmd.handle = &vres->base.u.nq;

        if (is_prepared) {
            lcb_cmdn1ql_adhoc(cmd,1);
            //cmd.cmdflags |= LCB_CMDN1QL_F_PREPCACHE;
        }
        if (is_xbucket) {
#if PYCBC_LCB_API<0x030001
            cmd->cmdflags |= LCB_CMD_F_MULTIAUTH;
#endif
        }
#if PYCBC_LCB_API<0x030001
        if (host) {
            /* #define LCB_CMDN1QL_F_CBASQUERY 1<<18 */
            cmd->cmdflags |= (1 << 18);
            cmd->host = host;
        }
#endif
//        PYCBC_TRACECMD_SCOPED_NULL(
  //              rc, n1ql, self->instance, vres->base.u.nq, context, mres, cmd);
        PYCBC_TRACECMD_SCOPED_NULL(
                rc, n1ql, self->instance, cmd, vres->base.u.nq, context, mres, cmd);
    }
    if (rc != LCB_SUCCESS) {
        PYCBC_EXC_WRAP(PYCBC_EXC_LCBERR, rc, "Couldn't schedule n1ql query");
        goto GT_DONE;
    }

    ret = (PyObject *)mres;
    mres = NULL;

    GT_DONE:
    Py_XDECREF(mres);
    pycbc_oputil_conn_unlock(self);
    return ret;

}
PyObject *
pycbc_Bucket__n1ql_query(pycbc_Bucket *self, PyObject *args, PyObject *kwargs)
{
    const char *params = NULL;
    pycbc_strlen_t nparams = 0;
    int prepared = 0, cross_bucket = 0;
    PyObject *result = NULL;
    static char *kwlist[] = { "params", "prepare", "cross_bucket", NULL };
    if (!PyArg_ParseTupleAndKeywords(
        args, kwargs, "s#|ii", kwlist, &params,
        &nparams, &prepared, &cross_bucket)) {

        PYCBC_EXCTHROW_ARGS();
        return NULL;
    }
    PYCBC_TRACE_WRAP_TOPLEVEL(result,
                              LCBTRACE_OP_REQUEST_ENCODING,
                              query_common,
                              self->tracer,
                              self,
                              params,
                              nparams,
                              NULL,
                              prepared,
                              cross_bucket);
    return result;
}

PyObject *
pycbc_Bucket__cbas_query(pycbc_Bucket *self, PyObject *args, PyObject *kwargs)
{
    const char *host = NULL;
    const char *params = NULL;
    pycbc_strlen_t nparams = 0;
    static char *kwlist[] = { "params", "host", NULL };
    PyObject *result = NULL;
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s#s", kwlist,
        &params, &nparams, &host)) {
        PYCBC_EXCTHROW_ARGS();
        return NULL;
    }
    PYCBC_TRACE_WRAP_TOPLEVEL(result,
                              LCBTRACE_OP_REQUEST_ENCODING,
                              query_common,
                              self->tracer,
                              self,
                              params,
                              nparams,
                              host,
                              0,
                              0);
    return result;
}
