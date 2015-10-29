
#include <iostream>
#include <list>
#include <iterator>
#include "PrlelQSrt.h"

using namespace std;

int main ( int argc, char** argv )
{
	list<int>  unsortedList;
	unsortedList.push_back(21);
	unsortedList.push_back(19);
	unsortedList.push_back(17);
	unsortedList.push_back(16);
	unsortedList.push_back(15);
	unsortedList.push_back(14);
	unsortedList.push_back(13);
	unsortedList.push_back(12);
	unsortedList.push_back(11);
	unsortedList.push_back(10);
	unsortedList.push_back(31);
	unsortedList.push_back(41);
	unsortedList.push_back(51);
	unsortedList.push_back(7);
	unsortedList.push_back(6);
	unsortedList.push_back(4);
	unsortedList.push_back(2);

	list<int> sortedList = parallel_quick_sort ( unsortedList );

	unique_copy ( sortedList.begin(), sortedList.end(),
				ostream_iterator<int>(cout, " " ) );
	return 0;
}
