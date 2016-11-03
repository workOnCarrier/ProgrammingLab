// You have a string,'S' , of lowercase English alphabetic letters. You can perform two types of operations on 'S':
//
// _1_ Append a lowercase English alphabetic letter to the end of the string.
// _2_ Delete the last character in the string. Performing this operation on an empty string results in an empty string.
// Given an integer, 'K', and two strings, 'S' and ,'T' determine whether or not you can convert 'S' to 'T' by performing exactly  'K' number of the above operations on 'S'. If it's possible, print Yes; otherwise, print No.
//
// Input Format
//
// The first line contains a string, 'S', denoting the initial string. 
// The second line contains a string,'T' , denoting the desired final string. The third line contains an integer, 'R', denoting the desired number of operations.
//
// Constraints
// 1 <= len(S) <= 100
// 1 <= len(T) <= 100
// 1 <= R <= 100
// 'S' and 'T' consist of lowercase English alphabetic letters.
//  Output Format
//
//  Print Yes if you can obtain string  by performing exactly  operations on ; otherwise, print No.
//
//  Sample Input 0
//  hackerhappy
//  hackerrank
//  9
//  Sample Output 0
//  Yes
//  Explanation 0
//      We perform  delete operations to reduce string  to hacker. Next, we perform  append operations (i.e., r, a, n, and k), to get hackerrank. Because we were able to convert  to  by performing exactly  operations, we print Yes.
//
//  Sample Input 1
//  aba
//  aba
//  7
//  Sample Output 1
//  Yes
//  Explanation 1
//      We perform  delete operations to reduce string  to the empty string (recall that, though the string will be empty after  deletions, we can still perform a delete operation on an empty string to get the empty string). Next, we perform  append operations (i.e., a, b, and a). Because we were able to convert  to  by performing exactly  operations, we print Yes.

#include <iostream>
#include <ostream>
#include <cstdio>
#include <cstring>

using namespace std;

void LearnStrcmp ( ) ;
class AppendDeleteContext {
public:
    AppendDeleteContext ( string s, string t, int steps );
    int steps ( ) { return m_steps;}
    int matchLength ( ) {return m_matchLength;}
    int deleteLength ( ) {return m_deleteLength;}
    int appendLength ( ) {return m_appendLength;}
    void decreaseMatchLen ( ) {
        if ( m_matchLength > 0 ) {
            --m_matchLength;
            ++m_appendLength;
        }
        ++m_deleteLength;
    }
    int StepCount () {
        return m_deleteLength + m_appendLength;
    }
private:
    string  m_s ;
    string  m_t ;
    int     m_steps ;
    int     m_matchLength ;
    int     m_deleteLength ;
    int     m_appendLength ;
    friend ostream& operator << ( ostream& ,const  AppendDeleteContext& );
};
bool checkIfAppendDeletePossible ( const string s, const string t, const int steps ){
    bool    possibleFlag = false;
    AppendDeleteContext  adContextObj ( s, t, steps );
    while ( true ) {
        if ( adContextObj.steps() == adContextObj.StepCount() ) {
            possibleFlag = true;
            break;
        }
        if ( adContextObj.steps() < adContextObj.StepCount() ) {
            break;
        }
        adContextObj.decreaseMatchLen ();
    }
    return possibleFlag;
}

AppendDeleteContext::AppendDeleteContext ( string s, string t, int steps ) 
    : m_s(s), m_t(t), m_steps ( steps ) {
    int start = s.length();
    int target = t.length();
    int match = 0; // you need a separate variable -- VisStudio needs -- can't use count outside for loop
    for ( int count = 1; count <= start && count <= target ; count++ )
    {
        if ( 0 == strncmp ( s.c_str(), t.c_str(), count ) ) {
            match = count;
        } else { break; }
    }
    m_matchLength = match;
    m_deleteLength = s.length() - match;
    m_appendLength = t.length() - match;
}
ostream& operator << ( ostream& stream, const  AppendDeleteContext& adContextObj) {
    stream << "start string:" << adContextObj.m_s << endl;
    stream << "target string:" << adContextObj.m_t << endl;
    stream << "matchLength:" << adContextObj.m_matchLength << "\t";
    stream << "deleteLength:" << adContextObj.m_deleteLength << "\t";
    stream << "appendLength:" << adContextObj.m_appendLength << "\t";
    stream << "steps:" <<  adContextObj.m_steps << "\t";
    return stream;
}

