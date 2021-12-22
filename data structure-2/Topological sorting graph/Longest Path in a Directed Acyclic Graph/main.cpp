#include <bits/stdc++.h>
using namespace std;
#define NINF INT_MIN

class Graph
{
    int V;
    vector<pair<int, int>> *adj;
public:
    Graph(int v);
    void addEdge(int v, int u, int w);
    void Topological(int src);
    void TopologicalUtil(stack<int> &st, int u, bool visit[]);
};

Graph::Graph(int v)
{
    V=v;
    adj = new vector<pair<int, int>>[V];
}
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back({v, w});
}

void Graph::TopologicalUtil(stack<int> &st, int u, bool visit[])
{
    visit[u]=true;
    for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
    {
        if(!visit[(*it).first])
            TopologicalUtil(st, (*it).first, visit);
    }
    st.push(u);
}
void Graph::Topological(int src)
{
  stack<int> st;
  bool visit[V];
  memset(visit, false, sizeof(visit));

  for(int i=0; i<V; i++)
  {
    if(!visit[i])
        TopologicalUtil(st, i, visit);
  }

  int dist[V];
  for(int i=0; i<V; i++)
    dist[i]=NINF;

  dist[src]=0;
  while(!st.empty())
  {
     int u=st.top();
     st.pop();

     if(dist[u]!=NINF)
     {
         for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
         {
             pair<int,int> p=*it;
             if(dist[p.first] < dist[u]+p.second)
                dist[p.first] = dist[u]+p.second;
         }
     }
  }

  for(int i=0; i<V; i++)
     dist[i]==NINF ? cout<<"INF"<<" " : cout<<dist[i]<<" ";

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
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int src=1;
    g.Topological(src);
    return 0;
}
