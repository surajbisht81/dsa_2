#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *adj;

    Graph(int v);
    void addEdge(int u, int v);
    int DFS(int src, int dst);
    void DFSUtil(int v,int dst, int &path);
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

void Graph::DFSUtil(int v, int dst, int &path)
{

    for(auto it=adj[v].begin(); it!=adj[v].end(); it++)
    {
            if(dst==*it)
                path++;
            else
                DFSUtil(*it, dst, path);

    }
}

int Graph::DFS(int src, int dst)
{
    int path=0;
    for(auto it=adj[src].begin(); it!=adj[src].end(); it++)
    {
        if(dst==*it)
            path++;
        else
            DFSUtil(*it, dst, path);
    }
    return path;
}
int main()
{
     Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(1, 4);
    g.addEdge(4, 3);

    int s = 0, d = 2;

    cout<<"\n no of paths blw src and dst are :"<<g.DFS(s, d);
    return 0;
}
