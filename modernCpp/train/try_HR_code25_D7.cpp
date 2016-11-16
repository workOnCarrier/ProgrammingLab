// 
// We consider two sequences of integers, a[0], a[1], a[2],..., a[n-1] and b[0], b[1], b[2],..., b[n-1]  to be similar if there exists a polynomial, P(x) , with integer coefficients of a degree <= k such that P(i)=a[i]-b[i] (where m=998244353) for 0<=i<n.
//
// Given sequences a and b , find and print the minimal integer x (where 0 <=x<=n) such that a cyclic shift of b on x elements (sequence b[x mod n], ..., b[ (x+n-1)mod n]) is similar to a; if no such x exists, print -1 instead.
//
// Input Format
//
// The first line contains two space-separated integers describing the respective values of n (the length of the sequences) and k(the maximum degree of polynomial).
// The second line contains n space-separated integers describing the respective values of a[0],a[1],...,a[n-1].
// The second line contains space-separated integers describing the respective values of b[0],b[1],...,b[n-1].
//
// Constraints
// 1 <= n<= 10^5
// 0 <= k<= 10^9
// 0 <= a[i],b[i]< m
//
// Output Format
//
// Print an integer, x , denoting the minimal appropriate cyclic shift. If no such value exists, print -1 instead.
//
// Sample Input 0
//
// 6 0
// 1 2 1 2 1 2
// 4 3 4 3 4 3
//
// Sample Output 0
//
// 1
//
// Explanation 0
//
// After a cyclic shift of x=1, sequence b is [3,4,3,4,3,4] and P(x) = -2. Thus, we print 1.
//
// Sample Input 1
//
// 4 2
// 1 10 100 1000
// 0 0 0 0
//
// Sample Output 1
//
// -1
//
// Explanation 1
//
// Sequence b does not change after any cyclic shift and there are no integers a, b, and c such that and P(x)=a.x^2 + b*x + c,  and P(0)=1, P(1)=10, P(2)=100 and P(3) = 1000 mod m. Thus, we print -1.
//
