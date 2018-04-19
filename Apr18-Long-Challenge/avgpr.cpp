#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

unordered_map< int, int > m;
int odd[1003];
int even[1003];

int main(){

	int T, N;

	scanf( "%d", &T );

	while( T-- ){

		scanf( "%d", &N );

		for( int i= 0; i< N; ++i ){
			int x;
			scanf( "%d", &x );

			m[x]++;
		}

		int i, j;
		i= j= 0;

		long long ans= 0;

		for( auto it= m.begin(); it!= m.end(); ++it ){
			int key= it->ff;

			if( key%2== 0 ){
				even[i]= key;
				i++;
			}else{
				odd[j]= key;
				j++;
			}

			ans+= 1ll*(it->ss)*(it->ss-1)/2;
		}

		int n_even= i;
		int n_odd= j;

		for( int i= 0; i< n_even; ++i ){
			//ans+= m[even[i]] - 1;
			for( int j= i+1; j< n_even; ++j ){
				int avg= ( even[i] + even[j] )/2;

				if( m[avg]!= 0 ){
					ans+= 1ll*( m[even[i]]*m[even[j]] );
				}
			}
		}

		for( int i= 0; i< n_odd; ++i ){
			//ans+= m[odd[i]] - 1;
			for( int j= i+1; j< n_odd; ++j ){
				int avg= ( odd[i] + odd[j] )/2;

				if( m[avg]!= 0 ){
					ans+= 1ll*( m[odd[i]]*m[odd[j]] );
				}
			}
		}

		cout << ans << endl;

		m.clear();

	}

}