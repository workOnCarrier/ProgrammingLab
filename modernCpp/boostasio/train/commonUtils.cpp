#include "commonUtils.h"
#include <exception>
#include <iostream>

AsioWorker::AsioWorker ( AsioServicePtr asioPtr)
		:m_service(asioPtr), m_workObj(*asioPtr){}

AsioWorker::~AsioWorker ( ){}

void AsioWorker::operator()(){
	while(true){
		try{
			boost::system::error_code ec;
			m_service->run(ec);
			if ( ec) {
				std::cout << "context error" << std::endl;
			}
			break;
		}catch(std::exception& e){
			std::cout << "exception observed: " << std::endl;
		}
	}
}

