#include <bits/stdc++.h>

using namespace std;

int arr[200005];

inline int inp()
{
    register int r=0,c;
    for(c=getchar_unlocked(); c<=32; c=getchar_unlocked());
    if(c=='-')
        return -inp();
    for(; c>32; r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());
    return r;
}

int main(){

	int T;
	int N, M, x;

	scanf( "%d", &T );

	while( T-- ){

		N= inp();
		M= inp();

		for( int i= 0; i< M; ++i ){
			arr[i]= inp();
		}

		if( M== N ){
			printf("%d\n", M/2 );
			continue;
		}

		if( M== 1 ){
			printf("0\n");
			continue;
		}

		sort( arr, arr+M );

		long count= 0;
		int i= 0, j= M-1;

		while( M > 1 ){

			while( arr[i] && M > 1 ){

				if( arr[i]== 1 ){
					M-= 2;
				}else{
					M-= 1;
				}

				++count;
				--arr[i];
			}

			++i;
		}
		

		printf( "%ld\n", count );

	}

}