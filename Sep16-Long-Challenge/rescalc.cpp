#include <bits/stdc++.h>
using namespace std;
 
int score[105];
int c[105];
int t[105][105];
 
int main(){
 
    int T, n;
 
    scanf( "%d", &T );
 
    while( T-- ){
 
        scanf( "%d", &n );
 
        memset( score, 0, sizeof score );
 
        int maxi= INT_MIN;
 
        for( int i= 1; i<= n; ++i ){
            scanf( "%d", &c[i] );
            for( int j= 1; j<= c[i]; ++j ){
                int x;
                scanf( "%d", &x );
                t[i][x]++;
            }
            score[i]= c[i];
 
            sort( t[i]+1, t[i]+7 );
        }
 
        /*
        for( int i= 1; i<= n; ++i ){
            for( int j= 1; j<= 6; ++j ){
                cout << t[i][j] << ' ';
            }
            cout << endl;
        } */
 
        for( int i= 1; i<= n; ++i ){
            score[i]+= ( 4*t[i][1] );
            t[i][2]-= t[i][1];
            t[i][3]-= t[i][1];
 
            if( t[i][2] > 0 ){
                score[i]+= 2*t[i][2];
                t[i][3]-= t[i][2];
            }
 
            if( t[i][3] > 0 ){
                score[i]+= t[i][3];
                //t[i][3]-= t[i][2];
            }
 
            if( score[i] > maxi )
                maxi= score[i];
        }
 
        int cnt= 0;
        int id;
 
        for( int i= 1; i<= n; ++i ){
            memset( t[i], 0, sizeof t[i] );
            //cout << score[i] << ' ';
            if( score[i] == maxi ){
                cnt++;
                id= i;
            }
 
        }
 
        if( cnt >= 2 )
            printf( "tie\n" );
        else if( cnt== 1 && id== 1 )
            printf( "chef\n" );
        else
            printf( "%d\n", id );
 
 
    }
 
    return 0;
}