#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

class Graph
{
    int V;
    list<pair<int, int>> *adj;
public:
    Graph(int v);
    void addEdge(int u, int v, int w);
    void ShortestPath(int s);
    void TopologicalSort(bool visit[], int s, stack<int> &st);
};

Graph::Graph(int v)
{
    V=v;
    adj = new list<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}

void Graph::TopologicalSort(bool visit[], int i, stack<int> &st)
{
    visit[i]=true;
    for(auto p=adj[i].begin(); p!=adj[i].end(); p++)
    {
        int it=(*p).first;
        if(!visit[it])
            TopologicalSort(visit, it, st);
    }
    st.push(i);
}

void Graph::ShortestPath(int s)
{
    bool visit[V];
    memset(visit, false, sizeof(visit));
    stack<int> st;
    for(int i=0; i<V; i++)
    {
        if(!visit[i])
            TopologicalSort(visit, i, st);
    }

    int dist[V];
    for(int i=0; i<V; i++)
        dist[i]=INF;

    dist[s]=0;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();

        if(dist[u]!=INF)
        {
            for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
            {
                if(dist[(*it).first]> dist[u]+ (*it).second)
                    dist[(*it).first] = dist[u]+ (*it).second;
            }
        }
    }
    for(int i=0; i<V; i++)
    {
      if(dist[i]==INT_MAX)
        cout<<"INF"<<" ";
      else
        cout<<dist[i]<<" ";
    }
}

int main()
{
     Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s=1;
    g.ShortestPath(s);
    return 0;
}
