#ifndef __PRODUCTFACTORY_H__
#define __PRODUCTFACTORY_H__

#include "int2type.h"
#include "productLine.h"

namespace modernCpp{
    class productFactory{
	public:
	    productFactory ();
	    ~productFactory ();

		Interface* create ( int2type<first> );
		Interface* create ( int2type<second> );
	};
}

#endif // __PRODUCTFACTORY_H__
