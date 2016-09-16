#include <iostream>


#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <thread>
#include <memory>
#include "lockedcout.h"

namespace basio = boost::asio;
void workerThread ( boost::shared_ptr<basio::io_service> ioserv , int counter){
    {
    Lcout       g_lcout ( std::cout );
    g_lcout << "Thread:" << counter ;
    }
    try {
        Lcout       g_lcout ( std::cout );
        ioserv->run();
        g_lcout << "in thread:" << counter ;
    }catch (std::exception &ex){
        Lcout       g_lcout ( std::cout );
        g_lcout << "Message:" << ex.what() ;
    }
}
void ThrowAnException ( boost::shared_ptr<basio::io_service> iosvc, int counter ){
    Lcout       g_lcout ( std::cout );
    g_lcout << "throwing exception for thread:" << counter ;
    throw (std::runtime_error("Intended exception for testing" ) );
}

int main ( int argc, char** argv ){
    boost::shared_ptr<basio::io_service> io_serv ( new basio::io_service);
    boost::shared_ptr<basio::io_service::work> worker(
            new basio::io_service::work(*io_serv)
            );
    // try using the Lcout class
    { Lcout lcout(std::cout);
        lcout << "program will exit once all work finishes" ;
    }
    boost::thread_group threads;
    for ( int i = 1; i <= 3; i++ ){
        threads.create_thread(boost::bind(&workerThread,io_serv,i) ); 
    }
    for ( int i = 1; i <= 5; i++ ){
        io_serv->post ( boost::bind (&ThrowAnException, io_serv, i) );
    }
    threads.join_all();
    return 0;
}
