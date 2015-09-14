#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

vector< pair< int, int > > coordi;

int main(){

	int T, N;

	scanf( "%d", &T );

	while( T-- ){

		scanf( "%d", &N );
		int x;

		coordi.resize( N*N+2 );

		for( int i= 1; i<= N; ++i )
			for( int j= 1; j<= N; ++j ){
				cin >> x;
				coordi[x]= { i, j };
			}

		long dist= 0;

		for( int i= 2; i<= N*N; ++i )
			dist+= abs( coordi[i].ff - coordi[i-1].ff ) + abs( coordi[i].ss - coordi[i-1].ss );

		printf( "%ld\n", dist );
		coordi.clear();
	}

}