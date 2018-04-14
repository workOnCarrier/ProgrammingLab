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

AsioServiceBP::AsioServiceBP ()
:m_service(std::make_shared<AsioService>())
,m_work(std::make_shared<AsioWork>(*m_service))
,m_strand(std::make_shared<AsioStrand>(*m_service))  {}

AsioServiceBP::~AsioServiceBP (){
    if ( !m_service->stopped() ) m_service->stop();
	m_work.reset();
	m_strand.reset();
	m_service.reset();
}
AsioServicePtr	AsioServiceBP::getServicePtr(){
	return m_service;
}
void AsioServiceBP::stopService(){
    m_service->stop();
}
