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
template <int dimention>
class template_assert {
public:
    static_assert ( dimention < 4 , "cannot handle dimention more than 3" );
    template_assert (){
    }
	void display () {
	}
private:
    int values[dimention] ;
};

struct base {
public:
    virtual ~base(){}
};

template <typename T>
class my_mixin : public T {
    static_assert ( has_virtual_destructor<T>::value, "The destructor has to be virtual " );
    public:
	my_mixin(){}
};


int main ( int argc , char** argv ) {
    check_static_assert(4,5);

	template_assert<3>		obj_template_assert;
	// will not compile
	// template_assert<4>		obj_template_assert_not_working;


	my_mixin <base>			obj_my_mixin;
	// will not compile
	// my_mixin <int>			obj_my_mixin_invalid;
    return 0;
}
