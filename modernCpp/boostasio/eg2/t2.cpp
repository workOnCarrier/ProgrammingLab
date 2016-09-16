
#include <iostream>
#include <boost/asio.hpp>

#include <boost/date_time/posix_time/posix_time.hpp>


void async_handler  ( const boost::system::error_code /*e*/ ) {
    std::cout << "Hello, world! 5 seconds have elapsed " << std::endl;
}

int main()
{
    boost::asio::io_service io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
    std::cout << "Starting to wait" << std::endl;

    auto lambda_async_handler = [] ( const boost::system::error_code /*e*/ ) ->void {
        std::cout << "Hello, world! 5 seconds have elapsed " << std::endl;
    };
    //t.async_wait ( &async_handler );
    t.async_wait ( lambda_async_handler );
    io.run();
    return 0;
}
