#include "Memoization.h"
#include <iostream>

using namespace std;

auto main() -> int {
    cout << "testing memoization" << endl;
	int a = 50;
	int b = 10;
	int c = 1;
	Memoization<int,decltype(cout)> multiply_impure([&](){
	    return a*b*c;
	},cout);

	for ( int i = 0; i < 5; i++ ) {
	    c++;
	    cout << "output -- " << multiply_impure.Fetch() << endl;
	}
    return 0;
}
