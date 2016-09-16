#include <boost/asio.hpp>
#include <iostream>
#include "NetworkCommon.h"

using namespace boost;


int EndPoint (){
    /// assumed IP and port
    std::string     rawIP = NetworkCommon::rawIp;
    unsigned short  port  = NetworkCommon::port;

    // store for error messages
    boost::system::erro_code    errorObj;

    asio::ip::address   ip_address = asio::ip::address::from_string ( rawIP, errorObj );

    if ( errorObj.value() != 0 ){
        std::cout << "Error obtained while connectiong" << std::endl;
        std::cout << "errorObj.message" << errorObj.message() << "<-- Code -->" << errorObj.value() << std::endl;
        return errorObj.value();
    }
    asio::ip::tcp::endpoint endPoing ( ip_address, port );
    return 0;
}


int function_socket(){
    asio::io_service    serviceObj;
    asio::ip::tcp::protocol tcpProtocol = asio::ip::tcp::v4();
    asio::ip::tcp::socket   tcpSocket (serviceObj);
    boost::system::erro_code    errorObj;

    tcpSocket.open ( tcpProtocol, errorObj );
    if ( errorObj.value() != 0 ){
        std::cout << "Error obtained while opening socket" << std::endl;
        std::cout << "errorObj.message" << errorObj.message() << "<-- Code -->" << errorObj.value() << std::endl;
        return errorObj.value();
    }
    return 0;
}

int ConnectWithEndPoint () {
    try{
        // service object for OS dependent functionality
        asio::io_service    serviceObj;

        // form the end point
        std::string     rawIP = NetworkCommon::rawIp;
        unsigned short  port  = NetworkCommon::port;

        // ip address from string can throw exception
        asio::ip::tcp::endpoint endPoint (asio::ip::address::from_string ( rawIP) , port );
        asio::io::tcp::socket   socketObj ( serviceObj, endPoint.protocol() );
        // connect can throw an exception
        socketObj.connect ( endPoint );
    }catch (system::system_error &e ){
        std::cout << "Exception thrown : " << e.what() << std::endl;
    }
    return 0;
}

int ConnectEndPoint4DomainName() {
    std::string     domain  = NetworkCommon::domain;
    std::string     port    = NetworkCommon::port;
    asio::io_service    serviceObj;
    boost::system::erro_code    errorObj;

    asio::ip::tcp::resolver::query dsnSolver ( NetworkCommon::domain, NetworkCommon::port,
            ios::ip::tcp::resolver::query::numeric_service );

    asio::ip::tcp::resolver     resolverObj;
    try{
        asio::ip::tcp::resolver::iterator   resolvItr = resolverObj.resolve ( dsnSolver );
        asio::ip::tcp::socket   socketObj (ios);
        asio::connect ( socketObj, resolvItr );
    } catch ( system::system_error &e ){
        std::cout << " Exception while connecting :" << e.what() << std::endl;
        return e.code();
    }
 
    return 0;
}

void writeToSocket_withWriteSome (asio::ip::tcp::socket &socketObj ){
    std::string     bufferObj = "Hello World \n boost asio based networking software";
    std::size       totalWritten = 0;

    while ( totalWritten != bufferObj.length() ){
        totalWritten = socketObj.write_some ( bufferObj.c_str()+totalWritten,
                                        bufferObj.length()-totalWritten );
    }
}
// alternatives exist to write_some
// 1_ send ()-- overloaded to 3 forms
// 2_ write () -- also has an overload
int function_WriteToSocket_user(){
    std::string raw_ip  = NetworkCommon::rawIP;
    unsigned portNo     = NetworkCommon::port ;
    asio::io_service    serviceObj;
    try{
        asio::ip::tcp::endpoint  endPointObj ( asio::ip::address::from_strin(raw_ip), portNo );
        asio::ip::tcp::socket   socketObj ( serviceObj, endPointObj.protocol() );
        socketObj.connect ( endPointObj );
        writeToSocket_withWriteSome ( socketObj );
    }catch(system::system_error &err){
        cout << "Error occurred! " << err.what() << std::endl;
        return err.code().value();
    }
    return 0;
}
