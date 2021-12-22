#include <bits/stdc++.h>
using namespace std;
#define V 6

bool dfs(int rGraph[V][V], int s, int t, int parent[])
{
    queue<int> qu;
    qu.push(s);
    bool visit[V];
    memset(visit, false, sizeof(visit));
    visit[s]=true;

    while(!qu.empty())
    {
        int p=qu.front();
        qu.pop();

        for(int i=0; i<V; i++)
        {
            if(visit[i]==false and rGraph[p][i]>0)
            {
                visit[i]=true;
                parent[i]=p;
                qu.push(i);
            }
        }
    }
    return (visit[t]==true);
}

int FordFulkerson(int graph[][V], int s, int t)
{
    int rGraph[V][V];
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            rGraph[i][j]=graph[i][j];
        }
    }

    int parent[V];
    parent[s]=-1;
    int max_flow=0;

    while(dfs(rGraph, s, t, parent))
    {
       int min_val=INT_MAX;
       for(int v=t; v!=s; v=parent[v])
       {
           int u=parent[v];
           min_val=min(min_val, rGraph[u][v]);
       }

       for(int v=t; v!=s; v=parent[v])
       {
           int u=parent[v];
           rGraph[u][v]-=min_val;
           rGraph[v][u]+=min_val;
       }
       max_flow+=min_val;
    }
    return max_flow;
}

int main()
{
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

  cout<<FordFulkerson(graph, 0, 5);
  return 0;
}
