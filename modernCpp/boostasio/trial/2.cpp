


#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;



class car {
};
class taxi : public car{
};
class limo : public car {
};

class student{
    public:
    int id;
    float gpa;

};


void typeExperiments();
int trial();
int initialization(){
    float *f1 = new float();
    float *f2 = new float;

    student *s1 = new student;

    cout << s1->id << " " << s1->gpa << endl;

    cout << " initialization : float() " << *f1 << endl;
    cout << " initialization : float " << *f2 << endl;
    return 0;
}
int main (){
    initialization();
    typeExperiments();
    enum day { mon=11, tue = 12 };

    day d = mon;
    enum day d2 = mon;
    // enum day d3 = day::mon;
    // enum day d3 = day.mon;
    // enum day d3 = dynamic_cast<enum day>(mon);
    return 0;
}
int trial(){

    car c;
    taxi t;
    limo l;

    car*  C[3] = {&c, &t, &l};
    for ( int i = 0; i < 3; i++ ){
        car* cp = C[i];
        
        // if ( rtti(*cp).name == "taxi" )
        // if ( typeid(t) == typeid (cp) )
        // if ( typeid(taxi) == typeid (*cp) )
        if ( typeid(taxi) == typeid (*cp) ){
            cout << "taxi" << endl;
        }else{
            cout << "not a taxi" << endl;
        }
    }
    return 0;
}

void typeExperiments() {
    int i = 10;
    cout << "typeExperiments : " << typeid(decltype(i+1.0)).name() << endl;
}
