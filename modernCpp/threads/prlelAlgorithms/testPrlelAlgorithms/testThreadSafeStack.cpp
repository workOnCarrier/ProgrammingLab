

#include "ThreadSafeStack.h"
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace std;

void testValueBasedStack() ;
void testPointerBasedStack();
int main ( int argc, char** argv )
{
	std::cout << "Testing value based stack" << std::endl;
	testValueBasedStack() ;

	std::cout << std::endl;
	std::cout << "Testing pointer based stack" << std::endl;
	testPointerBasedStack();
	return 0;
}
void testValueBasedStack() {
	ThreadSafeStack<int> intStack;
	vector<int>			 intVect;
	intVect.push_back(2);
	intVect.push_back(3);
	intVect.push_back(4);
	intVect.push_back(5);
    intVect.push_back(6);
	for ( auto val : intVect )
	{
		intStack.push ( val );
	}
	while ( ! intStack.empty() )
	{
		int newVal;
		intStack.pop(newVal);
		std::cout <<  newVal << " ";
	}
	std::cout << std::endl;
	std::unique_copy ( intVect.begin(), intVect.end(),
					std::ostream_iterator<int>(std::cout," " ) );
}
void testPointerBasedStack(){
	ThreadSafeStack<boost::shared_ptr<int>> intStack;
	vector<int>			 intVect;
	//std::unique_copy ( istream_iterator<int>(cin),
	//				istream_iterator<int>(),
	//				back_inserter(intVect) );
	intVect.push_back(2);
	intVect.push_back(3);
	intVect.push_back(4);
	intVect.push_back(5);
	intVect.push_back(6);
	for ( auto val : intVect )
	{
		intStack.push ( boost::make_shared<int>(val)  );
	}
	while ( ! intStack.empty() )
	{
		//int newVal;
		//intStack.pop(newVal);
		//std::cout <<  newVal << " ";
		std::cout << *(intStack.pop().get() ) << " ";
	}
	std::cout << std::endl;
	std::unique_copy ( intVect.begin(), intVect.end(),
					std::ostream_iterator<int>(std::cout," " ) );
}
