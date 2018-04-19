#include <bits/stdc++.h>
using namespace std;

int c[1003];

int main(){

	int N, t;
	long mint1, mint2, mint3;

	mint3= mint2= mint1= 1000000;

	cin >> N;

	for( int i= 0; i< N; ++i )
		cin >> c[i];

	for( int i= 0; i< N; ++i ){
		int t;
		cin >> t;

		if( t== 1 ){
			if( c[i] < mint1 )
				mint1= c[i];
		}else if( t== 2 ){
			if( c[i] < mint2 )
				mint2= c[i];
		}else{
			if( c[i] < mint3 )
				mint3= c[i];
		}
	}

	cout << min( mint3, min( mint3 + mint1, min( mint1 + mint2, mint2 + mint3 ) ) ) << endl;
}