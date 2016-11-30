#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

// implement a solution function that takes a string and 
// calculates as below instructions
// string will constitute numbers and operators '*' and '+'
// all numbers are in the range 0-9
// push the first number on to stack
// push the sedond number on to stack
// when operator is observed, pop the top two numbers 
// and apply the relevant operator
// given all numbers are positive and operators are * and +
// expected result is >= 0
// in case the string has errors, return -1
int solution ( string & S );
void test_solution ( ) ;

int main () {
    test_solution ( ) ;
    return 0;
}

void test_solution ( ) {
    string s = "13+62*7+*";
    int val = solution ( s );
    cout << val << endl;
}
bool getTopTwoFromStack ( stack<int>& stack, int& one, int& two );
int solution ( string & S ) {
    long ans = 0;
    int final_ans = 0;
    int slen = S.length();
    int charIntVal;
    bool isError = false;
    stack<int>     intStack; 
    for ( int i = 0; i < slen; i++ ) {
        char tmp [] = {S[i],'\n'};
        if ( isdigit ( S[i] ) ) {
            charIntVal = atoi ( tmp );
            intStack.push ( charIntVal );
        }else {
            int one = 0, two = 0;
            bool isStackProper ;
            if ( S[i] == '+' ) {
                isStackProper = getTopTwoFromStack  ( intStack, one, two );
                if ( isStackProper  == false ) {isError = true;   break; }
                charIntVal = one + two;
                if ( charIntVal < 0 )  {  isError = true; break; }
                intStack.push ( charIntVal );
            }else
            if ( S[i] == '*' ) {
                isStackProper = getTopTwoFromStack  ( intStack, one, two );
                if ( isStackProper  == false ) {isError = true;   break; }
                charIntVal = one * two;
                if ( charIntVal < 0 )  {  isError = true; break; }
                intStack.push ( charIntVal );
            } else{
                isError = true; break; 
            }
        }
    }
    if ( isError == true ) { 
        final_ans = -1; 
    } else { final_ans  = intStack.top(); }
    return final_ans;
}
bool getTopTwoFromStack ( stack<int>& stack, int& one, int& two ) {
     if ( stack.empty() ) {return false;}
     one = stack.top();
     stack.pop();
     if ( stack.empty() ) {return false;}
     two = stack.top();
     stack.pop();
     return true;
}
