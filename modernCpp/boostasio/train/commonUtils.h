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

class AsioWorker {
public:
	AsioWorker ( AsioServicePtr );
	~AsioWorker ( );

	void operator()();
private:
	AsioServicePtr	m_service;
	AsioWork		m_workObj;
};
#endif //__COMMONUTILS_H__
