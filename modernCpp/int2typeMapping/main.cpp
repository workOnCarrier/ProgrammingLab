
#include "productFactory.h"

int main ( ) {
    modernCpp::productFactory   myFactoryObj;
	
	int2type<modernCpp::first> value4first;
	modernCpp::Interface *objPtr = myFactoryObj.create ( value4first );
	delete (objPtr );

	int2type<modernCpp::second> value4second;
	objPtr = myFactoryObj.create ( value4second );
	delete (objPtr );
    return 0;
}
