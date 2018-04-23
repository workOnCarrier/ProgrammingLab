#ifndef __COMMONUTILS_H__
#define __COMMONUTILS_H__

#include <memory>
#include <boost/asio.hpp>

typedef boost::asio::io_service AsioService;
typedef std::shared_ptr<AsioService> AsioServicePtr;

typedef boost::asio::io_service::work AsioWork;
typedef std::shared_ptr<AsioWork> AsioWrokPtr;

typedef boost::asio::io_service::strand AsioStrand;
typedef std::shared_ptr<AsioStrand> AsioStrandPtr;

typedef boost::system::error_code BoostEC;

typedef boost::asio::ip::tcp::socket AsioSocket;
typedef std::shared_ptr<AsioSocket> AsioSocketPtr;

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
	AsioWrokPtr		m_work;
	AsioStrandPtr	m_strand;
};

#endif //__COMMONUTILS_H__
