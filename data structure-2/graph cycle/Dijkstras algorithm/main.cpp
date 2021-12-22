#include <bits/stdc++.h>
using namespace std;
#define V 9

int minDist(int dist[V], bool sptSet[V])
{
    int minn=INT_MAX, min_idx;

    for(int i=0; i<V; i++)
    {
        if(sptSet[i]==false and dist[i]<minn)
            minn=dist[i], min_idx=i;
    }
    return min_idx;
}

void print(int dist[])
{
    cout<<"Vertex"<<"   "<<"Distance from src"<<endl;
    for(int i=0; i<V; i++)
    {
        cout<<i<<"          "<<dist[i]<<endl;
    }
}
void Dijkstras(int graph[][V], int src)
{
    int dist[V];
    bool sptSet[V];

    for(int i=0; i<V; i++)
    {
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }

    dist[src]=0;

    for(int i=0; i<V-1; i++)
    {
       int u = minDist(dist, sptSet);

       sptSet[u]=true;

       for(int j=0; j<V; j++)
       {
           if(!sptSet[j] and graph[u][j] and dist[u]!=INT_MAX and dist[u]+graph[u][j]<dist[j])
            dist[j]=dist[u]+graph[u][j];
       }
    }
   print(dist);
}

int main()
{
     int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    Dijkstras(graph, 0);
    return 0;
}
