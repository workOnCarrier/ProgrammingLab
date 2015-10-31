#ifndef __JOINTHREADS_H__
#define __JOINTHREADS_H__

#include <thread.h>

template <typename Container = std::vector<std::thread> >
class JoinThreads{
	Container	&m_containerRef;
public:
	JoinThreads( Container& containerRef ) : m_containerRef(containerRef){
	}
	~JoinThreads ( ){
		for ( unsigned current = 0; current < m_containerRef.size(); current ++ ){
			if ( m_containerRef[current].joinable() ) {
				m_containerRef[current].join();
			}
		}
	}
};

#endif // __JOINTHREADS_H__

