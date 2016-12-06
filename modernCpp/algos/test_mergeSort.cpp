#include <iostream>

#include "mergeSort.h"

using namespace std;

int main ( ) {
    int testArray [] = {5, 4, 6, 2, 3, 1};
	for ( int val : testArray ) { cout << val << " " ;} cout << endl;
	mergeSort ( testArray, 0, sizeof(testArray)/sizeof(int) -1 );
	for ( int val : testArray ) { cout << val << " " ;} cout << endl;
    return 0;
}
