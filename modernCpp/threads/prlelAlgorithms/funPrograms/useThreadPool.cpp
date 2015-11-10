
#include "taskCreater.h"
#include "keyInputSource.h"
#include "textInterpreter.h"
#include "ITask.h"
#include "ThreadSafeStack.h"
#include <atomic>
#include <memory>
#include "JoinThreads.h"

class myThreadPool {

	std::atomic<bool>										m_done;
	ThreadSafeStack <Task> 									m_taskQueue;
	std::shared_ptr<TextInterpreter> 						m_textInterpret;
	TaskCreater <KeyInputSource,ThreadSafeStack<Task>,TextInterpreter >		m_taskCreation;
	std::vector<std::thread>								m_threads;
	JoinThreads<std::vector<std::thread>>					m_joiner;

	void workerThread () {
		while ( !m_done ){
			Task task;
			if ( m_taskQueue.try_pop ( task) ){
				task->execute();
			}else{
				std::this_thread::yield();
			}
		}
	}
public:
	myThreadPool ( int requestedCount = 0 ) 
		: m_done ( false), m_taskCreation( m_taskQueue, std::make_shared<TextInterpreter>()),
		m_joiner ( m_threads)
	{
		unsigned threadCount = std::thread::hardware_concurrency();	
		if ( requestedCount > 0 && requestedCount <= threadCount )
		{
			threadCount = requestedCount;
		}
		try{
			for ( unsigned counter = 0; counter < threadCount; counter++ ){
				m_threads.push_back( std::thread( &myThreadPool::workerThread, this ) );
			}
		}catch(...){
			m_done = true;
			return ;
		}
	}
	void start(){
		m_taskCreation.operator();
	}
};
int main ( int argc, char** argv )
{
	myThreadPool	threadPoolObj ( 2 );
	threadPoolObj.start();
	return 0;
}
