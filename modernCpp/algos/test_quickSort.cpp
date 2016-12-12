#include <iostream>

#include "quickSort.h"


int main () {
    int array[] = {13,19,9,5,12,8};
	for ( auto val : array ) { cout << " " << val; }cout << endl;
	QuickSort<int> ( array, 0, (sizeof(array)/sizeof(int)) - 1 );
	for ( auto val : array ) { cout << " " << val; }cout << endl;

//    int array_[] = {3,19,9,5,2,8};
//	for ( auto val : array_ ) { cout << " " << val; }cout << endl;
//	QuickSort<int> ( array_, 0, (sizeof(array_)/sizeof(int)) - 1, false );
//	for ( auto val : array_ ) { cout << " " << val; }cout << endl;

//    int array_1[] = {3,3,3,3,3,3};
//	for ( auto val : array_1 ) { cout << " " << val; }cout << endl;
//	QuickSort<int> ( array_1, 0, (sizeof(array_1)/sizeof(int)) - 1 );
//	for ( auto val : array_1 ) { cout << " " << val; }cout << endl;
     return 0;
}


