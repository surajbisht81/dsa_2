#include <bits/stdc++.h>
using namespace std;
#define V 8
#define INF INT_MAX

int ShortestPath(int graph[][V], int src, int dst)
{
  int dist[V];

  dist[dst]=0;

  for(int i=V-2; i>=0; i--)
  {
      dist[i]=INF;

      for(int j=0; j<V; j++)
      {
          if(graph[i][j]!=INF)
              dist[i]=min(dist[i], graph[i][j]+dist[j]);
      }
  }
  return dist[0];
}

int main()
{
    int graph[V][V] =
      {{INF, 1, 2, 5, INF, INF, INF, INF},
       {INF, INF, INF, INF, 4, 11, INF, INF},
       {INF, INF, INF, INF, 9, 5, 16, INF},
       {INF, INF, INF, INF, INF, INF, 2, INF},
       {INF, INF, INF, INF, INF, INF, INF, 18},
       {INF, INF, INF, INF, INF, INF, INF, 13},
       {INF, INF, INF, INF, INF, INF, INF, 2}};
    int src=0, dst=7;
    cout<<"\nShortest Path is: "<<ShortestPath(graph, src, dst);
    return 0;
}
