/*Given a directed graph and a source node and destination node, we need to find how many edges we need to
 reverse in order to make at least 1 path from source node to destination node.*/

#include <bits/stdc++.h>
using namespace std;
#define INF 99999
int V = 7;
vector<pair<int, int> > adj[7];

void addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}
void getShortestReversal(int edge[][2], int E)
{
    for(int i=0; i<E; i++)
    {
        addEdge(edge[i][0], edge[i][1], 0);
        addEdge(edge[i][1], edge[i][0], 1);
    }
}

int Dijkstra( int src, int dst)
{
   set<pair<int, int>> st;
   vector<int> dist(V, INF);
   dist[src]=0;

   st.insert(make_pair(0, src));

   while(!st.empty())
   {
       pair<int, int> tmp = *(st.begin());
       st.erase(st.begin());

       int u = tmp.second;
       for(auto i=adj[u].begin(); i!=adj[u].end(); i++)
       {
          int v=(*i).first;
          int wgt=(*i).second;

          if(dist[v]>dist[u]+wgt)
          {
              // if dist[v]==INF, then v node is already visited so erase the old distance and update it with new distance
              if(dist[v]!=INF)
                st.erase(st.find(make_pair(dist[v], v)));

              dist[v]=dist[u]+wgt;
              st.insert(make_pair(dist[v], v));
          }
       }
   }
   return dist[dst];
}

int main()
{

    int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1},
                     {4, 5}, {6, 4}, {6, 3}};
    int E = sizeof(edge) / sizeof(edge[0]);
    getShortestReversal(edge, E);

    cout<<Dijkstra(0, 6);
    return 0;
}
