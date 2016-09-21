#include <iostream>

using namespace std;

int check_static_assert ( int a, int b ) {
    // thie works
    static_assert ( sizeof(int) <= 4, "Int is 4 bytes or less" );

    // this does not
    // static_assert ( sizeof(int) >= 3, "Int is 3 bytes or less" );

    return a+b;
}

// in templates for validation



int main ( int argc , char** argv ) {
    check_static_assert(4,5);
    return 0;
}
