#include <iostream>
#include <vector>
#include <functional>


using namespace std;

void test_mutable_lambda() {
    vector<int> intvector  = {1,2,3,4,5,6,7};
    int     running_total = 0;

    for ( const int &value : intvector ) {
        cout << " value aded:" << value << endl;
        [ &running_total , value ]()  mutable 
        // missing mutable will render running_total const
        { 
            running_total += value; 
            cout << "running total:" << running_total ;
        }();
    }
    cout << "running total with lambda in for loop is " << running_total << endl; 
}

void NotToDo_Lambda_1 () {
    cout << __FUNCTION__ << " NotToDo_Lambda_1 " << endl;
    auto dummy = 0;
    function<int(int&)> f;
    {
        auto insideBlock  = 5;
        f = [&insideBlock](int &getValue) ->int{ getValue = insideBlock;};
    }
    f(dummy);
    cout << "Value from inside block " << dummy << endl;
    cout << __FUNCTION__ << " NotToDo_Lambda_1  -- undefined by standard by gcc5 has some custom implementation" << endl;
}

int main () {
    test_mutable_lambda () ;
    NotToDo_Lambda_1 () ;
    return 0;
}
