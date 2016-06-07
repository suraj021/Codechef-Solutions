#include <bits/stdc++.h>
using namespace std;

int main(){

    int T;
    string a, b;

    cin >> T;

    while( T-- ){

        cin >> a >> b;

        int n= (int)a.length();
        int i2o, o2i, o2o, i2i;
        i2o= o2i= o2o= i2i= 0;

        for( int i= 0; i< n; ++i ){

            if( a[i]== b[i] ){
                if( a[i]== '0' )
                    o2o++;
                else
                    i2i++;
            }else{
                if( a[i]== '0' )
                    o2i++;
                else
                    i2o++;
            }

        }

        bool flag= true;
        long ans= min( i2o, o2i );
        i2o-= ans;
        o2i-= ans;

        o2o+= ans;
        i2i+= ans;

        if( o2i ){
            if( i2i ){
                ans+= o2i;
            }else{
                flag= false;
            }
        }else{
            if( o2o ){
                ans+= i2o;
            }else{
                flag= false;
            }
        }

        if( flag ){
            cout << "Lucky Chef\n";
            cout << ans << '\n';
        }else{
            cout << "Unlucky Chef\n";
        }
    }

    return 0;
}
