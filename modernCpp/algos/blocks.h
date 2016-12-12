

#ifndef __BLOCKS_H__
#define __BLOCKS_H__

#ifdef DEBUG
#include <iostream>
#endif //DEBUG

template <typename T, typename C = T[]>
void inPlaceSwap ( C &array,const  int findex, const  int secIndex ){
#ifdef DEBUG
    std::cout << " findex:" << findex << " secIndex:" << secIndex << endl;
#endif // DEBUG
    if ( findex == secIndex ) return;
    T val = array[findex];
	array [findex] = array[secIndex];
	array[secIndex] = val; 
}

#endif // __BLOCKS_H__

