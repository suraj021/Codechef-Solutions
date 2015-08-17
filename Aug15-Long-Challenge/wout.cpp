/*  Author: Suraj Bora
	Lang: C++

	Note: Be aware of long long

*/

#include <bits/stdc++.h>

using namespace std;

inline void scanint(int* x)
{
	register char c = getchar_unlocked();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar_unlocked());
	for(; (c>47)&&(c<58);c = getchar_unlocked())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}

int start[1000006];
int finish[1000006];
int row[1000006];

int main(){

	int T, N, H;
	int l, h;

	scanf( "%d", &T );

	while( T-- ){
		
		scanf( "%d%d", &N, &H );

		for( int i= 0; i< N; ++i ){
			start[i]= 0;
			finish[i]= 0;
			row[i]= 0;
		}

		for( int i= 0; i< N; ++i ){

			scanint( &l );
			scanint( &h );

			start[l]++;
			finish[h]++;

		}

		int l= 0;

		for( int i= 0; i< N; ++i ){

			l+= start[i];
			row[i]= l;
			l-= finish[i];
		}


		long long max_sum= 0;

		//for( int i= 0; i< N; ++i )
		//	cout << row[i] << " ";

		//cout << finishl;

		for( int i= 0; i< H; ++i ){
			max_sum+= (long long) row[i];
		}

		long long sum= (long long)max_sum;

		for( int i= H; i< N; ++i ){

			int add_index= i;
			int sub_index= i - H;

			sum+= row[add_index] - row[sub_index];

			max_sum= max( max_sum, sum );

		}

		//cout << max_sum << finishl;

		printf("%lld\n", 1LL*((long long )N*H - (long long)max_sum) );
	}

}