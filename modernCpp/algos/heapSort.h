
#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__

inline int Parent ( int index )  { return index /  2 ; }
inline int Left ( int index )  { return index *  2 ; }
inline int Right ( int index )  { return (index*2 + 1 ) ; }
inline int& valueat (int* array, int index ) { return array[index-1]; }


void	HeapSort ( int* array, int size );
void	MaxHeapify ( int* array, int arraySize,  int index );
void	BuildMaxHeap (int* array, int arraySize );

void MaxHeapInsert ( );
int HeapExtractMax ( int *array, int size );
void HeapIncreaseKey ( );
int HeapMax ( int *array  ) { return valueat ( array, 1 );}

void heap_swap ( int* array, int lIndex, int rIndex ) {
    int temp = valueat(array, lIndex);
	valueat(array, lIndex ) = valueat(array, rIndex);
	valueat(array, rIndex) = temp;
}
void MaxHeapify ( int* array, int arraySize ,  int index ) {
    int L = Left ( index );
    int R = Right ( index );
	int lIndex = index;
	// if ( L < m_size && m_array[L] > m_array[index] ) {}
	if ( L < arraySize && valueat (array,L) > valueat(array,index) ) {
	    lIndex = L ;
	}
	if ( R < arraySize && valueat(array, R) > valueat(array, lIndex) ) {
	    lIndex = R ;
	}  // else handled with L index else loop
	if ( lIndex != index ) {
	    heap_swap ( array , lIndex, index );
		MaxHeapify ( array, arraySize, lIndex );
	}
}
void BuildMaxHeap (int* array, int size ) {
    int half = size/2;
	for ( ; half > 0; half-- ) {
	    MaxHeapify(array, size, half);
	}
}
void HeapSort(int* array, int size) {
    BuildMaxHeap ( array, size);
	for ( int j = size; j > 1; j-- ) {
	    heap_swap ( array, j, 1 );
		MaxHeapify ( array, j, 1 );
	}
}

int HeapExtractMax ( int *array, int size ){
    int max = valueat ( array, 1 );
	heap_swap ( array, 1, size );
	MaxHeapify ( array, size - 1, 1 );
	return max;
}

void HeapIncreaseKey ( int* array, int size, int index, int value) {
    if ( index > size ) { // this is error condition
	}
	valueat ( array, index ) = value;
	while ( index > 1 &&  valueat ( array, index ) > valueat(array, Parent ( index ))  ) {
	    heap_swap ( array, index, Parent ( index ) );
		index = Parent ( index );
	}
}
#endif // __HEAPSORT_H__

