#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <boost/bind.hpp>

#include "commonUtils.h"


void OnConnect ( const BoostEC & ec ){
	if ( ec ){
		std::cout << "OnConnect error:" << ec << std::endl;
	}else{
		std::cout << " connection successful " << std::endl;
	}
}

void run_client(){
	std::vector<std::thread>  threadList;
	{
		AsioServiceBP	asioBpObj;
		AsioWorker 		worker(asioBpObj.getServicePtr());
		for ( int i = 0; i < 3; i ++ ) threadList.push_back(std::thread(worker));

		std::chrono::duration<int>  sleepTime(3);
		std::this_thread::sleep_for(sleepTime);

		auto svc = asioBpObj.getServicePtr();
		AsioSocketPtr socktptr = std::make_shared<AsioSocket>(*svc);


		try{
			boost::asio::ip::tcp::resolver resolverObj (* svc);
			

			boost::asio::ip::tcp::resolver::query  querry ( "www.pactpub.com","80");
			auto resolveItr = resolverObj.resolve(querry);
			auto endPoint = *resolveItr;

			socktptr -> async_connect ( endPoint, boost::bind(OnConnect,_1));
		}catch(std::exception &ec){
			std::cout << "Exception caught:" << ec.what()<< std::endl;
		}
		std::cin.get();
		BoostEC ec;

		socktptr->shutdown ( boost::asio::ip::tcp::socket::shutdown_both,ec);
		socktptr->close(ec);
		svc->stop();

	}
	for ( auto &t : threadList ) t.join();
	std::cout << "after destruction of asioBpObj" << std::endl;
}

int main ( int argc, char** argv){
	std::cout << "hello world" << std::endl;
	run_client();
}
