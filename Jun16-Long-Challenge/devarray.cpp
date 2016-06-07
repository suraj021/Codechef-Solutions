#include <bits/stdc++.h>
using namespace std;

long a[100005];

int main(){

    int n, q;
    long t;

    cin >> n >> q ;

    long mini= INT_MAX;
    long maxi= INT_MIN;

    for( int i= 0; i< n; ++i ){
        cin >> a[i];

        if( a[i] > maxi )
            maxi= a[i];
        if( a[i] < mini )
            mini= a[i];
    }

    for( int i= 0; i< q; ++i ){
        cin >> t;

        if( t>= mini && t <= maxi )
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
