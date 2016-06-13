/* dispatch.cpp */
#include <boost/asio.hpp>
#include <memory>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <boost/bind.hpp>
#include <iostream>

std::mutex global_stream_lock;

void WorkerThread(std::shared_ptr<boost::asio::io_service> iosvc) {
    global_stream_lock.lock();
    std::cout << "Thread Start.\n";
    global_stream_lock.unlock();

    iosvc->run();

    global_stream_lock.lock();
    std::cout << "Thread Finish.\n";
    global_stream_lock.unlock();
}

void Dispatch(int i) {
    global_stream_lock.lock();
    std::cout << "dispath() Function for i = " << i <<  std::endl;
    global_stream_lock.unlock();
}

void Post(int i) {
    global_stream_lock.lock();
    std::cout << "post() Function for i = " << i <<  std::endl;
    global_stream_lock.unlock();
}

void Running(std::shared_ptr<boost::asio::io_service> iosvc) {
    for( int x = 0; x < 5; ++x ) {
        iosvc->dispatch(boost::bind(&Dispatch, x));
        iosvc->post(boost::bind(&Post, x));
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main(void) {
    std::shared_ptr<boost::asio::io_service> io_svc(
            new boost::asio::io_service
            );

    std::shared_ptr<boost::asio::io_service::work> worker(
            new boost::asio::io_service::work(*io_svc)
            );

    global_stream_lock.lock();
    std::cout << "The program will exit automatically once all work has finished." << std::endl;
    global_stream_lock.unlock();

    std::vector<std::shared_ptr<std::thread>> threads;

    threads.push_back ( std::make_shared<std::thread>(boost::bind(&WorkerThread, io_svc)) );
    // adding another thread -- will process post also
    // threads.push_back ( std::make_shared<std::thread>(boost::bind(&WorkerThread, io_svc)) );

    io_svc->post(boost::bind(&Running, io_svc));

    worker.reset();
    for ( auto thrd : threads ) {
        thrd->join(); 
    }
    return 0;
}
