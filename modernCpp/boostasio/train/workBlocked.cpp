
#include <boost/asio.hpp>

#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

using namespace std;
using namespace boost;
using namespace boost::asio;

int main ( int argc, char** argv ){
    
    io_service ioservObj;
    std::shared_ptr<io_service::work> worker = std::make_shared<io_service::work> ( ioservObj );
    thread      threadObj ( [&]()->void{ 
                this_thread::sleep_for ( chrono::seconds(4) );
                worker.reset();
            } );
    cout << "      waiting for work to be done" << endl;
    ioservObj.run();
    cout << "This indicates the worker has been reset" << endl;
    threadObj.join();
    return 0;
}
