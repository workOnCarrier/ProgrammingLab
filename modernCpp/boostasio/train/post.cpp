/* post.cpp */
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <boost/bind.hpp>
#include <iostream>
#include <memory>

std::mutex global_stream_lock;

void WorkerThread(boost::shared_ptr<boost::asio::io_service> iosvc, int counter) {
      global_stream_lock.lock();
      std::cout << counter << ".\n";
      global_stream_lock.unlock();

    std::this_thread::sleep_for( std::chrono::milliseconds(2000));
      iosvc->run();

      global_stream_lock.lock();
      std::cout << "End.\n";
      global_stream_lock.unlock();
}

size_t fac(size_t n) {
    if ( n <= 1 ) {
        return n;
    }
    std::this_thread::sleep_for( std::chrono::milliseconds(1000));
    return n * fac(n - 1);
}

void CalculateFactorial(size_t n) {
    global_stream_lock.lock();
    std::cout << "Calculating " << n << "! factorial" << std::endl;
    global_stream_lock.unlock();

    size_t f = fac(n);

    global_stream_lock.lock();
    std::cout << n << "! = " << f << std::endl;
    global_stream_lock.unlock();
}

int main(void) {
    boost::shared_ptr<boost::asio::io_service> io_svc(
            new boost::asio::io_service
            );

    io_svc->post(boost::bind(CalculateFactorial, 5));
    io_svc->dispatch(boost::bind(CalculateFactorial, 6));
    io_svc->post(boost::bind(CalculateFactorial, 7));

    std::vector<std::shared_ptr<std::thread>> threads;
    for(int i=1; i<=5; i++) {
        threads.push_back ( std::make_shared<std::thread>(boost::bind(&WorkerThread, io_svc, i)) );
    }

    //std::this_thread::sleep_for( std::chrono::seconds(1));

    global_stream_lock.lock();
    std::cout << "The program will exit once all work has finished." << std::endl;
    global_stream_lock.unlock();

//    boost::shared_ptr<boost::asio::io_service::work> worker(
//            new boost::asio::io_service::work(*io_svc)
//            );
//
//    worker.reset();

    for ( auto thrd : threads ){ thrd->join(); }

    return 0;
}
