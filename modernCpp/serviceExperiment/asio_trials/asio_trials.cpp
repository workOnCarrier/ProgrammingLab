// asio_trials.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "testing_asio.h"
#include <thread>
#include <iostream>
#include "boost/bind.hpp"

int main()
{
	// test_asioStrand();
	test_asioStrandWrap() ;
    return 0;
}
typedef boost::asio::io_service IOService;
typedef std::shared_ptr<IOService>	IOServicePtr;
typedef boost::asio::io_service::work IOServiceWork;
typedef std::shared_ptr<IOServiceWork>	IOServiceWorkPtr;
std::chrono::duration<int, std::ratio<1, 1>> sleeptime(3);

class IOServiceWorker {
	std::mutex*  m_lockable;
public:
	IOServiceWorker (std::mutex* mtx):m_lockable(mtx){}
	void operator()(IOServicePtr iosPtr, size_t id_display, std::string msg="") {
		{
			std::lock_guard<std::mutex> lg(*m_lockable);
			std::cout << "starting running :" << id_display << "for " << msg << "\n";
		}
		while (true) {
			try {
				boost::system::error_code		ec;
				iosPtr->run(ec);
				if (ec) {
					// log info
					std::lock_guard<std::mutex> lg(*m_lockable);
					std::cout << " Error Message:" << ec << "\n";
				}
				break;
			}
			catch (std::exception &ex){
					std::lock_guard<std::mutex> lg(*m_lockable);
					std::cout << " Exception Message:" << ex.what() << "\n";
			}
		}
		std::lock_guard<std::mutex> lg(*m_lockable);
		std::cout << " thread finished:" << id_display << "\n";
	}
};
void myPrint(int number) {
	std::cout << "Number is:" << number << std::endl;
}
void test_asioStrand() {
	std::mutex lockable;
	IOServicePtr iosp = std::make_shared<IOService>();
	IOServiceWorkPtr iosWorkp = std::make_shared<IOServiceWork>(*iosp);
	IOService::strand iosStrand (*iosp);
	{std::lock_guard<std::mutex> locking(lockable);
	std::cout << "program exits once all work isfinished" << std::endl;
	}

	std::vector<std::thread> threadList;
	IOServiceWorker IOServiceWorkerObj(&lockable);
	for (int i = 0; i < 5; i++)
		threadList.push_back(std::thread(IOServiceWorkerObj, iosp, i));

	std::this_thread::sleep_for(sleeptime);
	for (int i = 10; i < 15; i++)
		// iosp->post(boost::bind(&myPrint, i)); 
		iosStrand.post(boost::bind(&myPrint, i)); 

	iosWorkp.reset ();

	for (auto& t : threadList) t.join();

}
void test_asioStrandWrap() {
	std::mutex lockable;
	IOServicePtr iosp = std::make_shared<IOService>();
	IOServiceWorkPtr iosWorkp = std::make_shared<IOServiceWork>(*iosp);
	IOService::strand iosStrand (*iosp);
	{std::lock_guard<std::mutex> locking(lockable);
	std::cout << "program exits once all work isfinished" << std::endl;
	}

	std::vector<std::thread> threadList;
	IOServiceWorker IOServiceWorkerObj(&lockable);
	for (int i = 0; i < 5; i++)
		threadList.push_back(std::thread(IOServiceWorkerObj, iosp, i));

	std::this_thread::sleep_for(sleeptime);
	for (int i = 10; i < 15; i++)
		iosp->post(iosStrand.wrap(boost::bind(&myPrint, i))); 
		// iosStrand.post(boost::bind(&myPrint, i)); 

	iosWorkp.reset ();

	for (auto& t : threadList) {
		if (t.joinable())
			t.join();
		else
			continue;
	}

}
