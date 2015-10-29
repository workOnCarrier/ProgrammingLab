
#ifdef __SCOPED_THREAD_Ha__
#define __SCOPED_THREAD_Ha__
namespace nitin_learning
{
    class scopedThread
    {
        std::thread m_t;
    public:
        explicit scopedThread ( std::thread t ): m_t(t) {
    	    if ( !t.joinable())
    		    throw std::logic_error("no thread for owning");
    	}
    	~scopedThread() {
    	    t.join();
    	}
    	scopedThread (scopedThread const&)=delete;
    	scopedThread& operator=(scopedThread const&)=delete;
    };
}
#endif //__SCOPED_THREAD_Ha__
