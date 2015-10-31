
#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "ThreadSafeStack.h"
#include "JoinThreads.h"

#include <memory>
#include <vector>
#include <future>

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

class FunctionWrapper{
	struct ImplBase {
		virtual void call() = 0;
		virtual ~ImplBase () {}
	};
	std::unique_ptr<ImplBase>			m_ImplPtr;
	template <typename F>
	struct ImplType : public ImplBase {
		F	m_functionToCall;
		ImplType (F&& f) : m_functionToCall(std::move(f)) {}
		void call () { m_functionToCall(); }
	};
public:
	template <typename TaskFunction>
	FunctionWrapper( TaskFunction&& tf)
			: m_ImplPtr ( new ImplType<TaskFunction>(std::move(tf)) ) { }
	void operator () (){
		m_ImplPtr.call();
	}
	FunctionWrapper () = default; // what does this mean and why is it like so

	FunctionWrapper ( FunctionWrapper && other ) : m_ImplPtr ( std::move(other.m_ImplPtr) ) {}
	FunctionWrapper & operator = ( FunctionWrapper && other ) {
		m_ImplPtr ( std::move(other.m_ImplPtr) ); 
		return *this;
	}
	FunctionWrapper ( const FunctionWrapper & ) = delete;
	FunctionWrapper ( FunctionWrapper & ) = delete;
	FunctionWrapper & operator = ( FunctionWrapper & ) = delete;

};

class TaskWaitableThreadPool {
public:
	TaskWaitableThreadPool () : m_done(false),m_joiner(m_threads){
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
	~TaskWaitableThreadPool () {
		m_done = true;
	}
	template <typename FunctionType> submit ( FunctionType & f ) -> 
	std::future< typename std::result_of<FunctionType()>::type > 
	{
		typedef std::future< typename std::result_of<FunctionType()>::type >  ResultType;
		std::packaged_task<ResultType()> 		task ( std::move (f) );
		std::future<ResultType>					result( task.get_future() );
		m_workQueue.push ( std::move(task) );
		return result;
	}
private:
	workerThread() {
		while (!done){
			FunctionWrapper		wrapperObj;
			if ( m_workQueue.try_pop(wrapperObj) ) {
				wrapperObj();
			}else{
				std::this_thread.yield();
			}
		}
	}
	std::atomic								m_done;
	ThreadSafeStack<FunctionWrapper>		m_workQueue;
	std::vector<std::thread>				m_threads;
	JoinThreads<std::vector<std::thread>>	m_joiner;
};
#endif // __THREADPOOL_H__
