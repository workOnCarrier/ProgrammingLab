#ifndef __CONCURRENTDS_H__
#define __CONCURRENTDS_H__

#include <queue>
#include <mutex>
#include <condition_variable>
#include <boost/shared_ptr.hpp>

template <typename T, typename container = std::deque<T> >
class ConcurrentQueue {
public:
	explicit ConcurrentQueue(const container&){}
	explicit ConcurrentQueue(const container&& =container()){}

	ConcurrentQueue(const ConcurrentQueue& other) {
		std::lock_guard<std::mutex>	lock(other.m_mutex);
		m_queue = other.m_queue;
	}
	~ConcurrentQueue(){}

	//template <class Alloc> explicit ConcurrentQueue(const Alloc&);
	//ConcurrentQueue(const container&&){}
	template <class Alloc> ConcurrentQueue(container& contnr, const Alloc& allockater) : m_queue(contnr) { }
	template <class Alloc> ConcurrentQueue(container& contnr, Alloc&& allockater) : m_queue(contnr) { }
	ConcurrentQueue(ConcurrentQueue&& other) {
		std::unique_lock<std::mutex> lock1 ( m_mutex, std::defer_lock );
		std::unique_lock<std::mutex> lock2 ( other.m_mutex, std::defer_lock );
		std::lock(lock1,lock2);
		m_queue = std::move ( other.m_queue);
	}

	void 		swap ( ConcurrentQueue& queue ) {
		if (&queue == this )
			return;
		std::unique_lock<std::mutex> lock1(m_mutex,std::defer_lock);
		std::unique_lock<std::mutex> lock2(queue.m_mutex,std::defer_lock);
		std::lock(lock1,lock2);
		std::swap ( m_queue, queue.m_queue);
	}
	bool 		empty () const {
		std::lock_guard<std::mutex> lock(m_mutex);
		return m_queue.empty();
	}
	typename container::size_type	size()const{
		std::lock_guard<std::mutex> lock(m_mutex);
		return m_queue.size();
	}

//	T&	front (); const T&	front ()const;
//	T&	back (); const T&	back ()const;

	void push ( const T& tInstance ){
		std::lock_guard<std::mutex>	lock(m_mutex);
		m_queue.push_back ( tInstance );
		m_condVar.notify_one();
	}
	void push ( T&& tInstance){
		std::lock_guard<std::mutex>	lock(m_mutex);
		m_queue.push_back ( tInstance );
		m_condVar.notify_one();
	}

	std::shared_ptr<T>	pop ( ){
		std::shared_ptr<T>	valPtr (new T()) ;
		std::unique_lock<std::mutex>	lock(m_mutex);
		m_condVar.wait(lock, [&] { return !m_queue.empty(); } );
		*valPtr =  m_queue.front() ;
		m_queue.pop_front();
		return valPtr;
	}

	void pop ( T &value){
		std::shared_ptr<T>	valPtr = pop() ;
		value = *valPtr;
	}

	template < class... Args> void emplace ( Args&& ... args );
private:
	mutable std::mutex		m_mutex;
	container				m_queue;
	std::condition_variable	m_condVar;
};
#endif // __CONCURRENTDS_H__
