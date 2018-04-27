#ifndef __COMMONUTILS_H__
#define __COMMONUTILS_H__

#include <memory>
#include <vector>
#include <list>
#include <boost/asio.hpp>

typedef boost::asio::io_service AsioService;
typedef std::shared_ptr<AsioService> AsioServicePtr;

typedef boost::asio::io_service::work AsioWork;
typedef std::shared_ptr<AsioWork> AsioWorkPtr;

typedef boost::asio::io_service::strand AsioStrand;
typedef std::shared_ptr<AsioStrand> AsioStrandPtr;

typedef boost::system::error_code BoostEC;

typedef boost::asio::ip::tcp::socket AsioSocket;
typedef std::shared_ptr<AsioSocket> AsioSocketPtr;

typedef boost::asio::ip::tcp::acceptor AsioAcceptor;
typedef std::shared_ptr<AsioAcceptor> AsioAcceptorPtr;

typedef boost::asio::ip::tcp::resolver AsioResolver;
typedef std::shared_ptr<AsioResolver> AsioResolverPtr;

typedef boost::asio::ip::tcp::resolver::query AsioQuery;
typedef std::shared_ptr<AsioQuery> AsioQueryPtr;

class AsioWorker {
public:
	AsioWorker ( AsioServicePtr );
	~AsioWorker ( );

	void operator()();
private:
	AsioServicePtr	m_service;
	AsioWork		m_workObj;
};

// boiler place service object creation and work object creation
class AsioServiceBP{
public:
	AsioServiceBP ();
	~AsioServiceBP ();
	AsioServicePtr	getServicePtr();
	void 			stopService();
private:
	AsioServicePtr	m_service;
	AsioWorkPtr		m_work;
	AsioStrandPtr	m_strand;
};


class IClientContext: public std::shared_from_this {
public:
		IclientContext(AsioServicePtr svcPtr);
		void recv();
		void send(const void* buffer, size_t length);
		void close();
protected:
		void OnSend( BoostEC& ec, std::list<std::vector<boost::uint8_t>>::iterator it );
		void OnRecv(BoostEC& ec, size_t length);
		// void registerDataListener ( std::functional<(void)(std::vector<boost::uint8_t>)>);
private:

	AsioSocketPtr		m_socket;
	std::vector<size_t>	m_recvBuffer;
	std::list<std::vector<size_t>>	m_sendBuffer;
	size_t				m_bufferPosition;
};

#endif //__COMMONUTILS_H__
