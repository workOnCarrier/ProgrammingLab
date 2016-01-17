#ifndef __CONCURRENTDS_H__
#define __CONCURRENTDS_H__

#include <queue>
#include <mutex>
#include <condition_variable>
#include <boost/shared_ptr.hpp>

namespace AccGrind{
    template <typename T, typename container = std::deque<T> >
    class ThreadSafeStack {
    public:
        explicit ThreadSafeStack(const container&){}
        explicit ThreadSafeStack(const container&& =container()){}

        ThreadSafeStack(const ThreadSafeStack& other) {
            std::lock_guard<std::mutex>    lock(other.m_mutex);
            m_queue = other.m_queue;
        }
        ~ThreadSafeStack(){}

        //template <class Alloc> explicit ThreadSafeStack(const Alloc&);
        //ThreadSafeStack(const container&&){}
        template <class Alloc> ThreadSafeStack(container& contnr, const Alloc& allockater) : m_queue(contnr) { }
        template <class Alloc> ThreadSafeStack(container& contnr, Alloc&& allockater) : m_queue(contnr) { }
        ThreadSafeStack(ThreadSafeStack&& other) {
            std::unique_lock<std::mutex> lock1 ( m_mutex, std::defer_lock );
            std::unique_lock<std::mutex> lock2 ( other.m_mutex, std::defer_lock );
            std::lock(lock1,lock2);
            m_queue = std::move ( other.m_queue);
        }

        void         swap ( ThreadSafeStack& queue ) {
            if (&queue == this )
                return;
            std::unique_lock<std::mutex> lock1(m_mutex,std::defer_lock);
            std::unique_lock<std::mutex> lock2(queue.m_mutex,std::defer_lock);
            std::lock(lock1,lock2);
            std::swap ( m_queue, queue.m_queue);
        }
        bool         empty () const {
            std::lock_guard<std::mutex> lock(m_mutex);
            return m_queue.empty();
        }
        typename container::size_type    size()const{
            std::lock_guard<std::mutex> lock(m_mutex);
            return m_queue.size();
        }

    //    T&    front (); const T&    front ()const;
    //    T&    back (); const T&    back ()const;

        //void push ( const T& tInstance ){
        //    std::lock_guard<std::mutex>    lock(m_mutex);
        //    m_queue.push_back ( tInstance );
        //    m_condVar.notify_one();
        //}
        void push ( T&& tInstance){
            std::lock_guard<std::mutex>    lock(m_mutex);
            m_queue.push_back ( tInstance );
            m_condVar.notify_one();
        }
        void push ( T &tInstance){
            std::lock_guard<std::mutex>    lock(m_mutex);
            m_queue.push_back ( tInstance );
            m_condVar.notify_one();
        }
        T    pop ( ){
            std::unique_lock<std::mutex>    lock(m_mutex);
            m_condVar.wait(lock, [&] { return !m_queue.empty(); } );
            T    valPtr = m_queue.back();
            m_queue.pop_back();
            return valPtr;
        }

        void pop ( T &value ) {
            std::unique_lock<std::mutex>    lock(m_mutex);
            value = m_queue.back();
            m_queue.pop_back();
        }
        bool try_pop( T&value ) {
            std::unique_lock<std::mutex>    lock(m_mutex);
            if ( m_queue.empty() ) {
                return false;
            }
            value = m_queue.back();
            m_queue.pop_back();
            return true;
        }

        template < class... Args> void emplace ( Args&& ... args );
    private:
        mutable std::mutex        m_mutex;
        container                 m_queue;
        std::condition_variable   m_condVar;
    };
}
#endif // __CONCURRENTDS_H__
