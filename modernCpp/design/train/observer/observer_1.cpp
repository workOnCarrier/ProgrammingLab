

#include <iostream>
#include "observer_1.h"

GreenObserver::GreenObserver (std::weak_ptr<IObservable> subject )
	: IObserver(subject) { }
void GreenObserver::notify ( NotifyPayLoad& payLoad) {
	if ( payLoad.color == colors::green ) {
		track++;
	}
}

RedObserver::RedObserver ( std::weak_ptr<IObservable> subject) 
	: IObserver(subject) { }
void RedObserver::notify ( NotifyPayLoad& payLoad) {
	if ( payLoad.color == colors::red ) {
		track++;
	}
}

BlueObserver::BlueObserver (std::weak_ptr<IObservable> subject ) 
	:IObserver(subject){ }
void BlueObserver::notify ( NotifyPayLoad& payLoad){ 
	if ( payLoad.color == colors::blue ) {
		track++;
	}
}
