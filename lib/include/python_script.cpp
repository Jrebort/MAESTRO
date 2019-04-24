#include <Python.h>

//int great_function_from_python(int a);

int great_function_from_python(char *a) {
	Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('../../')");
    PyObject *pModule = PyImport_ImportModule("plot");
    PyObject *pDict = PyModule_GetDict(pModule);
    PyObject *pFunc = PyObject_GetAttrString(pModule, "printf");
    PyObject *pArg = Py_BuildValue("(s)", a);
    PyEval_CallObject(pFunc, pArg);
    Py_Finalize();
    return 0;
}

int main(){
	char string[7]="Hello";
	great_function_from_python(string);
}