/*Given a graph where every edge has weight as either 0 or 1. A source vertex is also given in the graph. Find the shortest path from source vertex 
to every other vertex.
*/

#include <bits/stdc++.h>
using namespace std;
#define V 9
list<pair<int, int>> adj[V];

void addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void ZeroOneBFS(int src)
{
    queue<pair<int, int>> qu;

    qu.push(make_pair(0, src));
    int dist[V];
    for(int i=0; i<V; i++)
        dist[i]=INT_MAX;
    dist[src]=0;

    while(!qu.empty())
    {
        pair<int, int> p=qu.front();
        qu.pop();

        int tmp=p.second;

        for(auto child:adj[tmp])
        {
            int v=child.first;
            int w=child.second;

            if(dist[v]>dist[tmp]+w)
            {
                dist[v]=dist[tmp]+w;
                qu.push(make_pair(dist[v], v));
            }
        }
    }
    for(int i=0; i<V; i++)
        cout<<dist[i]<<" ";
}

int main()
{
    addEdge(0, 1, 0);
    addEdge(0, 7, 1);
    addEdge(1, 7, 1);
    addEdge(1, 2, 1);
    addEdge(2, 3, 0);
    addEdge(2, 5, 0);
    addEdge(2, 8, 1);
    addEdge(3, 4, 1);
    addEdge(3, 5, 1);
    addEdge(4, 5, 1);
    addEdge(5, 6, 1);
    addEdge(6, 7, 1);
    addEdge(7, 8, 1);

    ZeroOneBFS(0);
    return 0;
}
