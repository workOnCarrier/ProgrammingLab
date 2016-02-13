
#include "scopedThread.h"

namespace nitin_learning
{
    explicit scopedThread::scopedThread ( std::thread t ): m_t(t) {
	    if ( !t.joinable())
		    throw std::logic_error("no thread for owning");
	}
	scopedThread::~scopedThread() {
	    t.join();
	}
}
