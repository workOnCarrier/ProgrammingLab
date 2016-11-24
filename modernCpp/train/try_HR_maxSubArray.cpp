// We define the following:
//
// A subarray of an n-element array, A, is a contiguous subset of A's elements in the inclusive range from some index i to some index j where 0 <= i < j < n.
// The sum of an array is the sum of its elements.
// Given an n-element array of integers, A, and an integer, m, determine the maximum value of the sum of any of its subarrays modulo m. This means that you must find the sum of each subarray modulo m, then print the maximum result of this modulo operation for any of the n*(n+1)/2 possible subarrays.
//
// Input Format
//
// The first line contains an integer, q, denoting the number of queries to perform. Each query is described over two lines:
//
// The first line contains two space-separated integers describing the respective  n(the array length) and  m(the right operand for the modulo operations) values for the query.
// The second line contains  space-separated integers describing the respective elements of array A=a[0],a[1],...,a[n-1] for that query.
// Constraints
//  2 <= n <= 10^5
//  1 <= m <= 10^14
//  1 <= a[i] <= 10^18
//  2 <= sum of n over all test cases <= 5*10^5
//Output Format
//  For each query, print the maximum value of  on a new line.
//
//  Sample Input
//  1
//  5 7
//  3 3 9 9 5
//  Sample Output
//  6
//  Explanation
//  The subarrays of array  and their respective sums modulo  are ranked in order of length and sum in the following list:
//  [9] ==> 9%7 = 2  , [9] ==> 9%7 = 2
//    [3] ==> 3%7 = 3  , [3] ==> 3%7 = 3
//    [5] ==> 5%7 = 5
//  [9,5] ==> 14%7 = 0   ,   [9,9] ==> 18%7 = 4
//    [3,9] ==> 12%7 = 5  ,  [3,3] ==> 6%7 = 6
//  [3,9,9] ==> 21%7 = 0  ,  [3,3,9] ==> 15%7 = 1
//    [9,9,5] ==> 23%7 = 2
//  [3,9,9,5] ==> 26%7 = 5  , [3,3,9,9] ==> 24%7 = 3
//  [3,3,9,9,5] ==> 29%7 = 1
//          As you can see, the maximum value for  subarray sum % 7 for any subarray is 6, so we print 6 on a new line.
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ostream>
using namespace std;

typedef struct {
        long long factor;
        vector<long long> nums;
} qParams;
typedef vector<qParams> qpvect;

qpvect getInput() ;
void processQPVect ( qpvect& qpv ) ;
ostream& operator << ( ostream &stream, const qParams & qp ) {
    stream << qp.factor << " " << qp.nums.size() << endl;
    stream << "   -- " << endl;
    for ( auto val : qp.nums ) {
        stream << val << " " ;
    }
    return stream;
}
void testInput () {
    qpvect qpvo = getInput ();
    for ( auto val : qpvo ) {
        cout << val << endl;
    }
}
void test_processing () ;
int main() {
    // testInput ();
    test_processing () ;
    return 0;
    qpvect qpvo = getInput ();
    processQPVect ( qpvo ) ;
    return 0;
}

void test_processing () {
    // qParams qpo = {20, {23,34,45,56,67,78,89} };
    qParams qpo = {20, {23,34,45,56,67,78,89} };
    qpvect  qpvo;
    qpvo.push_back ( qpo );
    qpo = {200, {23,34,45,56,67,78,89,90} };
    qpvo.push_back ( qpo );

    processQPVect ( qpvo ) ;
    cout << " finished processing " << endl;
}
qpvect getInput() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin >> q;
    qpvect  qpv;
    // cout << " getting " << q << " value " << endl;
    for ( int c = 0; c < q ; c++ ) {
        // cout << "-- getting " << c << "th input" << endl;
        qParams p;
        unsigned int count;
        cin >> count >> p.factor;
        long long val;
        for ( unsigned int i = 0; i < count ; i ++ ) {
            cin >> val;
            p.nums.push_back(val);
        }
        qpv.push_back ( p );
    }
    return qpv;
}
void processQPVect ( qpvect& qpv ) {
    for ( auto pv : qpv ) {
        long long ans = 0;
        unsigned int   vsize = pv.nums.size();
        for ( unsigned int index = 0; index < vsize; index++ ) {
            unsigned int vsubsize = vsize - index;
            long long sum = 0;
            for ( unsigned int sub = 0; sub < vsubsize ; sub ++ ){
                long long val = 0;
                sum += pv.nums[index + sub] ;
                val = sum % pv.factor;
                // cout << "index:" << index << " sub:" << sub << " sum:" << sum << " val:" << val << endl;
                if ( val  > ans ) {
                    ans = val;
                }
            }
        }
        cout << ans << endl;;
    }
}

