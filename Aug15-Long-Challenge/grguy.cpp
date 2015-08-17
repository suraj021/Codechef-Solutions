#include <bits/stdc++.h>

using namespace std;

int main(){

	vector< string > maze;
	maze.resize( 2, "" );

	int T;

	scanf( "%d", &T );

	while( T-- ){

		cin >> maze[0];
		cin >> maze[1];

		long count1= 0;
		long count2= 0;

		bool flagA, flagB;
		flagB= flagA= false;

		long len= (int)maze[0].length();

		if( maze[0][0]== '#' && maze[1][0]== '#' ){
			printf("No\n");
			continue;
		}

		if( maze[0][len-1]== '#' && maze[1][len-1]== '#' ){
			printf("No\n");
			continue;
		}

		if( maze[0][0]== '.' ){

			int i= 0;
			int j= 0;

			while( j != len-1 ){

				if( maze[i][j+1]== '.' ){
					j++;
					continue;
				}

				if( maze[1-i][j+1]== '.' ){
					i= 1-i;
					count1++;
					continue;
				}

				break;
			}

			if( j== len-1 )
				flagA= true;
		}

		if( maze[1][0]== '.' ){

			int i= 1;
			int j= 0;

			while( j != len-1 ){

				if( maze[i][j+1]== '.' ){
					j++;
					continue;
				}

				if( maze[1-i][j+1]== '.' ){
					i= 1-i;
					count2++;
					continue;
				}

				break;
			}

			if( j== len-1 )
				flagB= true;
		}

		if( flagB && flagA ){
			printf("Yes\n%ld\n", min( count2, count1 ) );
			continue;
		}

		if( flagA ){
			printf("Yes\n%ld\n", count1 );
			continue;
		}

		if( flagB ){
			printf("Yes\n%ld\n", count2 );
			continue;
		}

		if( !flagA && !flagB )
			printf("No\n");
	}


}