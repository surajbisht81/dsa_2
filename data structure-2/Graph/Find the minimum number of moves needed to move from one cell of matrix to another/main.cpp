#include <bits/stdc++.h>
using namespace std;
#define N 4

class Graph
{
    int V ;
    list < int > *adj;
public :
    Graph( int V )
    {
        this->V = V ;
        adj = new list<int>[V];
    }
    void addEdge( int s , int d ) ;
    int BFS ( int s , int d) ;
};
void Graph::addEdge( int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}
bool isSafe(int x, int y, int M[][N])
{
    if ((x < 0 || x >= N) ||
            (y < 0 || y >= N ) || M[x][y] == 0)
        return false;
    return true;
}

int Graph:: BFS( int src, int dst)
{
    int n= N*N+2;
    int *level = new int[n];
    for(int i=0; i<n; i++)
    {
        level[i]=-1;
    }

    queue<int> qu;
    qu.push(src);
    level[src]=0;

    list<int> :: iterator it;
    while(!qu.empty())
    {
        int p = qu.front();
        qu.pop();

        for(it=adj[p].begin(); it!=adj[p].end(); it++)
        {
            if(level[*it]<0 or level[*it]>level[p]+1)
            {
                level[*it]=level[p]+1;
                qu.push(*it);
            }
        }
    }
    return level[dst];
}
int countminPath(int M[][N])
{
    int V=N*N+2;
    Graph g(V);

    int src, dst;
    int k=1;

    for(int i=0; i<N; i++)
    {
      for(int j=0; j<N; j++)
      {
          if(M[i][j]!=0)
          { if(isSafe(i, j+1, M))
             g.addEdge(k, k+1);
            if(isSafe(i, j-1, M))
             g.addEdge( k, k-1);
            if(isSafe(i-1, j, M))
             g.addEdge(k, k-N);
            if(isSafe(i+1, j, M))
             g.addEdge(k, k+N);
          }
            if(M[i][j]==1)
             src = k;
            if(M[i][j]==2)
             dst = k;
          k++;
      }
    }
   return g.BFS( src, dst);
}

int main()
{
     int M[N][N] = {{ 3 , 3 , 1 , 0 },
        { 3 , 0 , 3 , 3 },
        { 2 , 3 , 0 , 3 },
        { 0 , 3 , 3 , 3 }
    };
    cout<<countminPath(M);
    return 0;
}
