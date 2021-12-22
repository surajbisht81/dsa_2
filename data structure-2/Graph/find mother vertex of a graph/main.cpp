#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *adj;

    Graph(int v);
    void addEdge(int u, int v);
    void DFSUtil(int v, vector<bool>&visited);
    int findMother();
};
Graph::Graph(int v)
{
    V=v;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::DFSUtil(int v, vector<bool>&visited)
{
    visited[v]=true;

    for(auto it=adj[v].begin(); it!=adj[v].end(); it++)
    {
        if(!visited[*it])
            DFSUtil(*it, visited);
    }
}
int Graph::findMother()
{
    vector<bool> visited(V, false);

    int v=0;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
          {
              DFSUtil(i, visited);
              v=i;
          }
    }

    fill(visited.begin(), visited.end(), false);

    DFSUtil(v, visited);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            return -1;
    }
    return v;
}
int main()
{
  Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);

    cout<<"\nmother vertex of graph is :"<<g.findMother();
    return 0;
}
