// Create three classes Person, Professor and Student. The class Person should have data members name and age. The classes Professor and Student should inherit from the class Person.
//
// The class Professor should have two data members: publications and cur_{id}. There will be two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age and publications of the professor. The function putdata should print the name, age, publications and the cur_{id} of the professor.
//
// The class Student should have two data members: marks, which is an array of size 6 and cur_{id}. It has two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age, and the marks of the student in  6 subjects. The function putdata should print the name, age, sum of the marks and the cur_{id} of the student.
//
// For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from 1.
//
// Solve this problem using virtual functions, constructors and static variables. You can create more data members if you want.
//
// Input Format
//
// There are two types of input. If the object being created is of the Professor class, you will have to input the name, age and publications of the professor.
//
// If the object is of the Student class, you will have to input the name, age and the marks of the student in 6 subjects.
//
// Constraints
// 1 <= len(name) <= 100  where  is the length of the name. 
// 1 <= age <= 80
// 1 <= publications <= 1000
// 0 <= marks <= 100 , where marks is the marks of the student in each subject.
//
//   Output Format
//
//   There are two types of output depending on the object.
//
//   If the object is of type Professor, print the space separated name, age, publications and id on a new line.
//
//   If the object is of the Student class, print the space separated name, age, the sum of the marks in 6 subjects and id on a new line.
//
//   Sample Input
//
//   4
//   1
//   Walter 56 99
//   2
//   Jesse 18 50 48 97 76 34 98
//   2
//   Pinkman 22 10 12 0 18 45 50
//   1
//   White 58 87
//   Sample Output
//
//   Walter 56 99 1
//   Jesse 18 403 1
//   Pinkman 22 135 2
//   White 58 87 2

#include <iostream>
#include <vector>

using namespace std;


class Person{
public:
    Person(){}
    virtual void getdata(){cin >> m_name >> m_age;}
    virtual void putdata() {
        cout << m_name << " " <<  m_age;
    }
private:
    string  m_name;
    int     m_age;
};

class Professor : public Person{
public:
    Professor ():id(++Count) {}
    virtual void getdata(){
        Person::getdata();
        cin >> m_publications ;
    }
    virtual void putdata() {
        Person::putdata();
        cout << " " << m_publications  << " "<< id << endl ;
    }
private:
    int     m_publications;
    int     id;
    static int Count;
};
int Professor::Count = 0;

class Student : public Person{
public:
    Student ():id(++Count) {}
    virtual void getdata() {
        Person::getdata();
        int mark;
        for ( int i = 0; i < 6; i++ ) {
            cin >> mark ;
            m_marks.push_back( mark );
        }
    }
    virtual void putdata() { 
        int sum = 0;
        for ( auto val : m_marks ) {
            sum += val;
        }
        Person::putdata();
        cout << " " << sum << " " << id << endl;
    }
private:
    vector<int>     m_marks;
    int             id;
    static int Count;
};
int Student::Count = 0;


int main () {
    int n, val;
    cin >> n;
    Person *per[n];

    for ( int i = 0; i < n; i++ ) {
        cin >> val;
        if ( val == 1 ){
            per[i] = new Professor;
        } else{
            per[i] = new Student;
        }
        per[i]->getdata();
    }

    for ( int i = 0; i < n; i++ ){
        per[i]->putdata();
    }
    return 0;
}
