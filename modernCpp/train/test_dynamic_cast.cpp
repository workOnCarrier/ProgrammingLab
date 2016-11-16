#include <iostream>
#include <vector>

using namespace std;


void test(){
    int x();
    cout << x << endl;
}
enum class shades : int { light, dark };


typedef struct {
    int a;
    int b;
    int c;
    int d;
} sides;
void test_poly() ;
int main () {
    // test();
    test_poly ();
    return 0;
}
void test_poly() {
    sides poly;
    vector<sides>   sideList;
    int readValue = 1;
    readValue = scanf ("%d %d %d %d", &poly.a,&poly.b,&poly.c,&poly.d );
    while ( readValue ){
        sideList.push_back ( poly);
        readValue = scanf ("%d %d %d %d", &poly.a,&poly.b,&poly.c,&poly.d );
    }
    int sc=0, rc=0, oc=0;
    for ( auto p : sideList ){
        if ( p.a == p.c && p.a == p.b && p.b == p.d) {sc++; continue;}
        if ( p.a == p.c && p.a != p.b && p.b == p.d) {rc++; continue;}
        else oc++;
    }
    cout << sc << " " << rc << " " << oc << endl;
}
