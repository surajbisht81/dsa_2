#include <iostream>

using namespace std;
const int v=9;

int minindex(bool sptSET[],int dist[])
{
    int min=INT_MAX,min_index;
    for(int i=0;i<v;i++)
    {
        if(!sptSET[i] && dist[i]<=min)
        {
            min=dist[i];
            min_index=i;
        }

    }
    return min_index;
}
void printdijkstra(int dist[])
{
    int i;
    cout<<"\nvertex  \t  distance from source\n";
    for(i=0;i<v;i++)
    {
        cout<<i<<"\t"<<  dist[i];
        cout<<endl;
    }
}
void dijkstra(int graph[v][v],int src)
{
    int dist[v];
    bool sptSET[v];
    int i;
    for( i=0;i<v;i++)
    {
        sptSET[i]=false;
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    for( i=0;i<v-1;i++)
    {
        int u=minindex(sptSET,dist);
        sptSET[u]=true;
        for(int j=0;j<v;j++)
        {
            if(!sptSET[j] && graph[u][j] && dist[u]!=INT_MAX && dist[u]+graph[u][j]<dist[j])
             {
              dist[j]=dist[u]+graph[u][j];
             }
         }
}
printdijkstra(dist);
}
int main()
{
    int graph[v][v]= { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);
    return 0;
}
