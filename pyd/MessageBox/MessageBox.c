#include <Python.h>
#include <windows.h>

static PyObject* Py_MessageBox(PyObject* self,char* title, char* message, int icon, int button) {
    if (title == NULL || message == NULL) {
        return 1;
    }
    if (icon == 0) {
        if (button == 0) {
            MessageBox(NULL, message, title, MB_OK);
        } else {
            MessageBox(NULL, message, title, button);
        }
    }
    else {
        if (button == 0) {
            MessageBox(NULL, message, title, icon);
        } else {
            MessageBox(NULL, message, title, icon | button);
        }
    }
}

static PyMethodDef MyMethods[] = {
    {"Py_MessageBox", Py_MessageBox, METH_VARARGS,},
    {NULL, NULL, 0, NULL} 
};

static struct PyModuleDef mymodule_definition = {
    PyModuleDef_HEAD_INIT,
    "MessageBox",       
    "a api connect python to c", 
    -1,
    MyMethods
};
PyMODINIT_FUNC PyInit_MessageBox(void) {
    return PyModule_Create(&mymodule_definition);
}