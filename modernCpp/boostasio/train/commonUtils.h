#ifndef __COMMONUTILS_H__
#define __COMMONUTILS_H__

#include <memory>
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

#endif //__COMMONUTILS_H__
