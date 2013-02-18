#ifndef __FILEWORKITEM_H__
#define __FILEWORKITEM_H__

#include "workItem.h"
#include "workQueue.h"

using std::string;

class work
{
public:
	virtual void doWork()=0;
};

class fileWorkItem :public IworkItem{
	std::string				m_path;
	std::string				m_search;
	workQueue<fileWorkItem> &m_queue;
	auto_ptr<work>			m_work;
public:
	fileWorkItem ( workQueue<fileWorkItem> &workContext, std::string path, std::string search );
	fileWorkItem ( workQueue<fileWorkItem> &workContext );
	fileWorkItem ( const fileWorkItem &);
	virtual ~fileWorkItem () { }

	fileWorkItem& operator = ( const fileWorkItem& ) ;
    const std::string&		getPath () { return m_path; }
	const std::string&		getSearchStr () { return m_search; }
	virtual void 			doWork();
	virtual void 			InitWork();
	virtual void 			cleanupWork ();
	virtual string 			display () {return m_path;}
};

class fileWork : public work
{
public:
	fileWork (std::string path, std::string search );
	virtual void doWork();
private:
	std::string				m_path;
	std::string				m_search;
};
class dirWork : public work
{
public:
	dirWork(workQueue<fileWorkItem> &, std::string path, std::string search);
	virtual void doWork();
private:
	std::string				m_path;
	std::string				m_search;
	workQueue<fileWorkItem> &m_queue;
};

#endif // __FILEWORKITEM_H__

