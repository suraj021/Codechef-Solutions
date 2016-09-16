#include <bits/stdc++.h>
using namespace std;

bool graph[1003][1003];     // actual graph
vector< int > g[1003];      // complement graph
int color[1003];

int in(){

    int cc = getc(stdin);
    for (;cc < '0' || cc > '9';)
            cc = getc(stdin);
    int ret = 0;
    for (;cc >= '0' && cc <= '9';)
    {
            ret = ret * 10 + cc - '0';
            cc = getc(stdin);
    }
    return ret;
}

bool bipartite( int s ){

    color[s]= 1;
    queue< int > q;
    q.push( s );

    while( !q.empty() ){

        int u= q.front();
        q.pop();

        for( int i= 0; i< g[u].size(); ++i ){
            int v= g[u][i];

            if( color[v]== -1 ){
                color[v]= 1 - color[u];
                q.push( v );
            }
            else if( color[u]== color[v] )
                return false;
        }
    }

    return true;
}

int main(){

    int T, N, M;

    T= in();

    memset(color,-1,sizeof color);

    while( T-- ){

        N= in();
        M= in();

        for( int i= 0; i< M; ++i ){
            int u, v;
            u= in(); v= in();

            if( u!= v ){
                graph[u][v]= 1;
                graph[v][u]= 1;
            }
        }

        // make complementary graph (g) and actual graph (gg)
        for( int i= 1; i<= N; ++i ){
            for( int j= i+1; j<= N; ++j ){
                if( !graph[i][j] ){
                    g[i].push_back( j );
                    g[j].push_back( i );
                }
            }
        }

        // find connected components of the given graph

        bool flag=true;

        for( int i= 1; i<= N; ++i ){
            if( color[i]==-1 ){

              bool ret=  bipartite(i);

              if(ret==false)
               {
                 flag=false;
                 break;
               }
            }
        }



        if( flag )
            printf( "YES\n" );
        else
            printf( "NO\n" );


        for( int i= 0; i<= N; ++i ){
            color[i]= -1;
            g[i].clear();
            memset( graph[i], 0, sizeof graph[i] );
        }

    }

}
