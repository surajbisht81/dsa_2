#include <iostream>
#include<list>

using namespace std;
class Graph
{
    int V;
    list<int>*adj;

public:
    Graph(int v)
    {
        v=V;
        adj=new list<int>[V];

    }
    int BFS(int src,int l);
    void addEdge(int u,int v);
};

void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int Graph::BFS(int src,int l)
{
    bool* traverse=new bool[V];
    int level[V];
        for(int i=0;i<V;i++)
        {
            traverse[i]=false;
            level[i]=0;
        }
    list<int>qu;

    level[src]=0;
    traverse[src]=true;
    qu.push_back(src);
    while(!qu.empty())
    {
    src=qu.front();
    qu.pop_front();
    list<int>::iterator i;
    for(i=adj[src].begin();i!=adj[src].end();i++)
    {
        if(!traverse[*i])
        {
          level[*i]=level[src]+1;
          traverse[*i]=true;
          qu.push_back(*i);
        }
    }
    }
   int count=0;
    for(int j=0;j<V;j++)
    {
        if(level[j]==l)
            count++;
    }
    return count;
}
int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    int level = 2;
    cout <<"\nno of nodes at level 2 is="<< g.BFS(0, level);
}
