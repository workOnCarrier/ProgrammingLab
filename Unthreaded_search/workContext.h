#ifndef __WORKCONTEXT_H__
#define __WORKCONTEXT_H__

template <typename T>
class workContext
{
public:
    workContext();
    ~workContext();

	// public interface 
	void submitMoreWork ( IworkItem & );
private:
    typename workQueue<T> m_queue;

	workQueue<T> getWorkQueueRef ( );
};
#endif // __WORKCONTEXT_H__

