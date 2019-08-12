

#include <pybind11/pybind11.h>

namespace py = pybind11;

class Pet {
public:
    Pet ( const std::string& name ) : m_name(name){}
    void setName ( const std::string& name_) { m_name = name_ ; }
    const std::string &getName () const { return m_name ; }
private:
    std::string m_name ;
};

PYBIND11_MODULE( classExample, m ) {
    py::class_<Pet>(m, "Pet" )
	    .def ( py::init<const std::string&>() )
	    .def_property( "name", &Pet::getName, &Pet::setName)
	    .def ( "setName", &Pet::setName, py::arg("newName") )
	    .def ( "getName", &Pet::getName)
	    .def ( "__repr__",
		     [](const Pet&a){
		         return "<classExample.Pet named '" + a.getName() + "'";
		     }
		 )
	    ;
}
