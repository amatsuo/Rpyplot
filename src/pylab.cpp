#include <Rcpp.h>
#include <Python.h>
#include <stdio.h>
#ifndef WIN32
#include <dlfcn.h>
#endif


using namespace Rcpp;
typedef Rcpp::XPtr<PyObject> PyList;

//See http://gallery.rcpp.org/articles/rcpp-python/

//[[Rcpp::export]]
void pyrun(std::string command){
    PyRun_SimpleString(command.c_str());
}

//[[Rcpp::export]]
void initialize_python() {
#ifndef WIN32
    dlopen("libpython2.7.so", RTLD_NOW | RTLD_GLOBAL);
#endif
    Py_SetProgramName("python");
    Py_Initialize();
    pyrun("import matplotlib");
    pyrun("matplotlib.use('Qt4Agg')");
    pyrun("import matplotlib.pyplot as plt");
}

//[[Rcpp::export]]
void finalize_python() {
    Py_Finalize();
}

//Convert NumericVector to Python List
PyObject* numvec_to_list(NumericVector x){
    int n = x.length();
    PyObject *xpy = PyList_New(n);
    PyObject *f;
    
    for (int i=0; i<n; i++)
    {
      f = PyFloat_FromDouble(x[i]);
      //std::cout << i << "\n";
      PyList_SetItem(xpy, i, f);
    }   
    return(xpy);
}

//Push data to python __main__ namespace
//[[Rcpp::export]]
void numvec_to_python(std::string name, NumericVector x){
    PyObject *xpy = numvec_to_list(x);
    PyObject *m = PyImport_AddModule("__main__");
    PyObject *main = PyModule_GetDict(m);
    PyDict_SetItemString(main, name.c_str(), xpy);
}