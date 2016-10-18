#include <stdio.h>
#include <iostream>
using namespace std;
class Test
{
    public:
        int i;
        void get();
};
void Test::get()
{
    std::cout << "Enter the value of i: ";
    std::cin >> i;
}
Test t; // Global object
int main_() {
    Test t; // local object
    t.get();
    std::cout << "value of i in local t: "<<t.i<<'\n';
    ::t.get();
    std::cout << "value of i in global t: "<<::t.i<<'\n';
    return 0;
}

int main_2 () {
 char a = '\012';
 printf ( "%d", a );
 return 0;
 
}

int main_3 () {
    int i = 3;
    int l = i / -2;
    int k = i % -2;
    cout << l << k;
    return 0;
}

int main_4 () {
    float n = 1.1;
    double m = 1.1;
     
    if ( n == m ) cout << "s";
    else cout << "h";
    return 0;
}

int main_5 () {
    int n = 10;
    float m = 20;
    cout << sizeof ( n+m);
return 0;
}

int main_6 () {
//     void a = 10, b=10;
int a = 10, b=10;
    int c;
    c = a + b;
    cout << c << endl;;
    return 0;
}

int main_7 () {
    int a[] = {10, 20, 30};
    cout << -2[a] << endl;
    return 0;
}

int main_8 () {
    int a [] = {4,5,56,7};
    cout << a;
return 0;}

int main_9 () {
    char* const p = "nice";
 //   p  = "new nice";
return 0;
}

void sum ( int a, int b, int&c ){
    a = b+c;
    b = a+c;
    c = a+b;
}
int main_10 () {
    int x = 2, y = 3;
    sum(x,y,y);
    cout << x << " " << y << endl;
    return 0;
}

double  wh() {
    double h = 46.5;
    return h;
}
int main_11 () {
    double h = wh();
    cout << "weekly h" << h;
    return 0;
}

class Base {
    public:
        virtual void show() { cout<<" In Base \n"; }
};
class Derived: public Base {
    public:
        void show() { cout<<"In Derived \n"; }
};
int main_12(void) {
    Base *bp = new Derived;
    bp->show();Base &br = *bp;
    br.show();
    return 0;
}

template <typename T>
T max(T x, T y)
{
    return (x > y)? x : y;
}
int main()
{
    cout << max(3, 7) << std::endl;
    cout << max(3.0, 7.0) << std::endl;
    cout << max(3, 7.0) << std::endl;
    return 0;
}
