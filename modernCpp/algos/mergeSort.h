#include <iostream>
#include <limits>

using namespace std;
// merge sort
// merge

// merge ( A, p, q, r )
//   n1 = p -q + 1
//   n2 = r -	q
//   for i = 1 to n1
//     L[i] = A [p + i -1]
//   for j = 0 to n2
//     R[j] = A [q + j ]
//   L[n1+1]  = max_int
//   L[n2+1]  = max_int
//   i = 1
//   j = 1
//   for k = p to r
//     if L[i] < R[j]
//       A[k] = L[i]
//       i += 1
//     else
//       A[k] = L[j]
//       j += 1

void merge ( int *array, int start, int mid, int end ) {
    int n1 = mid - start + 1;
	int n2 = end - mid;
	int left[n1+1] ;
	int right[n2+1] ;
	int i ;
	int j ;
	for ( i = 0; i < n1; i ++) { left[i] = array [start + i] ; }
	for ( j = 0; j < n2; j ++) { right[j] = array [1+mid + j] ; }
	left[i] = numeric_limits<int>::max();
	right[j] = numeric_limits<int>::max();
//	for ( int l = 0; l < n1 ; l++ ) { cout << " " <<  left[l] ;} cout << " / " ;
//	for ( int m = 0 ; m < n2 ; m++ ) { cout << right[m] << " " ;} cout << endl;
	j = i = 0;
	for ( int k = start; k <= end; k++ ) {
	    cout << "   k:" << k << " i:" << i << " j:" << j << " left:" << left[i] << " right:" << right[j] << endl;
	    if ( left[i] < right[j] ) {
		    array[k] = left [i];
			i ++ ;
		} else {
		    array[k] = right [j];
			j ++ ;
		}
	}
}

// mergeSort ( A, p, r )
//   q = ( p + r ) / 2
//   mergeSort ( A, p, q )
//   mergeSort ( A, q+1, r )
//   merge ( A, p, q, r )

void mergeSort ( int *array , int start, int end ) {
    if ( start == end ) return ;
    int mid = ( start + end  ) / 2  ;
	mergeSort ( array, start, mid ) ;
	mergeSort ( array, mid + 1, end ) ;
	cout << " --- before merge:" ;
	for ( int l = start; l <= end ; l++ ) { cout << array[l] << " " ;} cout << endl;
	merge ( array, start, mid, end ) ;
	cout << " --- after merge:" ;
	for ( int l = start; l <= end ; l++ ) { cout << array[l] << " " ;} cout << endl;
}

