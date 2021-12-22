#include <bits/stdc++.h>
using namespace std;
#define V 4
#define INF INT_MAX

// using recursion
/*int ShortestPathSum(int graph[][V], int u, int v, int k)
{
    if(k==0 and u==v)
        return 0;
    if(k==1 and graph[u][v]!=INF)
        return graph[u][v];

    if(k<=0)
        return INF;

    int res=INF;
    for(int i=0; i<V; i++)
    {
        if(graph[u][i]!=INF and u!=i and v!=i)
        {
            int rec_res = ShortestPathSum(graph, i, v, k-1);
            res = min(res, rec_res+graph[u][i]);
        }
    }
    return res;
}

int main()
{
     int graph[V][V] = { {0, 10, 3, 2},
                        {INF, 0, INF, 7},
                        {INF, INF, 0, 6},
                        {INF, INF, INF, 0}
                       };

     int u=0, v=3, k=2;
     cout<<ShortestPathSum(graph, u, v, k);
     return 0;
}
*/


// using dynamic programing
int ShortestPathSum(int graph[][V], int u, int v, int k)
{
     int sp[V][V][k+1];

     for(int e=0; e<=k; e++)
     {
         for(int i=0; i<V; i++)
         {
             for(int j=0; j<V; j++)
             {
                 sp[i][j][e]=INF;

                 if(e==0 and i==j)
                    sp[i][j][e]=0;
                 if(e==1 and graph[i][j]!=INF)
                    sp[i][j][e]=graph[i][j];

                 if(e>1)
                 {
                     for(int a=0; a<V; a++)
                     {
                         if(graph[i][a]!=INF and i!=a and j!=a and sp[a][j][e-1]!=INF)
                            sp[i][j][e]=min(sp[i][j][e], graph[i][a]+sp[a][j][e-1]);
                     }
                 }
             }
         }
     }
     return sp[u][v][k];
}

int main()
{
     int graph[V][V] = { {0, 10, 3, 2},
                        {INF, 0, INF, 7},
                        {INF, INF, 0, 6},
                        {INF, INF, INF, 0}
                       };

     int u=0, v=3, k=2;
     cout<<ShortestPathSum(graph, u, v, k);
     return 0;
}
