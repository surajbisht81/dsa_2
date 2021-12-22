#include <iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> edges[],int u,int v)
{
    edges[u].push_back(v);
    edges[v].push_back(u);
}
int minEdgeBFS(vector<int> edges[],int u,int v,int n)
{
    queue<int> qu;
    bool *visited=new bool[n];
    int distance[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        distance[i]=0;
    }
    visited[u]=true;
    qu.push(u);
    while(!qu.empty())
    {
        int s=qu.front();
        qu.pop();
        for(auto it=edges[s].begin();it!=edges[s].end();it++)
        {
            if(!visited[*it])
            {
                distance[*it]=distance[s]+1;
                visited[*it]=true;
                qu.push(*it);
            }
        }
    }
    return distance[v];
}
int main()
{
     int n = 7;
    vector <int> edges[7];
    addEdge(edges, 0, 1);
    addEdge(edges, 0, 2);
    addEdge(edges, 0, 4);
    addEdge(edges, 1, 2);
    addEdge(edges, 2, 5);
    addEdge(edges, 3, 4);
    addEdge(edges, 4, 5);
    addEdge(edges, 4, 6);
    int u = 1;
    int v = 5;
    cout <<"min edges are:"<< minEdgeBFS(edges, u, v, n);
    return 0;
}
