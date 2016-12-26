#ifndef __OBSERVABLE_1_H__
#define __OBSERVABLE_1_H__
#include <list>
#include "observer_1.h"
#include "numgen.h"

class Observable_1 :  public numGen , public IObservable {
public:
	Observable_1 ( ) {}
	virtual ~Observable_1 ( ) {}

	virtual bool attach ( IObserver* observer ) {
		m_observers.push_back ( observer );
		return true;
	}
	virtual bool detach ( IObserver* observer ) {
		m_observers.remove ( observer );
		return true;
	}

private:
	void notify ( NotifyPayLoad & );
	virtual void processNumber ( int )  ;
	std::list<IObserver*> m_observers;
};


#endif //  __OBSERVABLE_1_H__
