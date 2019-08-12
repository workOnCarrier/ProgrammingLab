
#include <pybind11/pybind11.h>

namespace py = pybind11;

int add ( int i, int j ){
    return i+j;
}

PYBIND11_MODULE(example1,m){
    m.doc()="pybind11 example1 plugin";
    m.def("add",&add, "A function to add two numbers",
		    py::arg("i"), py::arg("j") );
}
