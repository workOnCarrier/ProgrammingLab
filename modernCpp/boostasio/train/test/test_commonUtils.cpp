#include "commonUtils.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <boost/asio.hpp>

int main(){
	std::cout << "hello world" << std::endl;
	AsioServicePtr asioSerObj = std::make_shared<AsioService>();
	AsioWrokPtr		asioWorkObj = std::make_shared<AsioWork>(*asioSerObj); 

	std::vector<std::thread>	threadlist;
	AsioWorker 	worker(asioSerObj);
	for ( int i = 0; i < 1; i++ ) threadlist.push_back( std::thread(worker) );

	std::chrono::duration<int>  sleepTime(5);
	std::this_thread::sleep_for(sleepTime);

	asioWorkObj.reset();
	asioSerObj->stop();
	for ( auto &t : threadlist ) t.join();
	return 0;
}

