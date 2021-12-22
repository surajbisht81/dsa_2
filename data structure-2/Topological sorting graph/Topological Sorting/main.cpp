#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    int V;
    list<int> *adj;

    Graph(int v);
    void addEdge(int u, int v);
    void TopologicalSort();
    void TopologicalSortUtil(int u, bool visit[], stack<int> &st);
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

void Graph::TopologicalSortUtil(int u, bool visit[], stack<int> &st)
{
    visit[u]=true;

    for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
    {
        if(!visit[*it])
            TopologicalSortUtil(*it, visit, st);
    }
    st.push(u);
}
void Graph::TopologicalSort()
{
    bool *visit = new bool[V];
    memset(visit, false, sizeof(visit));

    stack<int> st;

    for(int i=0; i<V; i++)
    {
        if(!visit[i])
        {
           TopologicalSortUtil(i, visit, st);
        }
    }

    while(!st.empty())
    {
        int p = st.top();
        cout<<p<<" ";
        st.pop();
    }
}
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout<<"\ntopological sorting is:\n";
    g.TopologicalSort();
    return 0;
}
