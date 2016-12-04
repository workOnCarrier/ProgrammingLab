#include <iostream>

#include "insertionSort.h"


using namespace std;

void test_build_setup () { cout << "Hellow world" << endl; }

void test1 () ;
int main () {
    // test_build_setup ();
	test1 () ;
	return 0;
}

void test1 () {
    int testArray [] = {5,2,4,6,1,3};
	for ( auto val : testArray ) {
	    cout << val << " " ;
	} cout << endl;
	insertion_sort <int>( testArray, false );
	for ( auto val : testArray ) {
	    cout << val << " " ;
	} cout << endl;
	insertion_sort <int>( testArray );
	for ( auto val : testArray ) {
	    cout << val << " " ;
	} cout << endl;

}

