#include <bits/stdc++.h>
using namespace std;

int val[1005];

int main(){
	
	int T;
	long long n;
	string s;

	cin >> T;

	while( T-- ){

		cin >> s >> n;

		int len= s.length();

		int d= 0;
		int a= 0;

		for( int i= 0; i< len; ++i ){
			if( s[i]== 'a' )
				a++;
			else
				a--;
		}

		d= a;

		if( d== 0 ){
			int cc= 0;
			a= 0;
			for( int i= 0; i< len; ++i ){
				if( s[i]== 'a' )
					a++;
				else
					a--;

				if( a > 0 )
					cc++;
			}

			//    << "here";

			cout << 1ll*cc*n << endl;

			continue;
		}

		long long ans= 0ll;

		if( d > 0 ){
			a= 0;
			for( int i= 0; i< len; ++i ){
				if( s[i]== 'a' )
					a++;
				else
					a--;

				if( a== 0 )
					ans+= 1ll*(n-1);
				else if( a > 0 ){
					ans+= 1ll*n;
				}else{
					int x= (-a)/d + 1;
					if( x > n )
						x= n;
					ans+= 1ll*( n-x );
					//    << i << ' ' << (n-x) << endl;
				}
			}
		}else{
			a= 0;
			for( int i= 0; i< len; ++i ){
				if( s[i]== 'a' )
					a++;
				else
					a--;

				if( a > 0 ){
					int x= (-a)/d + 1;
					if( a%d== 0 )
						x--;
					if( x > n )
						x= n;
					//    << i << ' ' << x << endl;
					ans+= 1ll*x;
				}
			}
		}

		    << 1ll*ans << endl;

	}

}