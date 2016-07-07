#include <iostream>


#include <boost/asio.hpp>
#include <thread>
#include <memory>
#include "lockedcout.h"

// namespace basio = boost::asio;

// void workerThread ( basio::io_service &ioserv , int counter){
// }

Lcout lcout(std::cout);
int main ( int argc, char** argv ){
    // try using the Lcout class
    lcout << "Hello World" << '\n' ;
    return 0;
}
