#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[], int u, int v)
{
    adj[u].push_back(v);
}

void getTranspose(vector<int>transpose[], vector<int> adj[], int V)
{

    for(int i=0;i<V;i++)
    {
            for(auto it=adj[i].begin(); it!=adj[i].end(); it++)
            {
                transpose[*it].push_back(i);

            }
    }
}

void DisplayAdj(vector<int>adj[], int V)
{
    for(int i=0;i<V;i++)
    {
       cout<<i<<"-->";
       for(auto it=adj[i].begin(); it!=adj[i].end(); it++)
       {
           cout<<*it<<" ";
       }
       cout<<endl;
    }
}
int main()
{
    int V= 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);

    vector<int> transpose[V];
    getTranspose(transpose,adj, V);
    DisplayAdj(transpose, V);
    return 0;
}
