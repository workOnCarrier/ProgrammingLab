#ifndef __PARALELQSORT_H__
#define __PARALELQSORT_H__

#include <thread>
#include <future>
#include <chrono>
#include "ThreadSafeStack.h"
#include <unistd.h>

#include <iostream>

namespace parallel_sort{
template <typename T>
class Sorter{

class chunkToSort; // forward declaration
public:
	Sorter () :// m_chunks(),  m_threads(),
		m_endOfData(false),
		//m_Max_Thread_Count(std::thread::hardware_concurrency()-1)
		m_Max_Thread_Count(1)
	{
	}
	~Sorter ()
	{
		m_endOfData = true;
		for ( unsigned i = 0; i < m_Max_Thread_Count; i++ )
		{
			m_threads[i].join();
		}
	}
	void try_sort_chunk ()
	{
		std::shared_ptr<chunkToSort>	chunk = m_chunks.pop();
		if ( chunk )
		{
			sort_chunk(chunk);
		}
	}
	std::list<T> do_sort( std::list<T> & chunk )
	{
		if ( chunk.empty()){
			return chunk;
		}
		std::cout << " start list display for Threadid : " << std::this_thread::get_id() << " list size" << chunk.size() << std::endl;
		std::unique_copy ( chunk.begin(), chunk.end(), std::ostream_iterator<T>(std::cout, " " ) );
		std::cout << "                 end list display for Threadid : " << std::this_thread::get_id() << std::endl;
		std::list<T> result;
		result.splice ( result.begin(), chunk, chunk.begin() );
		T const& partition_value = *result.begin();

		typename std::list<T>::iterator divide_point = std::partition (
							chunk.begin(), chunk.end(),
							[&](const T &val){ return val < partition_value; });

		chunkToSort	new_lower_chunk;
		new_lower_chunk.m_data.splice ( new_lower_chunk.m_data.end(),
							chunk, chunk.begin(), divide_point);

		std::future<std::list<T> > newLower = new_lower_chunk.m_promise->get_future();
		m_chunks.push ( std::move( new_lower_chunk ) );

		if ( m_threads.size() < m_Max_Thread_Count ){
			m_threads.push_back(std::thread(&Sorter<T>::sort_thread, this) );
		}
		std::list<T> new_higher ( do_sort ( chunk ) );
		result.splice ( result.end(), new_higher );
		while ( newLower.wait_for(std::chrono::seconds(0)) != std::future_status::ready )
		{
			try_sort_chunk();
		}
		result.splice ( result.begin(), newLower.get() );
		return result;
	}
	void sort_chunk ( std::shared_ptr<chunkToSort> & chunk )
	{
		chunk->m_promise->set_value(do_sort(chunk->m_data));
	}
	void sort_thread ()
	{
			while ( !m_endOfData ){
				try_sort_chunk();
				 std::this_thread::yield();
			}
	}
private:
	struct chunkToSort
	{
		std::list<T>	m_data;
		std::shared_ptr<std::promise<std::list<T>>>	m_promise;
		chunkToSort() :m_promise(new std::promise<std::list<T>>) {}
	};
	ThreadSafeStack<chunkToSort>	m_chunks;
	std::vector<std::thread>		m_threads;
	unsigned const 			m_Max_Thread_Count;
	std::atomic<bool>		m_endOfData;
};
}

template <typename T>
std::list<T>	parallel_quick_sort ( std::list<T> input )
{
	if ( input.empty() ){
		return input;
	}
	parallel_sort::Sorter<T>	sorter;
	return sorter.do_sort(input);
}
#endif // __PARALELQSORT_H__
