#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector< lli > fib;

void generate(){

	fib[1]= 1;
	fib[2]= 2;
	fib[3]= 3;

	for( int i= 4; i< 92; ++i ){
		fib[i]= fib[i-1]+fib[i-2];
		//cout << fib[i] << " ";
	}

	//cout << endl << fib[91] << endl;;

}

int main(){

	fib.resize( 93, 0 );

	generate();

	int T;
	lli N;

	scanf( "%d", &T );

	while( T-- ){

		scanf( "%lld", &N );

		if( N <= 3 ){
			printf("%lld\n", N );
			continue;
		}

		int i= lower_bound( fib.begin(), fib.end(), N ) - fib.begin();

		//cout << i << " ";

		if( fib[i]== N )
			printf("%d\n", i );
		else
			printf("%d\n", i-1 );

	}

}