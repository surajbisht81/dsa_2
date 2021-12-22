#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int> *adj;
public:
    Graph(int v);
    void addEdge(int u, int v);
    void Topological();
    void TopologicalUtil(stack<int> &st, int u, bool visit[]);
};
Graph::Graph(int v)
{
    V=v;
    adj = new vector<int>[V];
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::TopologicalUtil(stack<int> &st, int u, bool visit[])
{
    visit[u]=true;
    for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
    {
        if(!visit[*it])
            TopologicalUtil(st, *it, visit);
    }
    st.push(u);
}
void Graph::Topological()
{
  stack<int> st;
  bool visit[V];
  memset(visit, false, sizeof(visit));

  for(int i=0; i<V; i++)
  {
    if(!visit[i])
        TopologicalUtil(st, i, visit);
  }
  vector<int> v;
  while(!st.empty())
  {
      v.push_back(st.top());
      st.pop();
  }

  memset(visit, false, sizeof(visit));
  for(int i=0; i<v.size(); i++)
  {
       int t=v[i];
       for(auto it=adj[t].begin(); it!=adj[t].end(); it++)
         visit[*it]=true;

       for(int j=i+1; j<v.size(); j++)
       {
           if(!visit[v[j]])
            cout<<t<<"-->"<<v[j]<<endl;

           visit[v[j]]=false;
       }
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

    g.Topological();
    return 0;
}
