#include "commonUtils.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <boost/asio.hpp>


int test_basicAsioWroker(){
	std::cout << "hello world" << std::endl;
	AsioServicePtr asioSerObj = std::make_shared<AsioService>();
	AsioWrokPtr		asioWorkObj = std::make_shared<AsioWork>(*asioSerObj); 

	std::vector<std::thread>	threadlist;
	AsioWorker 	worker(asioSerObj);
	for ( int i = 0; i < 1; i++ ) threadlist.push_back( std::thread(worker) );

	std::chrono::duration<int>  sleepTime(3);

	asioSerObj->post([](){std::cout << "done sample work"<< std::endl;});
	std::this_thread::sleep_for(sleepTime);
	asioSerObj->post([](){std::cout << "done sample work_2"<< std::endl;});
	std::this_thread::sleep_for(sleepTime);

	asioSerObj->stop();
	for ( auto &t : threadlist ) t.join();
	asioWorkObj.reset();
	return 0;
}
int test_AsioServiceBP(){
	std::vector<std::thread>	threadlist;
	{
	AsioServiceBP  asioBpObj;
	AsioWorker 	worker(asioBpObj.getServicePtr());
	for ( int i = 0; i < 1; i++ ) threadlist.push_back( std::thread(worker) );
	asioBpObj.getServicePtr()->post([](){std::cout << "done sample work"<< std::endl;});

	std::chrono::duration<int>  sleepTime(3);
	std::this_thread::sleep_for(sleepTime);

	asioBpObj.getServicePtr()->post([](){std::cout << "done sample work_2"<< std::endl;});
	asioBpObj.stopService();
	}
	for ( auto &t : threadlist ) t.join();
	std::cout << "after destruction of asioBpObj" << std::endl;
}
int main(){
	// test_basicAsioWroker();
	test_AsioServiceBP();
	return 0;
}

