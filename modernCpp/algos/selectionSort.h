#ifndef __SELECTIONSORT_H__
#define __SELECTIONSORT_H__
template <typename T, typename C = T[]>
int find_max ( C& container, int startIndex, int maxIndexVal ) {
    int itm = startIndex;
	while ( startIndex <= maxIndexVal ) {
	    if ( container[startIndex] > container[itm] ) {
		    itm = startIndex;
		}
		startIndex ++ ;
	}
	return itm;
}
template <typename T, typename C = T[]>
int find_min ( C& container, int startIndex, int maxIndexVal ) {
    int itm = startIndex;
	while ( startIndex <= maxIndexVal ) {
	    if ( container[startIndex] < container[itm] ) {
		    itm = startIndex;
		}
		startIndex ++ ;
	}
	return itm;
}
template <typename T, typename C = T[]>
void selection_sort ( C &container
						, int size = sizeof(C) /  sizeof(int)
						, bool increasing = true ) {
    int itm = 0;
	for ( int itr = 0; itr < size-1; itr++ ) {
	    if ( true == increasing ) {
		    itm = find_min<T> ( container, itr, size-1 );
		} else {
		    itm = find_max<T> ( container, itr, size-1 );
		}
		// swap items at itm, itr
		if ( itm != itr ) {
		    T  val = container[itr];
			container[itr] = container[itm] ; 
			container[itm] = val ; 
		}
	}
}
#endif // __SELECTIONSORT_H__
