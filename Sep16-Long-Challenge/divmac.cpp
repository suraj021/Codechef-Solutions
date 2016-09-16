#include <bits/stdc++.h>
using namespace std;

#define N 1000006

bitset<N> b;
vector< int > p;
int lpd[N];
int a[100005];
int st[4*100005];

int readint(){

    int cc = getc(stdin);
    for (;cc < '0' || cc > '9';)
            cc = getc(stdin);
    int ret = 0;
    for (;cc >= '0' && cc <= '9';)
    {
            ret = ret * 10 + cc - '0';
            cc = getc(stdin);
    }
    return ret;
}

void primeGen(){

    b.set();

    b[0]= b[1]= false;

    for( int i= 2; i*i < N; ++i ){
        if( b[i] ){
            for( int j= i*i; j< N; j+= i )
                b[j]= false;
        }
    }

}

int getLpd( int x ){

    if( !( x&1 ) ){
        return 2;
    }

    for( int i= 0; i< (int)p.size(); ++i ){
        if( x%p[i]== 0 )
            return p[i];
        else if( x < p[i] )
            return 1;
    }

}

void lpdGen(){

    memset( lpd, 1, sizeof lpd );

    lpd[0]= lpd[1]= 0;

    p.push_back( 2 );

    for( int i= 2; i< N; i+= 2 ){
        lpd[i]= 2;
    }

    for( int i= 3; i< N; i+= 2 ){
        if( b[i] ){
            lpd[i]=i;
            p.push_back( i );
        }
        else
            lpd[i]= getLpd( i );
    }

}

void build( long id, long l, long r ){

    if( l== r ){
        if( lpd[a[l]]== 0 ){
            st[id]= a[l];
        }else{
            st[id]= lpd[a[l]];
        }
        return ;
    }

    long mid= (l+r)>>1;

    build( 2*id, l, mid );
    build( 2*id+1, mid+1, r );

    st[id]= max( st[2*id], st[2*id+1] );
}

void update( long id, long l, long r, long x, long y ){

    if( l > r || x > r || y < l )
        return ;

    if( st[id]== 1 )
        return;

    if( l== r ){

        if( lpd[a[l]]== 0 ){
            st[id]= 1;
            a[l]= 1;
        }else{
            a[l]= a[l]/lpd[a[l]];
            st[id]= lpd[a[l]];
        }

        return;
    }

    long mid= l + ( r-l )/2;

    update( 2*id, l, mid, x, y );
    update( 2*id+1, mid+1, r, x, y );

    st[id]= max( st[2*id], st[2*id+1] );

}

long query( long id, long l, long r, long x, long y ){

    if( l > r || x > r || y < l )
        return 1;

    if( x <= l && y >= r )
        return st[id];

    long mid= l + ( r-l )/2;

    return max( query( 2*id, l, mid, x, y ), query( 2*id+1, mid+1, r, x, y ) );


}

int main(){

    primeGen();
    lpdGen();

    long T, t, n, q, x, y;

    T= readint();

    while( T-- ){

        n= readint();
        q= readint();

        for( long i= 0; i< n; ++i ){
            a[i]= readint();
        }

        build( 1, 0, n-1 );

        while( q-- ){

            t= readint();
            x= readint();
            y= readint();
            //scanf( "%d%d%d", &t, &x, &y );
            x--, y--;

            if( t== 0 ){
                update( 1, 0, n-1, x, y );
                //for( long i= 0; i< n; ++i )
                  //  cout << a[i]  << ' ';
                //cout << endl;
            }else
                printf( "%d\n", query( 1, 0, n-1 , x , y ) );

        }

        printf( "\n" );
    }

}
