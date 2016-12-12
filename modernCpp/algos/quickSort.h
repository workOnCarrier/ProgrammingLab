#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include <iostream>
using namespace std;
#include "blocks.h"
template <typename T,  typename C = T[]>
int partition ( C &array, const int startIndex, const int endIndex ) {
    T pivotVal = array [endIndex];
	int i = startIndex -1;
	int newPivot = startIndex;
	bool isSameValue = true;
	for ( auto val : array ) { cout << " " << val; }cout << endl;
	for ( int j = startIndex; j < endIndex ; j ++ ) {
	    if ( array [j] !=  pivotVal ) {
			isSameValue  = false;
		} else { continue; }
	    if ( array [j] < pivotVal ) {
		    i = i +1 ;
			inPlaceSwap<T> ( array, i, j );
		}
	}
	if ( isSameValue  )  {
	    newPivot  = (startIndex + endIndex) / 2;
	}else {
	    newPivot = i + 1;
	}
	inPlaceSwap<T> ( array, newPivot, endIndex );
	return newPivot;
}
/*
template <typename T,  bool order = false, typename C = T[]>
int partition ( C &array, const int startIndex, const int endIndex ) {
    T pivotVal = array [startIndex];
	int i = endIndex + 1;
	int newPivot = endIndex;
	bool isSameValue = true;
	for ( auto val : array ) { cout << " " << val; }cout << endl;
	for ( int j = startIndex; j < endIndex ; j ++ ) {
	    if ( array [j] !=  pivotVal ) {
			isSameValue  = false;
		} else { continue; }
	    if ( array [j] > pivotVal ) {
		    i = i -1 ;
			inPlaceSwap<T> ( array, i, j );
		}
	}
	if ( isSameValue  )  {
	    newPivot  = (startIndex + endIndex) / 2;
	}else {
	    newPivot = i - 1;
	}
	inPlaceSwap<T> ( array, newPivot, endIndex );
	return newPivot;
}*/
template <typename T, typename C=T[]>
void QuickSort ( C &array, const int startIndex, const int endIndex , bool increasingOrder = true ) {
    if ( startIndex < endIndex ) {
		int pivot = partition<T> ( array, startIndex, endIndex );
		cout << "start:" << startIndex << " pivot:" << pivot << " end:" << endIndex << endl;
		QuickSort<T> ( array, startIndex, pivot -1 , increasingOrder);
		QuickSort<T> ( array, pivot +1, endIndex , increasingOrder);
	}
}
#endif  //  __QUICKSORT_H__
