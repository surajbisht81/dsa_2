#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    int V;
    list<int>*adj;

    Graph(int v);
    void addEdge(int v, int u);
    bool isCyclic();
    bool isCyclicUtil(int u, bool visit[], int parent);
};

Graph::Graph(int v)
{
    V=v;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool Graph::isCyclicUtil(int u, bool visit[], int parent)
{
    visit[u]=true;

    for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
    {
        if(!visit[*it])
          {
             if(isCyclicUtil(*it, visit, u));
             return true;
          }
        else if(*it!=parent)
         return true;
    }
    return false;
}
bool Graph::isCyclic()
{
    bool *visit = new bool[V];
    for(int i=0; i<V; i++)
        visit[i]=false;

    for(int i=0; i<V; i++)
    {
        if(!visit[i])
        {
            if(isCyclicUtil(i, visit, -1))
                return true;
        }
    }
    return false;
}
int main()
{
     Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";

  return 0;
}
