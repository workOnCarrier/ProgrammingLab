/* mutexbind.cpp */
#include <boost/asio.hpp>
#include <memory>
#include <thread>
#include <mutex>
#include <vector>
#include <boost/bind.hpp>
#include <iostream>

std::mutex global_stream_lock;

void WorkerThread(boost::shared_ptr<boost::asio::io_service> iosvc, int counter) {
    global_stream_lock.lock();
    std::cout << counter << ".\n";
    global_stream_lock.unlock();
    
    iosvc->run();
    
    global_stream_lock.lock();
    std::cout << "End.\n";
    global_stream_lock.unlock();
}

int main(void) {
    boost::shared_ptr<boost::asio::io_service> io_svc(
            new boost::asio::io_service
            );
    
    boost::shared_ptr<boost::asio::io_service::work> worker(
            new boost::asio::io_service::work(*io_svc)
            );
    
    std::cout << "Press ENTER key to exit!" << std::endl;
    
    std::vector<std::shared_ptr<std::thread>> threads;
    for(int i=1; i<=5; i++) {
        threads.push_back(std::make_shared<std::thread>(&WorkerThread, io_svc, i));
    }
    
    std::cin.get();
    
    io_svc->stop();
    
    for ( auto thrd : threads ){
        thrd->join();
    }
    
    return 0;
}
