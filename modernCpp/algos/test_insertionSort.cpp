#include <iostream>
#include <vector>

#include "insertionSort.h"


using namespace std;

void test_build_setup () { cout << "Hellow world" << endl; }

void test1 () ;
void test2 () ;
int main () {
    // test_build_setup ();
	test1 () ;
	test2 () ;
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
void test2 () {
    vector<int> testArray  = {5,2,4,6,1,3};
	for ( auto val : testArray ) {
	    cout << val << " " ;
	} cout << endl;
	// insertion_sort <int>( testArray, false , testArray.size() );
	insertion_sort <int>( testArray, false ,testArray.size() );
	for ( auto val : testArray ) {
	    cout << val << " " ;
	} cout << endl;
	cout << "Sizeof vector:" << sizeof(testArray) << " sizeof int:" << sizeof(int) << endl;
	insertion_sort <int,vector<int>>( testArray ,true ,testArray.size());
	for ( auto val : testArray ) {
	    cout << val << " " ;
	} cout << endl;
	insertion_sort <int>( testArray ,false ,testArray.size());
	for ( auto val : testArray ) {
	    cout << val << " " ;
	} cout << endl;

}



