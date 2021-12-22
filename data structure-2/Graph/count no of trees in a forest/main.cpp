#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[])
{
    adj[u].push_back(v);
}

void DFS(vector<int>adj[], bool visit[], int i)
{
    visit[i]=true;

    for(auto it=adj[i].begin(); it!=adj[i].end(); it++)
    {
        if(visit[*it]==false)
            DFS(adj, visit, *it);
    }
}

int countTrees(vector<int>adj[], int V)
{
    bool visit[V];
    memset(visit, false, sizeof(visit));

    int trees=0;
    for(int i=0; i<V; i++)
    {
        if(visit[i]==false)
        {
            DFS(adj, visit, i);
            trees++;
        }
    }
    return trees;
}
int main()
{
    int V=5;
    vector<int> adj[V];
    addEdge(0, 1, adj);
    addEdge(0, 2, adj);
    addEdge(3, 4, adj);

    cout<<"\n no of trees are : "<<countTrees(adj, V);
    return 0;
}
