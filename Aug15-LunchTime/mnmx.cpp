#include <bits/stdc++.h>

using namespace std;

int arr[50005];

int main(){

	int T, N;

	scanf( "%d", &T );

	while( T-- ){

		scanf( "%d", &N );
		int min= INT_MAX;

		for( int i= 0; i< N; ++i ){
			scanf( "%d", &arr[i] );
			if( min > arr[i] )
				min= arr[i];
		}

		printf("%lld\n", 1LL*min*(N-1) );

	}
}