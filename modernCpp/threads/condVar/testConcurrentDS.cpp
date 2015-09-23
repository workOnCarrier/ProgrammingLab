
#include <iostream>
#include "concurrentDS.h"

int main (int argc, char** argv){
	ConcurrentQueue<std::string>  stringQueue;

	stringQueue.push ( "This should be fun" );
	stringQueue.push ( "This is looking like fun" );
	stringQueue.push ( "This is becoming fun" );
	stringQueue.push ( "This is fun" );
	stringQueue.push ( "I had a lot of fun" );

	std::cout << "No of elements" << stringQueue.size() << std::endl;

	for ( size_t i = 0; i < stringQueue.size(); ){
		std::shared_ptr<std::string> value = stringQueue.pop();
		std::cout <<  "element: " << *value << std::endl;
	}
	std::cout << "---> Testing multithreaded " << std::endl;

	//std::thread		thread1(
	return 0;
}
