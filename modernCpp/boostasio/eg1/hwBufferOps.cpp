#include <boost/asio.hpp>
#include <iostream>
#include <memory>

using namespace boost;

int function_OutPutBuffer (){
    std::string     data2Output;
    data2Output = "Hello";
    asio::const_buffer_1    outBufObj = asio::buffer(data2Output);

    return 0;
}

int function_InPutBuffer() {
    const BUFF_SIZE_BYTES = 200;
    std::unique_ptr<char[]> ipBuffer ( new char[BUFF_SIZE_BYTES]);
    asio::mutable_buffer_1 inputBufObj = asio::buffer( ipBuffer.get(), BUFF_SIZE_BYTES );

    return 0;
}

int function_extensibleStreamBuf () {
    asio::streambuf     streamBuffer;
    std::ostream        output (&streamBuffer);

    output << "Hello World \n Message from fist network on boost::asio program" ; 

    std::istream        intput  ( &streamBuffer );
    std::string         receivedBuffer;
    std::getline ( input, receivedBuffer );
    return 0;
}