void test_AppendDeleteContext () ;
void finalRun_with_IO() ;
void finalRun(const string&, const string&, const int) ;
void test_finalRun() ;

int main () {
    // LearnStrcmp ( )  ;
    // test_AppendDeleteContext ( ) ;
    // test_finalRun ( ) ;
    finalRun_with_IO ( ) ;
    return 0;
}
void finalRun_with_IO() {
    string  startStr,finalStr;
    int     stepsCount;
    cin >> startStr >> finalStr >> stepsCount ;
    finalRun ( startStr, finalStr,  stepsCount );
}
void finalRun(const string& startStr, const string& finalStr, const int stepsCount ) {
    if ( checkIfAppendDeletePossible ( startStr, finalStr, stepsCount ) ) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}
void test_finalRun() {
    int     stepsCount = 3;
    string startStr = "abcd";
    string finalStr_1 = "abc";
    cout << "src:" << startStr << " trgt:" << finalStr_1 << " stepCount:"  << stepsCount << endl;
    finalRun ( startStr, finalStr_1, stepsCount );

    string finalStr_2 = "abcd";
    cout << "\nsrc:" << startStr << " trgt:" << finalStr_2 << " stepCount:"  << stepsCount << endl;
    finalRun ( startStr, finalStr_2, stepsCount );

    string startStr_1 = "hackerhappy";
    string finalStr_3 = "hackerrank";
    stepsCount = 9;
    cout << "\nsrc:" << startStr_1 << " trgt:" << finalStr_3 << " stepCount:"  << stepsCount << endl;
    finalRun ( startStr_1, finalStr_3, stepsCount );

    string startStr_2 = "aba";
    string finalStr_4 = "aba";
    stepsCount = 7;
    cout << "\nsrc:" << startStr_2 << " trgt:" << finalStr_4 << " stepCount:"  << stepsCount << endl;
    finalRun ( startStr_2, finalStr_4, stepsCount );

}
void test_AppendDeleteContext () {
    cout << "Testing initializing" << endl;
    string s = "test_1";
    string t1 = "test_1";
    int steps = 4;
    AppendDeleteContext  adContextObj_1 ( s, t1, steps );
    cout << adContextObj_1 << endl;
    cout << "Testing initializing -- run 1 -----------" << endl;

    string t2 = "test_";
    steps = 5;
    AppendDeleteContext  adContextObj_2 ( s, t2, steps );
    cout << adContextObj_2 << endl;
    cout << "Testing initializing -- run 2 -----------" << endl;

}

void LearnStrcmp ( ) {
    cout << " comparing fun with fun " << endl;
    char str1[] = "fun";
    char str2[] = "fun";
    int compRet = strncmp ( str1, str2, strlen(str1) );
    cout << " --> " << compRet << endl;

    cout << " comparing fun with fum " << endl;
    char str3[] = "fum";
    compRet = strncmp ( str1, str3, strlen(str1) );
    cout << " --> " << compRet << endl;

    cout << " comparing fun with fui" << endl;
    char str4[] = "fui";
    compRet = strncmp ( str1, str4, strlen(str1) );
    cout << " --> " << compRet << endl;

    cout << " comparing fun with funy " << endl;
    char str5[] = "funy";
    compRet = strncmp ( str1, str5, strlen(str1) );
    cout << " --> " << compRet << endl;

    cout << " comparing fun with fuoy " << endl;
    char str6[] = "fuoy";
    compRet = strncmp ( str1, str6, strlen(str1) );
    cout << " --> " << compRet << endl;

    cout << " comparing fun with fupy " << endl;
    char str7[] = "fupy";
    compRet = strncmp ( str1, str7, strlen(str1) );
    cout << " --> " << compRet << endl;

}
