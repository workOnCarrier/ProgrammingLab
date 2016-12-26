#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include "IObserver.h"

enum class colors  {green = 0, red = 1, blue = 2};

class NotifyPayLoad {
public:
	colors color;
};

class GreenObserver : public IObserver {
public:
	GreenObserver (std::weak_ptr<IObservable>) ;
	virtual void notify ( NotifyPayLoad& ) ;
	int getTrack() { return track; }
private:
	int track;
};

class RedObserver : public IObserver {
public:
	RedObserver (std::weak_ptr<IObservable> ) ;
	virtual void notify ( NotifyPayLoad& ) ;
	int getTrack() { return track; }
private:
	int track;
};

class BlueObserver : public IObserver {
public:
	BlueObserver (std::weak_ptr<IObservable> ) ;
	virtual void notify ( NotifyPayLoad& ) ;
	int getTrack() { return track; }
private:
	int track;
};

#endif //  __OBSERVER_H__
