#include "productLine.h"
#include <iostream>

namespace modernCpp{

	Interface::Interface() {
	    std::cout << "Interface constructor" << std::endl;
	}
	Interface::~Interface() {
	    std::cout << "Interface destructor" << std::endl;
	}

	firstChild::firstChild() {
	    std::cout << "firstChild constructor" << std::endl;
	}
	firstChild::~firstChild() {
	    std::cout << "firstChild destructor" << std::endl;
	}

	secondChild::secondChild() {
	    std::cout << "secondChild constructor" << std::endl;
	}
	secondChild::~secondChild() {
	    std::cout << "secondChild destructor" << std::endl;
	}

}
