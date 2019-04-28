#include <Python.h>

//int great_function_from_python(int a);

int great_function_from_python() {
	Py_Initialize();
    PyRun_SimpleString("print 'Python Start'");
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('../../../')");
    PyObject *pModule = PyImport_ImportModule("plot");
//    PyObject *pDict = PyModule_GetDict(pModule);
    PyRun_SimpleString("print 'Python Start'");
    PyObject *pFunc = PyObject_GetAttrString(pModule, "main");
//    PyObject *pArg = Py_BuildValue("(s)", "Hello Charity");
    PyEval_CallObject(pFunc, NULL);
    Py_Finalize();
    PyRun_SimpleString("print 'Python end'");
    return 0;
}

int main(){
	
	great_function_from_python();
}