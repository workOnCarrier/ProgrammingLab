#include <iostream>

using namespace std;

// find binary gap 
// -- codility 
// https://codility.com/programmers/lessons/1-iterations/binary_gap/
//

// logic
// find the first msb which is 1
// check if the next bit is 0, increment the counter
// continue till you find the another bit 1
// if no other 1 bit is found, reset counter to 0
// set max counter to value of counter
// return the final value of max counter
//

int findFirstSet ( int number, int offset = 0 ) {
    int shiftedNum = number >> offset;
    return shiftedNum;
}


void test_findFirstSet () {
    cout << "testing shifting right with 0 as offset " << endl;
    int beforeNumber = 5;
    int afterNumber = findFirstSet ( 5, 0 );
    cout << beforeNumber << endl;
    cout << afterNumber << endl;

    cout << "testing shifting right with 1 as offset - expected 2" << endl;
    afterNumber = findFirstSet ( 5, 1 );
    cout << afterNumber << endl;
}
int main () {
    // test_findFirstSet ();
    return 0;
}


int solution(int N) {
    // write your code in C++11 (g++ 4.8.2)
	bool started = false;
	int currentCount = 0;
	int maxCount = 0;
	for ( int i  = 0; i < 32; i ++ ) {
		int shiftedNum = N >> i;
		int bitcheck = shiftedNum & 1;
		if ( bitcheck == 1 ) {
			if ( !started ) { started = true; }
			else { 
				if ( currentCount > maxCount ) {
					maxCount = currentCount;
				}
			}
			currentCount = 0;
		} else {
			if ( started ) {
				currentCount ++;
			}
		}
	}
	return maxCount;
}
