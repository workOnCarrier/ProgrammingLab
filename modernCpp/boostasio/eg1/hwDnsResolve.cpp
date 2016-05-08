#include <boost/asio.hpp>
#include <iostream>
#include "NetworkCommon.h"

using namespace boost;

// For more information on DNS and domain names, refer to the specification of the system that can be found in the RFC #1034 and RFC #1035 documents
int DnsResolve (){
    // domain name and port comming from NetworkCommon.h
    asio::io_service serviceObj;
    asio::ip::tcp::resolver::query dnsResolver ( NetworkCommon::domain,
            NetworkCommon::port,
            asio::ip::tcp::resolver::query::numeric_service );
    asio::ip::tcp::resolver  resolverObj;
    boost::system::error_code   errorObj;

    asio::ip::tcp::resolver::iterator  resolverIter = resolverObj.resolve ( dnsResolver, errorObj );

    if (  errorObj.value() != 0 ){
        std::cout << "Error obtained while opening socket" << std::endl;
        std::cout << "errorObj.message" << errorObj.message() << "<-- Code -->" << errorObj.value() << std::endl;
        return errorObj.value();
    }
    asio::ip::tcp::resolver::iterator it_end;

    for (; it != it_end; ++it) {
        // Here we can access the endpoint like this.
        asio::ip::tcp::endpoint ep = it->endpoint();
    }
    return 0;
}
