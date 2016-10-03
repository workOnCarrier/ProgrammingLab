

#include <iostream>
#include <memory>

using namespace std;

class Address {
    string* m_name = nullptr;
public:
    Address  ( string *name ) : m_name ( name ) {}
	string* getName() { return m_name; }
};

class Person {
    Address    *m_address = nullptr;
public:
    Person  ( Address* address ) : m_address ( address ) {}
    Address* getAddress () { return m_address; }
};

void print_houseName_withoutMonad ( Person* p ) {
	// not a very good code and real life can be very very challenging
	if ( 	   nullptr != p 
			&& nullptr != p->getAddress() 
			&& nullptr != p->getAddress()->getName() )
    cout << *(p->getAddress()->getName()) << " from WithoutMonad"  << endl;
	else
	cout << "null ptr from WithoutMonad" << endl;
}

void print_houseName_Monad( Person* p);
int main ( int argc, char** argv ) {
	string   testName = "test name";
	Address  addressObj (  &testName );
	Person	p (&addressObj );

    print_houseName_Monad(&p);

    print_houseName_withoutMonad(&p);
	return 0;
}

// declaration 
template <typename T> class Maybe ;

template <typename T> 
Maybe<T> maybe ( T* type ) {
    return Maybe<T>(type);
}

// definition 
template <typename T> class Maybe {
    T* m_context;
public :
	Maybe ( T* const context ) : m_context { context } {} // using initializer list instead of standard ()
	template <typename FUNC> 
	auto With ( FUNC convert ) {
	    if ( m_context == nullptr ) {
		    return Maybe<typename remove_pointer<decltype(convert(m_context))>::type>(nullptr );
		}else{
		    return maybe( convert(m_context) );
		}
	}
	template <typename FUNC> auto Do ( FUNC convert ) {
	    if ( m_context == nullptr ) {
		    cout << "null ptr" << endl;
		}else{
		    convert(m_context);
		}
	}
};

void print_houseName_Monad( Person* p){
	maybe(p)
	    .With ( [](auto x){ return x->getAddress();} )
	    .With ( [](auto x){ return x->getName();} )
		.Do ( [](auto x){ cout << *x  << " from Monad " << endl; } );
}
