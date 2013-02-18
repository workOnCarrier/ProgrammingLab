#ifndef __WORKQUEUE_H__
#define __WORKQUEUE_H__
#include <iostream>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <typeinfo>
#include <vector>
#include <list>
#include "workItem.h"
#include "trace.h"
#include "error.h"
using namespace std;
typedef boost::mutex::scoped_lock    scoped_lock;

template<class T >
class workQueue {

	static int 					count;
	list<T>						workList;
	boost::mutex				lock;
	boost::condition_variable	done;
	boost::condition_variable	go;
	long						path_max;
	long						name_max;


	// copy constructor
	workQueue ( const workQueue & );
	// assignment operator
	workQueue<T>& operator = ( const workQueue<T> & );
public:
    workQueue ( std::string );
    ~workQueue ( );

    void		addWork ( T & );
	T	        getWork ( );
	bool		isWorkInQueue ();
	void		waitForAllWorkFinish ();
	long		getPathMax() { return path_max; }
	long		getNameMax() { return name_max; }
	void		signalMoreWork () { go.notify_one() ; }
};

template<typename T>
int workQueue<T>::count = 0;

template<typename T>
workQueue<T>::workQueue ( std::string filepath)
{
	count=count+1;
	trace::getTrace()->Info() << "ccccc " << count ;
	trace::getTrace()->Info() << "filepath:" << filepath.c_str() ;
#ifndef WIN32
	path_max = pathconf ( filepath.c_str(), _PC_PATH_MAX );
	if ( path_max == -1 )
	{
	    DPRINTF ( ("filepath max size -1") );
		fflush (stdout);
	    if ( errno == 0 ) path_max = 1024;
		else errno_abort ( "Unable to get PATH_MAX" );
	}
	path_max++;
	errno = 0;
	name_max = pathconf ( filepath.c_str(), _PC_NAME_MAX );
	if ( name_max == -1 )
	{
	    DPRINTF ( ("filename max size -1") );
		fflush (stdout);
	    if ( errno == 0 ) name_max = 1024;
		else errno_abort ( "Unable to get NAME_MAX" );
	}
#else
	path_max = 1024;
	name_max = 128;
#endif
	name_max ++;
}

template<typename T>
workQueue<T>::~workQueue ()
{
}

template<typename T>
void	workQueue<T>::addWork ( T& newWork )
{
	{
//		scoped_lock condLock (lock);
		//boost::unique_lock<boost::mutex> condLock ((lock) );
		workList.push_back(newWork); //.insert( newWork );
		// signalMoreWork called by the client
	}
	trace::getTrace()->Info() << "items in list : " << workList.size() ;
}
template<typename T>
T	workQueue<T>::getWork ( )
{
	T	work_item(*this);
	while ( 1 )
	{
		{
//			scoped_lock condLock (lock);
			//boost::unique_lock<boost::mutex> condLock ((lock) );
//			while ( workList.empty() )
//			{
//				go.wait ( condLock );
//			}
			work_item = workList.front();
			workList.pop_front();
			trace::getTrace()->Info() << workList.size() << " items in list after getting: " << work_item.display() ;
			break;
		}
	}
	return work_item;
}

template <typename T>
bool		workQueue<T>::isWorkInQueue ()
{
		//lock.lock();
//	scoped_lock condLock (lock);
			
		bool isEmpty = !workList.empty();
		return isEmpty;
}

template <typename T>
void		workQueue<T>::waitForAllWorkFinish ()
{
	//boost::unique_lock<boost::mutex> condLock ((lock) );
//	scoped_lock condLock (lock);
    while ( !workList.empty () )
	{
//		done.wait( condLock );
	}
}

template <typename T>
workQueue<T>::workQueue ( const workQueue & ){ throw custom::runtime_error("Invalid function call");}

template <typename T>
workQueue<T>& workQueue<T>::operator = ( const workQueue<T>& )
{
	throw custom::runtime_error("Invalid function call");
	return *this;
}


#endif //__WORKQUEUE_H__

