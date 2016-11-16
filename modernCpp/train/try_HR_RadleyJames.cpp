#include <iostream>
#include <vector>

using namespace std;

int getMsb ( int n ) {
    for ( int ct = 0 ; ct < 32 ; ct ++ ) {
        if ( ( n << ct ) <  0 )
            return 32-ct;
    }
}
int exor ( int n , int start ) {
    int changed = 1;
    for ( int ct = 1; ct < start; ct++ ) {
        changed = changed *2 | 1;
    }
    cout << changed << endl;
    int a = n & changed;
    int b = ~n & ~changed;
    // int final_ =  ~a & ~b;
    int final_ =  changed ^ n;
    int final_ =  changed ^ n;
    return final_;
}
void test_msb () {
    cout << getMsb ( 2 ) << endl;
    cout << getMsb ( 5 ) << endl;
}
void test_exor () {
    cout << exor ( 5, getMsb (5) ) << endl;
}
void test_sizeof () {
    char a[] = "";
    cout << sizeof(a) << endl;
}
class sc {
public:
    int x;
    sc ( int xx ) : x (xx){}
    sc ( const sc& a ) { x = a.x; x++; }
    void operator =  ( const sc & a ) { x = a.x; x--; }
    // x private member
    //
    // increment in 
};
void    test_class_a() {
    sc a(4);
    sc b = a;
    cout << b.x << endl;
}
class aa{
    public :
    // int up;
    int lw;
    int up;
    aa (int i ) : lw ( i), up (lw+1){}
};
void testaa() {
    aa a(5);
    cout << a.lw << " " << a.up << endl;
}
class A {
    public:
        int data;
        virtual void f(){};
        virtual void f1(){};
        virtual void f2(){};
};
void    test_sizeOf_c () {
    A a;
    cout << sizeof(a) << endl;
}
void    test_wierd () {
    char p1[] = "hello world";
    char *p = (char*)malloc(3);
    p = p1;
    cout << p << endl;
    cout << *p << endl;
}
int maxdiff ( vector<int> a ){
    int maxd = -1;
    int veclen = a.size();
    for ( int i = 0; i < veclen; i++ ){
        for ( int j = 0; j < i; j++ ) {
            int td  = 0;
            if ( a[i] > a[j] ) td = a[i] - a[j];
            maxd = td > maxd ? td : maxd;
        }
    }
    return maxd;
}
void test_vectorInts() {
    vector<int> v = {2,3,10,2, 4,8,1};
    cout << maxdiff ( v ) << endl;
    vector<int> w = {12,10,8,7,6};
    cout << maxdiff ( w ) << endl;
}
int main () {
    // test_msb ();
    // test_sizeof () ;
      test_exor () ;
    // test_class_a() ;
    // testaa();
    // test_sizeOf_c ();
    // test_wierd () ;
    // test_vectorInts();
    return 0;
}
