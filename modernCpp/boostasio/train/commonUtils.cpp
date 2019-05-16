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

IClientContext::IClientContext(AsioServicePtr svcPtr)
	:m_socket(std::make_shared<AsioSocket>(*svcPtr)),m_bufferPosition(0) {
	m_recvBuffer.resize(4096);
}

void IClientContext::close(){
	BoostEC ec;
	m_socket->shutdown(AsioSocket::shutdown_both,ec);
#pragma message "Todo : handle error cases"
	m_socket->close(ec);
#pragma message "Todo : handle error cases"
}

void IClientContext::OnSend( BoostEC& ec, std::list<std::vector<boost::uint8_t>>::iterator it ){
	if ( ec ){
		std::cout << "error in OnSend:" << ec  << std::endl;
		close();
	}else{
		std::cout << "send data : " << (*it).size() << " bytes" << std::endl;
	}
	m_sendBuffer.erase(it);
	if ( !m_sendBuffer.empty() ){
	}
}

void IClientContext::OnRecv(BoostEC& ec, size_t length){};
void IClientContext::recv(){
	
}
void IClientContext::send(const void* buffer, size_t length){};
	
