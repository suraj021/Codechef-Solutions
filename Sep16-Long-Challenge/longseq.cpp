#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    int t;
    string s;
 
    cin >> t;
 
    while( t-- ){
        cin >> s;
 
        int z, o;
        z= o= 0;
 
        for( int i= 0; i< (int)s.length(); ++i ){
            if( s[i]== '0' )
                z++;
            else
                o++;
        }
 
        if( z== 1 || o== 1 )
            cout << "Yes\n";
        else
            cout << "No\n";
    }
 
}
