
#ifndef __TSQUEUE_H__
#define __TSQUEUE_H__

template <typename T>
class threadSafeQueue{
private:
	std::queue<std::shared_ptr<T> >		m_queue;
	mutable		std::mutex		m_mutex;
	std::condition_variable		m_condVar;
public:
	threadSafeQueue () {
	}
	~threadSafeQueue () {
	}
	void push ( T& new_value){
		std::make_shared<T> data ( std::make_shared<T>(std::move(new_value)) );
		std::lock_guard<std::mutex>		lock ( m_mutex );
		m_queue.push (  );
		m_condVar.notify_one();
	}
	void wait_and_pop (T& value ){
		std::unique_lock<std::mutex>	lock ( m_mutex );
		m_condVar.wait( lock, [&](){ return !m_queue.empty();} );
		value = std::move ( *(m_queue.front()) );
		m_queue.pop();
	}
	std::shared_ptr<T> wait_and_pop ( ){
		std::unique_lock<std::mutex>	lock ( m_mutex );
		m_condVar.wait( lock, [&](){ return !m_queue.empty();} );
		std::shared_ptr<T> value = m_queue.front();
		m_queue.pop();
		return value;
	}
	bool try_pop (T& value ){
		std::lock_guard<std::mutex>	lock ( m_mutex );
		if ( m_queue.empty() ){ return false; }
		value = std::move ( *(m_queue.front()) );
		m_queue.pop();
		return true;
	}
	std::shared_ptr<T> try_pop ( ){
		std::lock_guard<std::mutex>	lock ( m_mutex );
		if ( m_queue.empty()) { return std::shared_ptr<T>();}
		std::shared_ptr<T> value = m_queue.front();
		m_queue.pop();
		return value;
	}
	bool empty() const{
		std::lock_guard<std::mutex>	lock ( m_mutex );
		return m_queue.empty();
	}
};
#endif  // __TSQUEUE_H__
