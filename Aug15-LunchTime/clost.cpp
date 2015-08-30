#include <bits/stdc++.h>

using namespace std;

std::vector<char> arr;

int main(){

	int T, N, K;
	int x, y;

	scanf( "%d", &T );

	while( T-- ){

		scanf( "%d%d", &N, &K );

		arr.resize( N );

		while( K-- ){

			scanf( "%d%d", &x, &y );

			for( int i= x; i<=y; i+= 2 ){
				arr[i]= '(';
				arr[i+1]= ')';
			}

		}

		char last_used= ' ';
		bool first= true;

		for( int i= 0; i< N; ++i ){

			if( first && arr[i]!= '(' && arr[i]!= ')' ){
				arr[i]= '(';
				last_used= '(';
				first= false ;
				continue;
			}


			if( last_used== ')' && arr[i]!= '(' && arr[i]!= ')' ){
				arr[i]= '(';
				last_used= '(';
			}
			else if ( last_used== '(' && arr[i]!= '(' && arr[i]!= ')' ){
				arr[i]= ')';
				last_used= ')';
			}

		}

		string ans( arr.begin(), arr.end() );
		cout << ans << endl;
		arr.clear();
	}

}