#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>


using namespace std;
class Matrix {
};

int main () {
    int cases, icase;
    cin >> cases;

    for ( icase=0; icase < cases; icase++ ) {
        Matrix x;
        Matrix y;
        Martix result;

        int n, m, i, j;
        cin >> n >> m;
        auto matrixRead = [Matrix &A, int n, int m]() {
            for ( int i = 0; i < n; i++ ) {
                vector<int> b;
                int num;
                for ( int j = 0; j < m ; j ++ ) {
                    cin >> num;
                    b.push_back ( num );
                }
                x.a.push_back ( b );
            }
        };
        matrixRead ( x, n, m );
        matrixRead ( y, n, m );
        result = x + y;
        for ( i = 0; i < n; i++ ){
            for ( j = 0; j < m; j++ ) {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
