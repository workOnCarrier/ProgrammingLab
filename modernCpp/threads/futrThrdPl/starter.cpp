
#include <iostream>
#include <thread>
#include "concurrentDS.h"
#include "workScheduler.h"

using namespace std;

void testInputProcessing (ConcurrentQueue<std::string> &stringQueue){
    std::cout << "No of elements" << stringQueue.size() << std::endl;

	for ( size_t i = 0; i < stringQueue.size(); ){
		std::shared_ptr<std::string> value = stringQueue.pop();
		std::cout <<  "element: " << *value << std::endl;
	}
}
int main ( int argc, char** argv){

	ConcurrentQueue<std::string> stringQueue;

	{
	WorkScheduler<ConcurrentQueue<std::string>, std::string >		workScheduler(stringQueue);
	workScheduler.startScheduleing();
	}

	return 0;
}
