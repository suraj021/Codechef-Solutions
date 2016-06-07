#include <bits/stdc++.h>
using namespace std;

#define base 5

int rem[19];

int convert( long long N ){

    if( N== 0 )
        return 0;

    int i= 0;

    while( N > 0 ){
        rem[i]= N%5;
        N/= 5;
        ++i;
    }

    return i;
}

int main(){

    int T;
    long long N;

    cin >> T;

    while( T-- ){

        cin >> N;

        int n= convert( N-1 );

        if( n== 0 ){
            cout << 0 << endl;
            continue;
        }

        for( int i= n-1; i>= 0; --i )
            cout << 2*rem[i] ;

        cout << endl;
    }

    return 0;

}
