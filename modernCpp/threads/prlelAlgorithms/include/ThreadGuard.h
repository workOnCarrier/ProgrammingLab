
#ifndef __THREADGUARD_H__
#define __THREADGUARD_H__

#include <thread.h>

class ThreadGuard {
public:
	ThreadGuard ( std::thread& threadSrc ): m_guardedThread ( threadSrc ){
	}
	~ThreadGuard () {
		if ( m_guardedThread.joinable() ) m_guardedThread.join();
	}
private:
	thread m_guardedThread;
	ThreadGuard( const ThreadGuard & ) = delete;
	ThreadGuard& operator = ( const ThreadGuard & ) = delete;
};
#endif // __THREADGUARD_H__
