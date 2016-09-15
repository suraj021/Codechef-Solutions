#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    int t;
    string s;
 
    cin >> t;
 
    while( t-- ){
        cin >> s;
 
        int n= (int)s.length();
 
        bool is= true;
 
        for( int i= 0; i< n/2; ++i ){
 
            if( s[i]== s[n-i-1] && s[i]!= '.' )
                continue;
 
            if( s[i]!= '.' && s[n-i-1]!= '.' && s[i] != s[n-i-1] ){
                is= false;
                break;
            }
 
            if( s[i]== '.' && s[n-i-1]!= '.' ){
                s[i]= s[n-i-1];
            }else if( s[n-i-1]== '.' && s[i]!= '.' ){
                s[n-i-1]= s[i];
            }else{
                s[i]= s[n-i-1]= 'a';
            }
 
        }
 
        if( n%2!= 0 && s[n/2]== '.' )
            s[n/2]= 'a';
 
        if( is )
            cout << s << endl;
        else
            cout << -1 << endl;
 
    }
 
}