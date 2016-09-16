#include <iostream>
#include <boost/asio.hpp>

#include <boost/date_time/posix_time/posix_time.hpp>

int main()
{
    boost::asio::io_service io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
    std::cout << "Starting to wait" << std::endl;

    t.wait();
    std::cout << "Hello, world! 5 seconds have elapsed " << std::endl;

    return 0;
}
