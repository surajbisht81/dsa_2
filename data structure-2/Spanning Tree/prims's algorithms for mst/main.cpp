#include <bits/stdc++.h>
using namespace std;
#define V 5
#define INF INT_MAX

int minSet(int key[], bool mstSet[])
{
       int min_index,minn=INT_MAX;
       for(int i=0; i<V; i++)
       {
           if(minn>key[i] and mstSet[i]==false)
            minn=key[i], min_index=i;
       }
       return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    cout<<" Edges \t Weigh\n";
    for(int i=1; i<V; i++)
    {
        cout<<parent[i]<<" "<<i<<"\t"<<graph[parent[i]][i]<<endl;
    }
}
void Prims(int graph[V][V])
{
    bool mstSet[V];
    int parent[V];
    int key[V];

    for(int i=0; i<V; i++)
        key[i]=INF, mstSet[i]=false;

    key[0]=0, parent[0]=-1;

    for(int i=0; i<V-1; i++)
    {
       int u=minSet(key, mstSet);
       mstSet[u]=true;

       for(int v=0; v<V; v++)
       {
           if(graph[u][v] and mstSet[v]==false and key[v]> graph[u][v])
             key[v]=graph[u][v], parent[v]=u;
       }
    }
    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    Prims(graph);
    return 0;
}
