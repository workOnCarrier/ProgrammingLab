
#include "productFactory.h"
#include "productLine.h"


namespace modernCpp{
    productFactory::productFactory (){}
	productFactory::~productFactory (){}

	Interface* productFactory::create ( int2type<first> )
	{
	    return new firstChild();
	}
	Interface* productFactory::create ( int2type<second> )
	{
	    return new secondChild();
	}
}
