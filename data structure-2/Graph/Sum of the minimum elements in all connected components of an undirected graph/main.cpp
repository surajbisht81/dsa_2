/*Given an array A of N numbers where Ai represent the value of the (i+1)th node. Also given are M pair of edges where u and v represent the nodes that are 
connected by an edge. The task is to find the sum of the minimum element in all the connected components of the given undirected graph. If a node has no 
connectivity to any other node, count it as a component with one node.*/

#include <bits/stdc++.h>
using namespace std;

void addEdge(list<int> adj[], int u, int v)
{
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
}

void DFS(list<int> adj[], int i, int a[], int mini, bool visit[])
{
    visit[i]=true;
    mini = min(mini, a[i]);

    for(auto u:adj[i])
    {
        if(!visit[u])
            DFS(adj, u, a, mini, visit);
    }
}

void minSum(list<int> adj[], int a[], int n)
{
   bool visit[n];
   memset(visit, false, sizeof(visit));

   int sum=0;
   for(int i=0; i<n; i++)
   {
       int mini=a[i];
       if(!visit[i])
        {
            DFS(adj, i, a, mini, visit);
            sum+=mini;
        }
   }
   cout<<sum;
}

int main()
{
    int a[] = {1, 6, 2, 7, 3, 8, 4, 9, 5, 10};
    int n=sizeof(a)/sizeof(a[0]);

    list<int> *adj = new list<int>[n];
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 6);
    addEdge(adj, 7, 8);
    addEdge(adj, 9, 10);

    minSum(adj, a, n);
    return 0;
}
