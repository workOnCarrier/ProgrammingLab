#include <iostream>

#include "heapSort.h"

using namespace std;

void test_swap();
void test_valueat();
void test_heapSort () ;

int main () {
    // test_valueat();
	// test_swap();
	test_heapSort () ;
    return 0;
}

void test_valueat() {
    cout << " testing valueat functionality " << endl;
    int array[] = {2,5,6,3,8,7 };
	for ( auto val : array ) { cout << val << " " ; } cout << endl;
	cout << " value at " << 1 << ":" << valueat ( array, 1 ) << endl;;
	valueat ( array, 1 ) = 21 ;
	for ( auto val_ : array ) { cout << val_ << " " ; } cout << endl;
}

void test_swap() {
    cout << " testing heap_swap functionality " << endl;
    int array[] = {2,5,6,3,8,7 };
	for ( auto val : array ) { cout << val << " " ; } cout << endl;
	heap_swap ( array, 1, 6 );
	for ( auto val_ : array ) { cout << val_ << " " ; } cout << endl;
	heap_swap ( array, 2, 6 );
	for (auto val : array ) { cout << val << " " ; } cout << endl;
}

void test_heapSort () {
    cout << " testing heap_swap functionality " << endl;
    int array[] = {2,5,6,3,8,7 };
	for ( auto val : array ) { cout << val << " " ; } cout << endl;
	HeapSort ( array, sizeof ( array) / sizeof ( int ) );
	for ( auto val : array ) { cout << val << " " ; } cout << endl;
}

