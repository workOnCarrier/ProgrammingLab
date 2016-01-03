#ifndef __LINEARQSORT_H__
#define __LINEARQSORT_H__

#include <iostream>

using namespace std;
template <typename t>
list<T> linearQSort ( list<T> inputList ){
	if ( inputList.empty() ){
		return inputList;
	}
	list<T>	result;
	result.splice ( result.begin(), input, input.begin() );
	std::unique_copy ( result.begin(), result.end(), std::ostream_iterator<T>(std::cout, " " ) );
	T const& pivot = result.begin();

	auto divide_point = partition ( input.begin(), input.end(), [&](T const &t){ return t < pivot;} );
	list lower_part;
}
#endif // __LINEARQSORT_H__
