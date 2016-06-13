
#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost;
using namespace boost::asio;

int main ( int argc, char** argv){
    io_service   ioservObj;

    for ( int counter = 0 ; counter < 5 ; counter++ ) {
        ioservObj.poll();
        cout << "line: " << counter << endl;
    }
    return 0;
}
