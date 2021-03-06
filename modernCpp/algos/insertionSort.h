// insertion_sort ( A ) 
// for J = 2 to A.length
//   key = A[j]
//   // insert A[j] into sorted sequence A[1..j-1]
//   i = j -1
//   while  i > 0 and A[i] > key
//     A[i+1] = A[i]
//     i = i-1
//   A[i+1] = key

#ifndef __INSERTION_SORT_H__
#define __INSERTION_SORT_H__

#include <iostream>

using namespace std;

template <typename T>
bool order ( T left, T right, bool increasing ) {
    if  ( increasing == true ) {
	    return left > right;
	} else {
	    return left < right;
	}
}
template <typename T, typename C = T[]>
void insertion_sort ( C &input
                        , bool increasingOrder = true
						, int itemCount = sizeof(C)/sizeof(T)
						 ) {
	 cout << "itemCount:" << itemCount<< endl;
    for ( int j = 1; j < itemCount; j++ ) {
	    int i = j -1;
		T key = input [j];
		while ( i >= 0 && order ( input [i] , key, increasingOrder ) ) {
		    input [i+1] = input [i];
			i -= 1;
		}
		input [i+1] = key;
	}
};

#endif // __INSERTION_SORT_H__
