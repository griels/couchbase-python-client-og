/* This file was generated by PyBindGen 0.0.0.0 */
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stddef.h>


#if PY_VERSION_HEX >= 0x03000000
#if PY_VERSION_HEX >= 0x03050000
typedef PyAsyncMethods* cmpfunc;
#else
typedef void* cmpfunc;
#endif
#define PyCObject_FromVoidPtr(a, b) PyCapsule_New(a, NULL, b)
#define PyCObject_AsVoidPtr(a) PyCapsule_GetPointer(a, NULL)
#define PyString_FromString(a) PyBytes_FromString(a)
#define Py_TPFLAGS_CHECKTYPES 0 /* this flag doesn't exist in python 3 */
#endif


#if     __GNUC__ > 2
# define PYBINDGEN_UNUSED(param) param __attribute__((__unused__))
#elif     __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 4)
# define PYBINDGEN_UNUSED(param) __attribute__((__unused__)) param
#else
# define PYBINDGEN_UNUSED(param) param
#endif  /* !__GNUC__ */

#ifndef _PyBindGenWrapperFlags_defined_
#define _PyBindGenWrapperFlags_defined_
typedef enum _PyBindGenWrapperFlags {
   PYBINDGEN_WRAPPER_FLAG_NONE = 0,
   PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED = (1<<0),
} PyBindGenWrapperFlags;
#endif


#include "couchbase++.h"
static PyMethodDef a2_Couchbase_Internal_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef a2_Couchbase_Internal_moduledef = {
    PyModuleDef_HEAD_INIT,
    "a2.Couchbase.Internal",
    NULL,
    -1,
    a2_Couchbase_Internal_functions,
};
#endif

static PyObject *
inita2_Couchbase_Internal(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&a2_Couchbase_Internal_moduledef);
    #else
    m = Py_InitModule3((char *) "a2.Couchbase.Internal", a2_Couchbase_Internal_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef a2_Couchbase_OpInfo_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef a2_Couchbase_OpInfo_moduledef = {
    PyModuleDef_HEAD_INIT,
    "a2.Couchbase.OpInfo",
    NULL,
    -1,
    a2_Couchbase_OpInfo_functions,
};
#endif

static PyObject *
inita2_Couchbase_OpInfo(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&a2_Couchbase_OpInfo_moduledef);
    #else
    m = Py_InitModule3((char *) "a2.Couchbase.OpInfo", a2_Couchbase_OpInfo_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef a2_Couchbase_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef a2_Couchbase_moduledef = {
    PyModuleDef_HEAD_INIT,
    "a2.Couchbase",
    NULL,
    -1,
    a2_Couchbase_functions,
};
#endif

static PyObject *
inita2_Couchbase(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&a2_Couchbase_moduledef);
    #else
    m = Py_InitModule3((char *) "a2.Couchbase", a2_Couchbase_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    submodule = inita2_Couchbase_Internal();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Internal", submodule);
    submodule = inita2_Couchbase_OpInfo();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "OpInfo", submodule);
    return m;
}
static PyMethodDef a2_lcb_trace_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef a2_lcb_trace_moduledef = {
    PyModuleDef_HEAD_INIT,
    "a2.lcb.trace",
    NULL,
    -1,
    a2_lcb_trace_functions,
};
#endif

static PyObject *
inita2_lcb_trace(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&a2_lcb_trace_moduledef);
    #else
    m = Py_InitModule3((char *) "a2.lcb.trace", a2_lcb_trace_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef a2_lcb_views_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef a2_lcb_views_moduledef = {
    PyModuleDef_HEAD_INIT,
    "a2.lcb.views",
    NULL,
    -1,
    a2_lcb_views_functions,
};
#endif

static PyObject *
inita2_lcb_views(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&a2_lcb_views_moduledef);
    #else
    m = Py_InitModule3((char *) "a2.lcb.views", a2_lcb_views_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef a2_lcb_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef a2_lcb_moduledef = {
    PyModuleDef_HEAD_INIT,
    "a2.lcb",
    NULL,
    -1,
    a2_lcb_functions,
};
#endif

static PyObject *
inita2_lcb(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&a2_lcb_moduledef);
    #else
    m = Py_InitModule3((char *) "a2.lcb", a2_lcb_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    submodule = inita2_lcb_trace();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "trace", submodule);
    submodule = inita2_lcb_views();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "views", submodule);
    return m;
}
static PyMethodDef a2_std_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef a2_std_moduledef = {
    PyModuleDef_HEAD_INIT,
    "a2.std",
    NULL,
    -1,
    a2_std_functions,
};
#endif

static PyObject *
inita2_std(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&a2_std_moduledef);
    #else
    m = Py_InitModule3((char *) "a2.std", a2_std_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef a2_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef a2_moduledef = {
    PyModuleDef_HEAD_INIT,
    "a2",
    NULL,
    -1,
    a2_functions,
};
#endif


#if PY_VERSION_HEX >= 0x03000000
    #define MOD_ERROR NULL
    #define MOD_INIT(name) PyObject* PyInit_##name(void)
    #define MOD_RETURN(val) val
#else
    #define MOD_ERROR
    #define MOD_INIT(name) void init##name(void)
    #define MOD_RETURN(val)
#endif
#if defined(__cplusplus)
extern "C"
#endif
#if defined(__GNUC__) && __GNUC__ >= 4
__attribute__ ((visibility("default")))
#endif


MOD_INIT(a2)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&a2_moduledef);
    #else
    m = Py_InitModule3((char *) "a2", a2_functions, NULL);
    #endif
    if (m == NULL) {
        return MOD_ERROR;
    }
    submodule = inita2_Couchbase();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Couchbase", submodule);
    submodule = inita2_lcb();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "lcb", submodule);
    submodule = inita2_std();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "std", submodule);
    return MOD_RETURN(m);
}
