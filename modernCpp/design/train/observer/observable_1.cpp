#include "observable_1.h"


void Observable_1::notify ( NotifyPayLoad & pl) {
	for ( auto val : m_observers ) {
		val->notify ( pl );
	}
}
void Observable_1::processNumber ( int val) {
	int rem = val % 5;
	NotifyPayLoad  pl;
	if ( rem == 1 ) {
		pl.color = colors::green;
	} else if ( rem == 2 ) {
		pl.color = colors::red;
	} else if ( rem == 3 ) {
		pl.color = colors::blue;
	} else {
		return ;
	}
	notify ( pl );
}
