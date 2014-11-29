#include "myNew.h"
#include "objectCreater.h"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "myAlgo.h"

legacy* createMyNew()
{
    auto obj = create (  "sample with myNew" , Type2Type<myNew>() );
	return obj;
}
legacy* createLegacy()
{
	std::string sample = "sample with legacy";
    auto obj = create ( sample, Type2Type<legacy>() );
	return obj;
}
int main ( int argc, char** argv )
{
    // simple approach to see if the code works in the fist case or not
	{
	    auto newObj = boost::shared_ptr<legacy>(createMyNew());
		newObj = boost::shared_ptr<legacy>(createLegacy());
	}
	std::cout << " " << std::endl;

	//real example
	{
	    myAlgo<myNew> algo ("myNew with Algo");
    	algo.fire();
	}

	{
		myAlgo<legacy> algoLegacy("legacy with Algo");
		//algoLegacy.fire();
	}

    return 0;
}
