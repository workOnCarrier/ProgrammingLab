
#include <iostream>
#include "commonUtils.h"

#include <vector>
#include <thread>
#include <memory>
#include <boost/bind.hpp>

void OnAccept ( const BoostEC &ec, AsioServicePtr svcPtr, AsioAcceptorPtr acceptorPtr){
	if ( ec ) {
		std::cout << " error in On Accept " << ec << std::endl;
	}else{
		std::cout << " normal in On Accept " << std::endl;
	}
	AsioSocketPtr 	socktPtr = std::make_shared<AsioSocket>(*svcPtr);
	acceptorPtr->async_accept(*socktPtr,boost::bind(OnAccept,_1,svcPtr, acceptorPtr));
}


void run_server(){
	std::vector<std::thread> threadList;
	{
		AsioServiceBP asioBpObj;
		auto svcPtr = asioBpObj.getServicePtr();
		AsioWorker    worker(svcPtr);
		for ( int i = 0; i < 3; i ++ )
			threadList.push_back(std::thread( worker ));

		AsioAcceptorPtr acceptorPtr = std::make_shared<AsioAcceptor>(*svcPtr);
		AsioSocketPtr 	socktPtr = std::make_shared<AsioSocket>(*svcPtr);
		AsioResolverPtr	resolverPtr = std::make_shared<AsioResolver>(*svcPtr);
		AsioQueryPtr	queryPtr = std::make_shared<AsioQuery>("127.0.0.1","4444");

		auto resolvItr = resolverPtr->resolve(*queryPtr);
		boost::asio::ip::tcp::endpoint endPoint = *resolvItr;

		acceptorPtr->open(endPoint.protocol());
		acceptorPtr->set_option(AsioAcceptor::reuse_address(false));
		acceptorPtr->bind(endPoint);
		acceptorPtr->listen(boost::asio::socket_base::max_connections);

		// acceptorPtr->async_accept(*socktPtr,boost::bind(OnAccept,_1,socktPtr, acceptorPtr));
		acceptorPtr->async_accept(*socktPtr,
						[&](const BoostEC& ec){OnAccept(ec,svcPtr, acceptorPtr);}
						);
		std::cin.get();
		BoostEC ec;
		acceptorPtr->close(ec);

		socktPtr->shutdown(AsioSocket::shutdown_both,	ec);
		socktPtr->close();
		svcPtr->stop();
	}

	for ( auto &t: threadList) t.join();
}

int main ( int argc, char** argv ){
	std::cout << " hello world " << std::endl;
	run_server();
	return 0;
}
