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
    bool isCyclicUtil(int u, bool visit[], bool recStack[]);
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

bool Graph::isCyclicUtil(int u, bool visit[], bool recStack[])
{
    if(!visit[u])
    {
        visit[u]=true;
        recStack[u]=true;

        for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
        {
            if(!visit[*it])
            {
                if(isCyclicUtil(*it, visit, recStack))
                    return true;
            }
            else if(recStack[*it])
                return true;
        }
    }
    return false;
}
bool Graph::isCyclic()
{
    bool *visit = new bool[V];
    bool *recStack = new bool[V];

    for(int i=0; i<V; i++)
    {
        visit[i]=false;
        recStack[i]=false;
    }

    for(int i=0; i<V; i++)
    {
        if(isCyclicUtil(i, visit, recStack))
            return true;
    }
    return false;
}
int main()
{
   Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
