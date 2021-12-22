#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, wgt;
};

class Graph
{
   int V;
   list<pair<int, int>> *adj;
   vector<Edge> edge;
   public:
       Graph(int v)
       {
           V=v;
           adj = new list<pair<int, int>>[V];
       }
       void addEdge(int u, int v, int w);
       void removeEdge(int u, int v, int w);
       int FindMinCycle();
       int ShortestWgtCycle(int src, int dst);
};
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));

    Edge e{u, v, w};
    edge.push_back(e);
}

void Graph::removeEdge(int u, int v, int w)
{
    adj[u].remove(make_pair(v, w));
    adj[v].remove(make_pair(u, w));
}

int Graph::ShortestWgtCycle(int src, int dst)
{
    set<pair<int, int>> st;

    st.insert(make_pair(0, src));

    int dist[V];
    for(int i=0; i<V; i++)
        dist[i]=INT_MAX;

    dist[src]=0;

    while(!st.empty())
    {
        pair<int, int> p = *(st.begin());
        st.erase(st.begin());

        int u=p.second;

        for(auto child:adj[u])
        {
            int v= (child).first;
            int w= (child).second;
            if(dist[v]>dist[u]+w)
            {
                if(dist[v]!=INT_MAX)
                    st.erase(st.find(make_pair(dist[v], v)));

                dist[v]=dist[u]+w;
                st.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist[dst];
}

int Graph::FindMinCycle()
{
   int E = edge.size();
   int minCycle=INT_MAX;

   for(int i=0; i<E; i++)
   {
       Edge p=edge[i];
       int u=p.u;
       int v=p.v;
       int w=p.wgt;
       removeEdge(u, v, w);

       int shortestpath = ShortestWgtCycle(u, v);

       minCycle = min(minCycle, shortestpath+w);
       addEdge(u, v, w);
   }
   return minCycle;
}

int main()
{
    int V=9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout<<g.FindMinCycle();
    return 0;
}
