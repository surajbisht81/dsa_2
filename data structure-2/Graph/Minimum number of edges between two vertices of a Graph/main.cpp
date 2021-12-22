#include <bits/stdc++.h>
using namespace std;


int minEdges(int src, int dst, int n, list<int> edges[])
{
    int res[n];
    for(int i=0;i<n;i++)
        res[i]=INT_MAX;
    res[src]=0;

    queue<int> qu;
    qu.push(src);
    list<int> ::iterator it;
    bool visited[n];
    memset(visited, false, sizeof(visited));
    visited[src]=true;

    while(!qu.empty())
    {
        int p = qu.front();
        qu.pop();

        for(it=edges[p].begin(); it!=edges[p].end(); it++)
        {
               if(!visited[*it])
                {
                    if(*it!=dst)
                      visited[*it]=true;
                    else
                        visited[*it]=false;
                   res[*it]=min(res[p]+1, res[*it]);
                   qu.push(*it);
                }

        }
    }
    return res[dst];
}
void addEdge(list<int> edges[], int u, int v)
{
    edges[u].push_back(v);
    edges[v].push_back(u);
}
int main()
{
      int n = 9;
    list<int> *edges = new list<int>[n];
    addEdge(edges, 0, 1);
    addEdge(edges, 0, 3);
    addEdge(edges, 1, 2);
    addEdge(edges, 2, 4);
    addEdge(edges, 3, 4);
    addEdge(edges, 4, 5);
    /*addEdge(edges, 2, 8);
    addEdge(edges, 3, 4);
    addEdge(edges, 3, 5);
    addEdge(edges, 4, 5);
    addEdge(edges, 5, 6);
    addEdge(edges, 6, 7);
    addEdge(edges, 7, 8);*/


    int src=0, dst=5;
    cout<<"\n min edges blw 0 and 5 are : "<<minEdges(src, dst, n, edges);
    return 0;
}
