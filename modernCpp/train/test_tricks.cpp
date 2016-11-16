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
    // char* const p = "nice";
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
int main_13()
{
/*    cout << max(3, 7) << std::endl;
    cout << max(3.0, 7.0) << std::endl;
    cout << max(3, 7.0) << std::endl;
 */   return 0;
}

class dummy_class_14{
    public:
        static int data;
};
int dummy_class_14::data = 0;

void test_static_dc_14() {
   dummy_class_14 obj;
   cout << dummy_class_14::data  << endl;
//    cout << obj::data << endl;
 //  cout << dummy_class_14::obj.data << endl;
//   cout << obj->data << endl;
}
enum Day { Mon=11, Tue=12 };
void test_enum_scope () {
    enum Day var = Day::Mon;
    Day var1 = Day::Mon;
    enum Day var2 = Mon;
}
void test_const () {
    double val = 0.0;
    double val_orig = 0.0;
  //   double *ptr const = &val_orig;
  //   ptr = &val;
    cout << "Hello" << endl;
}
class car {
    public: car(){}
    virtual ~car() {}
};
class t : public car {
};
class l : public car {
};
void test_typeid () {
    car c1;
    // t c1_2;
    l c3;
    car *cars[3] = { &c1,&c1_2,&c3 };
    car *cp;
    for ( int i = 0; i < 3; i++ ){
        cp = cars[i];
        if ( typeid(*cp) == typeid(c2) ) { cout << "obj" << endl; }
        if ( typeid(cp) == typeid(c2) ) { cout << "ptr" << endl; }
        if ( typeid(*cp) == typeid(t) ) { cout << "obj_name" << endl; }
        if ( rtti(*cp).name == "t" ) { cout << "rtti" << endl; }
    }
}
int main () {
// test_static_dc_14();
// test_enum_scope () ;
// test_const () ;
return 0;
}
