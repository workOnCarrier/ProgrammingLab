#include <iostream>
#include <cstdio>
#include "keyInputSource.h"

int main ( int argc, char** argv )
{
	keyInputSource	processInput;

	std::cout << "starting to read:" << std::endl;
	keyInputSource::DataType dataObj = "";
	while ( processInput.hasMoreData() )
	{
		dataObj = "";
		dataObj = processInput.getNextDataItem();
		std::cout << "dataObject:" <<  dataObj << std::endl;
	}
	return 0;
}
