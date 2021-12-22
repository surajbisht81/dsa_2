#include <iostream>

using namespace std;
const int V=5;
const int E=8;
void printdistance(int dist[])
{
    cout<<"\nvertex  \tdistance from source:\n";
    for(int i=0;i<V;i++)
    {
        cout<<i<<"\t\t"<<dist[i];
        cout<<endl;
    }
}

void bellmenford(int graph[][3],int src)
{
    int dist[V];
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[src]=0;

    for(int i=0;i<V-1;i++)
    {
        for(int j=0;j<E;j++)
        {
            if(dist[graph[j][0]]+graph[j][2]<dist[graph[j][1]])
                dist[graph[j][1]]=dist[graph[j][0]]+graph[j][2];
        }
    }
    //checking for negative cycle in bellmen's ford algorithm;

    for(int i=0;i<E;i++)
    {
        int x=dist[graph[i][0]];
        int y=dist[graph[i][1]];
        int w=graph[i][2];
        if(x+w<y&& x!=INT_MAX)
        {
            cout<<"\ngraph contains -ve cycle\n";
        }
    }

    printdistance(dist);
}
int main()
{
    int graph[][3]={ {0,1,-1},{0,2,4},
                      {1,2,3},{1,3,2},
                      {1,4,2},{3,1,1},
                      {3,2,5},{4,3,-3}};
    bellmenford(graph,0);
    return 0;
}
