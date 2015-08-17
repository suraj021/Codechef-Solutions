#include <bits/stdc++.h>

using namespace std;

bool isNotPower( long n ){
	return n & (n-1);
}

int main(){

	int T;
	long int A, B;

	scanf( "%d", &T );

	while( T-- ){

		scanf( "%ld%ld", &A, &B );

		long count= 0;

		while( true ){

			if( !isNotPower( A ) )
				break;

			count++;

			A= A/2;
		}

		if( A < B ){

			while( A!= B ){
				A<<= 1;
				count++;
			}

		}else if ( A > B ){

			while( A!= B ){
				B<<= 1;
				count++;
			}
		}

		printf("%ld\n", count );
	}

}