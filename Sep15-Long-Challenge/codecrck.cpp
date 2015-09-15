// I used cin/cout for I/O and got wrong ans every time use C's I/O functions

#include <bits/stdc++.h>

using namespace std;

#define ll long long 

double powerlogn(double a, long long b){

	double result;
	result = 1;
	while (b > 0)
	{
		if (b & 1)
			result *= a;
		b >>= 1;
		a *= a;
	}
	return result;
} 

int main(){

	double a_i, b_i;
	long long i, k, s;

	scanf( "%lld%lld%lld", &i, &k, &s );
	scanf( "%lf%lf", &a_i, &b_i );

	long x= k-i;

	if( (x)%2== 0 ){

		long long p= 2*(k-i)-s;

		if( p > 0 )
			printf( "%lf\n", ( a_i + b_i )*powerlogn( 2.0, p ) );
		else
			printf( "%lf\n", ( a_i + b_i )/powerlogn( 2.0, -p ) );
	}else{

		double sqrt2= sqrt( 2 );
		double sqrt3= sqrt( 3 );

		//cout << sqrt2 << " " << sqrt3 << endl;

		long long p= 2*(k-i)-s-1;

		if( p > 0 )
			printf( "%lf\n", sqrt2*( a_i + b_i*sqrt3 )*powerlogn( 2.0, p ) );
		else
			printf( "%lf\n", sqrt2*( a_i + b_i*sqrt3 )/powerlogn( 2.0, -p ) );

	}



}
