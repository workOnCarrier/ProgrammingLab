
#include <iostream>
#include <memory>



using namespace std;
class A : public std::enable_shared_from_this<A> {
public:
	A () = default;
	virtual ~A () = default;
	void display ( ) { 
		cout << " this is from A " << endl;
	}
};
int main () {
	A a;
	a.display();
	// following code does not work till C++ 17
	// std::shared_ptr<A> aptr = a.shared_from_this();
	// aptr->display();
	return 0;
}

