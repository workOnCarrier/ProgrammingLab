#include <iostream>
#include "point.h"

using namespace std;
int main () {

    auto c = point::newCartesian ( 1,2);
    cout << c << endl;

    c = point::newPolar ( 1,2);
    cout << c << endl;

    return 0;
}
