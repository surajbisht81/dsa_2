#include <bits/stdc++.h>
using namespace std;
#define V 8
list<int> *adj;

void add_edge(list<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int ShortestPath(list<int> adj[], int src, int dst)
{
    queue<int> qu;
    qu.push(src);

    bool visit[V];
    memset(visit, false, sizeof(visit));
    visit[src]=true;

    int dist[V];
    dist[src]=0;

    while(!qu.empty())
    {
        int p=qu.front();
        qu.pop();

        for(auto it=adj[p].begin(); it!=adj[p].end(); it++)
        {
            if(!visit[*it])
            {
                visit[*it]=true;
                qu.push(*it);
                dist[*it]=dist[p]+1;
            }
        }
    }
    return dist[dst];
}

int main()
{
    adj = new list<int>[V];

    add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);
    int source = 0, dest = 7;

    cout<<"Shortest path is:"<<ShortestPath(adj, source, dest);
    return 0;
}
