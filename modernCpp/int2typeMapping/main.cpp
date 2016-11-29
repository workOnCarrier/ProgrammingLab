
#include <iostream>
#include "productFactory.h"
using namespace std;
bool isValidInput ( int input )
{
    if ( input < 0 || input > 2 ) return false;
	return true;
}
int getUserInput () 
{
    int input = 0;
	while ( !isValidInput( input ) ){
		cout << "Choices avaiable" << endl;
		cout << "0 --> Exit" << endl;
		cout << "1 --> attempt first object" << endl;
		cout << "2 --> attempt second object" << endl;
	    cout << " Please enter the choice: "  ;
		cin >> input;
	}
	return input;
}
int main ( ) {
    int input = 0;
	input = getUserInput () ;

    modernCpp::productFactory   myFactoryObj;
	int specializeWith ;
	if ( input == 1 ) specializeWith = modernCpp::first;
	else specializeWith = modernCpp::second;
	//int2type<specializeWith> valueType;

	modernCpp::Interface *objPtr = myFactoryObj.create ( int2type<specializeWith> valueType );
	delete (objPtr );

    return 0;
}
