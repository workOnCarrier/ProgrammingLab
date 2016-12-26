#include <iostream>

using namespace std;

class A {
public:
	void fun() { cout << "in function fun of class A" << endl;}
private:
};

int main () {
    auto a = &A::fun;
	cout << decltype ( a ) << endl;
	// A::*funPtr
    // void (A::*funPtr)() = &A::fun;
	A  aObj;
	aObj.fun();

	cout << " using the function call via a pointer " << endl;
	// (aObj.*funPtr)(); 
	(aObj.*a)();
    return 0;
}
