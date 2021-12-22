#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int>adj[])
{
    adj[u].push_back(v);
}

void printLevles(int V, vector<int> adj[])
{
    int level[V]={0};
    bool visit[V];
    memset(visit, false, sizeof(visit));

    level[0]=0;
    queue<int> qu;
    qu.push(0);

    while(!qu.empty())
    {
        int i = qu.front();
        qu.pop();

        for(auto it=adj[i].begin(); it!=adj[i].end(); it++)
        {
           if(visit[*it]==false)
           {
               level[*it]=level[i]+1;
               qu.push(*it);
               visit[*it]=true;
           }
        }
    }

    for(int i=0;i<V;i++)
        cout<<i<<"->"<<level[i]<<endl;
}

int main()
{
    int V=8;
    vector<int> adj[V];
    addEdge(0, 1, adj);
    addEdge(0, 2, adj);
    addEdge(1, 3, adj);
    addEdge(1, 4, adj);
    addEdge(1, 5, adj);
    addEdge(2, 6, adj);
    addEdge(6, 7, adj);

    printLevles(V, adj);
    return 0;
}
