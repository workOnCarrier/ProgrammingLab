#include <iostream>


using namespace std;

void foo ( int a, int b ){
    cout << "a:" << a << " , b:" << b << endl;
}
int get_num() {
    static int i = 0;
	i++;
	return i;
}

int main ( ) {
    foo ( get_num(), get_num() );
    return 0;
}
