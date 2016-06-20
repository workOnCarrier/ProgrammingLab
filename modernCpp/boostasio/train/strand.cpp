/* nonstrand.cpp */
#include <boost/asio.hpp>
#include <memory>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <boost/bind.hpp>
#include <iostream>

std::mutex global_stream_lock;

void WorkerThread(std::shared_ptr<boost::asio::io_service> iosvc, int counter) {
    global_stream_lock.lock();
    std::cout << "Thread " << counter << " Start.\n";
    global_stream_lock.unlock();

    iosvc->run();

    global_stream_lock.lock();
    std::cout << "Thread " << counter << " End.\n";
    global_stream_lock.unlock();
}

void Print(int number) {
    std::cout << "Number: " << number << std::endl;
}

int main(void) {
    std::shared_ptr<boost::asio::io_service> io_svc(
                                            std::make_shared<boost::asio::io_service>( ));

    std::shared_ptr<boost::asio::io_service::work> worker(
                                            std::make_shared<boost::asio::io_service::work>(*io_svc));
    boost::asio::io_service::strand strandObj ( *io_svc );

    global_stream_lock.lock();
    std::cout << "The program will exit once all work has finished.\n";
    global_stream_lock.unlock();

    std::vector<std::shared_ptr<std::thread>> threads;
    for(int i=1; i<=5; i++) {
        threads.push_back(std::make_shared<std::thread>(&WorkerThread, io_svc, i) );
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    strandObj.post(boost::bind(&Print, 1));
    strandObj.post(boost::bind(&Print, 2));
    strandObj.post(boost::bind(&Print, 3));
    strandObj.post(boost::bind(&Print, 4));
    strandObj.post(boost::bind(&Print, 5));

    worker.reset();

    for ( auto thrd : threads ){
        thrd->join();
    }

    return 0;
}
