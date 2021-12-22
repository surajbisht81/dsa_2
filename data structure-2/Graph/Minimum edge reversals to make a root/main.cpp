/*Given a directed tree with V vertices and V-1 edges, we need to choose such a root (from given nodes from where we can reach to every other node) with a
 minimum number of edge reversal.*/

#include <bits/stdc++.h>
using namespace std;

void addEdge(list<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int DFSUtil(list<int> adj2[], list<int> adj[], bool visited[],int v, int i)
{
    visited[i]=true;

    for( auto it=adj[i].begin(); it!=adj[i].end(); it++)
    {
        if(!visited[*it])
        {
            visited[*it]=true;
            adj2[i].push_back(*it);
            DFSUtil(adj2, adj, v, *it);
        }
    }
}

int DFSU(list<int> adj[], int v, int &count)
{
      list<int> *adj2 = new list<int>[v];
      int root;

      bool visited[v];
      memset(visited, false, sizeof(visited));

      for(int i=0;i<v;i++)
      {
             count = min(count, DFSUtil(adj2, adj, visited, v, i))
      }
}
int main()
{
    int v=8;
    list<int> *adj = new list<int>[v];
    addEdge(adj,0,1);
    addEdge(adj,0,1);
    addEdge(adj,0,1);
    addEdge(adj,0,1);
    addEdge(adj,0,1);
    addEdge(adj,0,1);
    addEdge(adj,0,1);

    int count=0;
    cout<<DFSUtil(adj, v, count);
    return 0;
}
