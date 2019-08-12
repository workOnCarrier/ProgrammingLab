

#include <pybind11/pybind11.h>

namespace py = pybind11;

class Pet {
public:
    Pet ( const std::string& name ) : m_name(name){}
    void setName ( const std::string& name_) { m_name = name_ ; }
    const std::string &getName () const { return m_name ; }
    virtual ~Pet(){}
private:
    std::string m_name ;
};

class Dog : public Pet {
public:
    Dog ( const std::string & name) : Pet(name) {}
    std::string bark() const { return "baw baw!"; }
};

PYBIND11_MODULE( inheritance, m ) {
    py::class_<Pet>(m, "Pet" )
	    .def ( py::init<const std::string&>() )
	    .def_property( "name", &Pet::getName, &Pet::setName)
	    .def ( "setName", &Pet::setName, py::arg("newName") )
	    .def ( "getName", &Pet::getName)
	    .def ( "__repr__",
		     [](const Pet&a){
		         return "<inheritance.Pet named '" + a.getName() + "'";
		     }
		 )
	    ;
    py::class_<Dog, Pet>(m,"Dog")
	    .def(py::init<const std::string& >() )
	    .def ( "bark", &Dog::bark);

    m.def("pet_store",[](){return std::unique_ptr<Pet>(new Dog("Molly"));});
}
