// You are standing at point (0,0) on an infinite plane. In one step, you can move from some point (xf,yf) to (xt,yt) any point  as long as the Euclidean distance, between the two points is either 'a' or 'b'. In other words, each step you take must be exactly  'a' or 'b' in length.
//
// You are given 'q' queries in the form of 'a','b' and 'd'. For each query, print the minimum number of steps it takes to get from point (0,0) to point (d,0) on a new line.
//
// Input Format
//
// The first line contains an integer,'q' , denoting the number of queries you must process. 
// Each of the  subsequent lines contains three space-separated integers describing the respective values of 'a', 'b' and 'd' for a query.
//
// Constraints
// 1 <= q <= 10^5
// 1 <= a < b <= 10^9
// 0 <= d <= 10^9
//
// Output Format
//
// For each query, print the minimum number of steps necessary to get to point  on a new line.
//
// Sample Input
// 3
// 2 3 1
// 1 2 0
// 3 4 11
// Sample Output
// 2
// 0
// 3
// Explanation
//  We perform the following q=3 queries:
//
//  _1_ One optimal possible path requires two steps of length a=2: (0,0)->(1/2, sqrt(15)/2)->(1,0). Thus, we print the number of steps, 2, on a new line.
//  _2_ The starting and destination points are both (0,0), so we needn't take any steps. Thus, we print '0' on a new line.
//  _3_ One optimal possible path requires two steps of length b=4 and one step of length a=3:  (0,0)->(4,0)->(8,0)->(11,0). Thus, we print 3 on a new line.

#include <iostream>
#include <vector>
#include <ostream>
using namespace std;

class userInput {
public:
    struct Query {
        int smallStep ;
        int bigStep ;
        int distance;
    } ;
    typedef vector<Query>  Queries ;

    Queries  getQueries ( ) const { return m_stepOptions ; }
    void addQuery ( Query& q) { m_stepOptions.push_back(q); }
private:
    Queries     m_stepOptions;
    friend ostream& operator << ( ostream& , const userInput& );
};
void run_final ();
void test_userInput() ;
void test_querySolver () ;
int main () {
    // test_userInput();
    // test_querySolver () ;
    run_final ();
    return 0;
}
void readUserInput (userInput &uiObj ) {
    int count;
    scanf("%d",&count);
    for ( ; count > 0 ; count-- ) {
        int f, s, d;
        scanf("%d %d %d", &f, &s, &d );
        userInput::Query   q { f, s, d };
        uiObj.addQuery ( q );
    }
}
ostream& operator << ( ostream& stream, const userInput& uiObj) {
    stream << uiObj.m_stepOptions.size() << endl;
    for ( auto q : uiObj.m_stepOptions ) {
        stream << q.smallStep << " " << q.bigStep << " " << q.distance << endl;
    }
    return stream;
}

void test_userInput() {
    userInput   usrInpObj;
    readUserInput ( usrInpObj );
    cout << usrInpObj << endl;
}
void solveQueries ( const userInput::Queries& uiObj );
void run_final () {
    userInput   usrInpObj;
    readUserInput ( usrInpObj );
    solveQueries ( usrInpObj.getQueries() );
}
void test_querySolver ( ) {
    userInput uiObj;
    userInput::Query    q1 {2,3,1};
    userInput::Query    q2 {1,2,0};
    userInput::Query    q3 {3,4,11};
    uiObj.addQuery ( q1 );
    uiObj.addQuery ( q2 );
    uiObj.addQuery ( q3 );
    solveQueries ( uiObj.getQueries() );
}
int solveQuery ( const userInput::Query & q ) {
    userInput::Query    qObj = q;
    if ( qObj.bigStep < qObj.smallStep ) {
        qObj.bigStep = q.smallStep;
        qObj.smallStep = q.bigStep;
    }
    int steps = qObj.distance / qObj.bigStep ;
    int gap = qObj.distance % qObj.bigStep ;

    if ( gap == 0 ) return steps ;
    if  ( gap == qObj.smallStep ) return steps + 1 ;
    if ( steps == 0 ) return 2;
    return steps + 1 ;
}
void solveQueries ( const userInput::Queries& queries ){
    for ( auto q :  queries ) {
        int moves = solveQuery ( q ) ;
        cout << moves << endl ;
    }
}
