

#include <iostream>
#include <vector>

using namespace std;


template <typename T>
class displayVectProp {
public:
    displayVectProp (vector<T> &vobj): m_member(vobj) { }
    void operator () () {
        cout << " size:" << m_member.size() << endl;
        cout << " capacity:" << m_member.capacity() << endl;
        cout << " data:\n\t ";
        int count = 0;
        for ( auto val : m_member ) {
            cout << "value_" << ++count << " :"<< val << "\t" ;
        } cout << endl  ;
    }
private:
    vector<T>       &m_member;
};

void displayProperties_interview ( ) {
    cout << __FUNCTION__ << "----------------------------" << endl;
    vector<int> vobj ; vobj.reserve(10) ;
    vobj[0] = 10; cout << vobj[0] << endl;

    displayVectProp<int> dispObj(vobj);
    dispObj ();
    cout << " adding push back -------- " << endl;
    vobj.push_back(10);
    dispObj ();
}
void displayProperties_intParameter ( ) {
    cout << __FUNCTION__ << "----------------------------" << endl;
    vector<int> vobj(10) ;

    displayVectProp<int> dispObj(vobj);
    dispObj ();
}
void displayProperties_initializerList ( ) {
    cout << __FUNCTION__ << "----------------------------" << endl;
    vector<int> vobj{10,20} ;

    displayVectProp<int> dispObj(vobj);
    dispObj ();
}
void displayProperties_resize_later ( ) {
    cout << __FUNCTION__ << "----------------------------" << endl;
    vector<int> vobj(20) ;
    vobj.reserve(5) ;

    displayVectProp<int> dispObj(vobj);
    dispObj ();
    vobj.resize(5) ;
	cout << " after resize ---- > " << endl;
    dispObj ();
}
int main ( int argc, char** argv ) {
    displayProperties_interview  ( ) ;
    displayProperties_intParameter   () ;
    displayProperties_initializerList   () ;
	displayProperties_resize_later  ();
    return 0;
}
