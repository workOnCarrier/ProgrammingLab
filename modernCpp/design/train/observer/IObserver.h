#ifndef __IOBSERVER_H__
#define __IOBSERVER_H__

#include <memory>

class IObserver ;
class NotifyPayLoad;

class IObservable : public std::enable_shared_from_this <IObservable>{
public:
    IObservable(){}
    virtual ~IObservable() {} 

	virtual bool attach ( IObserver* observer ) = 0 ;
	virtual bool detach ( IObserver* observer ) = 0;
private:
};
typedef std::shared_ptr<IObservable>  IObservableptr;


class IObserver {
public:
	~IObserver  ( ) {
		std::shared_ptr<IObservable> subject_s = m_subject.lock();
		if ( subject_s ) {
			subject_s->detach ( this  );
		}
	}
	IObserver  ( std::weak_ptr<IObservable> subject)
			: m_subject (subject) {
		std::shared_ptr<IObservable> subject_s = m_subject.lock();
		if ( subject_s ) {
			subject_s->attach ( this  );
		}
	}
	virtual void notify ( NotifyPayLoad& ) = 0;
private:
	std::weak_ptr<IObservable> m_subject;
};
typedef std::shared_ptr<IObserver> IObserverPtr;

#endif //  __IOBSERVER_H__

