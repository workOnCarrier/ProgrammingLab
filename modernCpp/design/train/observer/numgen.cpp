#include <thread>
#include "numgen.h"

void numGen::operator () () {
	int number = 0;
	while ( number < 1000 ) {
		processNumber (number);
		++number;
	}
	std::chrono::duration<int, std::ratio<10,1>> dur(1);
	std::this_thread::sleep_for ( dur );
}
