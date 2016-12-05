#include <iostream>
#include "selectionSort.h"

using namespace std;

int main ( ) {
    int testArray[] = {5,6,1,2,4,3,7};
	for ( int val : testArray ) { cout << " " << val ; } cout << endl;
	selection_sort<int> ( testArray );
	for ( int val : testArray ) { cout << " " << val ; }cout << endl;
	selection_sort<int> ( testArray , sizeof(testArray)/sizeof(int), false);
	for ( int val : testArray ) { cout << " " << val ; }cout << endl;
	selection_sort<int> ( testArray, 3 );
	for ( int val : testArray ) { cout << " " << val ; }cout << endl;
    return 0;
}
