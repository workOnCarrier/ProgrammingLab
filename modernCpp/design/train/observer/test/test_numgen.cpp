#include <thread>
#include <iostream>
#include "numgen.h"

#include "test_numgen.h"
using namespace std;

void testNumGen::processNumber ( int val) {
	cout << val  << " " ;
}

int main ( ) {
	testNumGen tng;
	tng();
	return 0;
}
