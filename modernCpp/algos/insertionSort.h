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

template <typename T, typename C = T[]>
void insertion_sort ( C &input
                        , int itemCount = sizeof(C)/sizeof(T) 
						, bool increasingOrder = true ) {
    for ( int j = 1; j < itemCount; j++ ) {
	    int i = j -1;
		T key = input [j];
		while ( i >= 0 && input [i] > key ) {
		    input [i+1] = input [i];
			i -= 1;
		}
		input [i+1] = key;
	}
};

#endif // __INSERTION_SORT_H__
