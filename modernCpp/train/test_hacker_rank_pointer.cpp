#include <iostream>

using namespace std;
void update ( int* a, int* b ) {
    *a = *a + *b;
    *b = *a - 2*(*b);
    *b = *b < 0 ? -*b : *b;
}
int main () {
    int a , b;
    cin >> a >> b;
    update ( &a, &b );
    cout << a << endl;
    cout << b << endl;

}
