

#include <iostream>
#include <memory>
#include <thread>
#include "IObserver.h"
#include "observer_1.h"
#include "observable_1.h"

using namespace std;

int main () {
	std::shared_ptr<IObservable> subj = make_shared<Observable_1>();

	shared_ptr<GreenObserver>	go = make_shared<GreenObserver> (subj );
	shared_ptr<RedObserver>		ro = make_shared<RedObserver>   (subj );
	shared_ptr<BlueObserver>	bo = make_shared<BlueObserver>  (subj );

	Observable_1* observable_ptr = NULL;
	try {
		observable_ptr = dynamic_cast<Observable_1*> (subj.get());
		if ( observable_ptr == NULL ) {
			cout << " dynamic ptr cast failed" << endl;
			return 0;
		}
		(*observable_ptr ) ();
	} catch ( std::bad_cast &bc ) {
			cout << " dynamic cast failed " << endl;
	} catch ( ... ) {
		cout << " unknokw exception -- level 1" << endl;
	}

	cout << "green coutn "	<< go->getTrack() << endl;
	cout << "red coutn "	<< ro->getTrack() << endl;
	cout << "blue coutn "	<< bo->getTrack() << endl;

    return 0;
}
