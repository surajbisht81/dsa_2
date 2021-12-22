#include <bits/stdc++.h>
using namespace std;
const int V= 5;
const int E =8;

void print(int dist[])
{
    cout<<"vertex     distance from src \n";
    for(int i=0; i<V; i++)
        cout<<i<<"\t\t"<<dist[i]<<endl;
}
void BellmenFord(int graph[][3], int src)
{
   int dist[V];
   for(int i=0; i<V; i++)
    dist[i]=INT_MAX;

   dist[src]=0;

   for(int i=0; i<V-1; i++)
   {
       for(int j=0; j<E; j++)
       {
           if(dist[graph[j][0]] + graph[j][2]<dist[graph[j][1]])
             dist[graph[j][1]]= dist[graph[j][0]]+graph[j][2];
       }
   }

   // checking for negative weight cycle in graph
   for(int i=0; i<E; i++)
   {
       int x = dist[graph[i][0]];
       int w = graph[i][2];
       int y = dist[graph[i][1]];
       if(x+w<y and x!=INT_MAX)
        cout<<"\ngraph contains negative weight cycle.";
   }
   print(dist);
}

int main()
{
   int graph[][3] = { {0,1,-1},{0,2,4},
                      {1,2,3},{1,3,2},
                      {1,4,2},{3,1,1},
                      {3,2,5},{4,3,-3}};
    BellmenFord(graph, 0);
    return 0;
}
