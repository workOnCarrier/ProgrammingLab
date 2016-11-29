#include <iostream>
#include "newPoint.h"
#include "newPointFactory.h"

using namespace std;
int main () {

    auto c = NewPointFactory::newCartesian ( 1,2);
    cout << c << endl;

    c = NewPointFactory::newPolar ( 1,2);
    cout << c << endl;

    return 0;
}
