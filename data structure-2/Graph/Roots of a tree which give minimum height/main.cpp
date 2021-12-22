#include <bits/stdc++.h>
using namespace std;

int V = 6;

struct node
{
    int val;
    int level;
};
void addEdge(list<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int BFS(int i, list<int>adj[])
{
    queue<node> qu;
    qu.push({i, 0});

    bool visit[V];
    memset(visit, false, sizeof(visit));

    visit[i]=true;

    list<int> :: iterator it;

    node main_node, newnode;
    while(!qu.empty())
    {
        node p = qu.front();
        qu.pop();

        for(it=adj[p.val].begin(); it!=adj[p.val].end(); it++)
        {
           if(!visit[*it])
           {
               visit[*it]=true;
               newnode.val = *it;
               newnode.level = p.level+1;
               qu.push(newnode);
           }
        }
        main_node = newnode;
    }
    memset(visit, false, sizeof(visit));
    return main_node.level;
}

void minHeight(list<int> adj[])
{
    int smallest = INT_MAX;
    int root;

    for(int i=0; i<V; i++)
    {
       int count = BFS(i, adj);
       if(count<smallest)
       {
           smallest = count;
           root = i;
        }
    }
    cout<<root;

}
int main()
{
    list<int> *adj = new list<int>[V];

    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 3);
    addEdge(adj, 5, 4);

     minHeight(adj);
     return 0;
}
