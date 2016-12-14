

#include <iostream>

using namespace std;
class A {
    public:
        A ( );
        A (int num  );
        void display () {
			cout << "num is:" << m_num << endl;
        }
        ~A () {
			cout << " destroying the object" << endl;
        }
    private: 
        int m_num;
};


A::A():m_num(0)	{
	A(100);
}
A::A(int num):m_num(num){
    cout << " parameterized constructor" << endl;
}


int main () {
	A a;
	a.display();
    return 0;
}
