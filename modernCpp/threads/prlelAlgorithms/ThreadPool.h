
#ifndef __THEADPOOL_H__
#define __THEADPOOL_H__
#include "ThreadSafeStack.h"
#include "JoinThreads.h"
class ThreadPool
{
	std::atomic								m_done;
	ThreadSafeStack<std::function<void()>>	m_workQueue;
	std::vector<std::thread>				m_threads;
	JoinThreads<std::vector<std::thread>>	m_joiner;

	void workerThread() {
		while ( !m_done ) {
			std::function task;
			if ( m_workQueue.try_pop(task){
				task();
			}else {
				std::this_thread::yield();
			}
		}
	} // void workerThread()
public:
	ThreadPool() : m_done(false), m_joiner(m_threads) {
		unsigned const threadCount = std::thread::hardware_concurrency();
		try{
			for ( unsigned i=0; i < threadCount; i++ ){
				m_threads.push_back ( std::thread ( &ThreadPool::workerThread, this ) );
			}
		}catch(...){
			done = true;
			throw;
		}
	}
	~ThreadPool() {
		m_done = true;
	}
	template <typename FunctionType>
	void submit ( FunctionType f ){
		m_workQueue.push(std::function<void()> (f) );
	}
};
#endif // __THEADPOOL_H__
