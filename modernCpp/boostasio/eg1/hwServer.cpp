#include <boost/asio.hpp>
#include <iostream>
#include "NetworkCommon.h"

using namespace boost;


int EndPoint (){
    /// assumed IP and port
    unsigned short  port  = NetworkCommon::port;

    // store for error messages
    boost::system::erro_code    errorObj;

    // accept connections from any IP address
    asio::ip::address   ip_address = asio::ip::address_v6::any ( );

    asio::ip::tcp::endpoint endPoing ( ip_address, port );
    return 0;
}

int function_socket(){
    asio::io_service    serviceObj;
    asio::ip::tcp::protocol tcpProtocol = asio::ip::tcp::v4();
    asio::ip::tcp::acceptor   tcpAcceptor (serviceObj);
    boost::system::erro_code    errorObj;

    tcpAcceptor.open ( tcpProtocol, errorObj );
    if ( errorObj.value() != 0 ){
        std::cout << "Error obtained while opening socket" << std::endl;
        std::cout << "errorObj.message" << errorObj.message() << "<-- Code -->" << errorObj.value() << std::endl;
        return errorObj.value();
    }
    return 0;
}

int function_socket_bind() {

    unsigned short  port  = NetworkCommon::port;
    asio::ip::tcp::endpoint tcpEndPoint = asio::ip::tcp::endpoint (
            asio::ip::address_v6::any ( ), port );

    asio::io_service        serviceObj;
    asio::ip::tcp::acceptor   tcpAcceptor (serviceObj, tcpEndPoint.protocol() );
    boost::system::erro_code    errorObj;
    
    tcpAcceptor.bind ( tcpEndPoint, errorObj );
    if ( errorObj.value() != 0 ){
        std::cout << "Error obtained while opening socket" << std::endl;
        std::cout << "errorObj.message" << errorObj.message() << "<-- Code -->" << errorObj.value() << std::endl;
        return errorObj.value();
    }
 }

int socket_listen_accept() {
    // size of queue containing pending connection requests
    const int BACKLOG_SIZE = 5;
    unsigned short portNo = NetworkCommon::portNo;
    asio::ip::tcp::endpoint     endpointObj ( asio::ip::tcp::address_v4::any(), portNo );
    asio::io_service            serviceObj;

    try{
        ios::ip::tcp::acceptor  acceptorObj ( ios, ep.protocol() );
        acceptorObj.bind(endpointObj);
        acceptorObj.listen(BACKLOG_SIZE);
        asio::ip::tcp::socket   socketObj (serviceObj);
        acceptor.accept(socketObj);
        // at this point server is ready to communicate with client
    }catch(system::system_error &e){
        cout << "Error occurred:" << e.code() << " ->" << e.what() << std::endl;
        return e.code().value();
    }
    return 0;
}
