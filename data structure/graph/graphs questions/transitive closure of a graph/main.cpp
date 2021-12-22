#include <iostream>
#include<list>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int>*adj;
    bool **tc;
public:
    Graph(int v)
    {
        V=v;
        adj=new list<int>[V];
        tc=new bool*[V];
        for(int i=0;i<V;i++)
        {
            tc[i]=new bool[V];
            memset(tc[i],false,V*sizeof(bool));
        }
    }
    void addEdge(int u,int v);
    void transitiveclosure();
    void DFSutil(int u,int v);
};
void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}
void Graph::DFSutil(int u,int v)
{
    tc[u][v]=true;
    list<int>::iterator i;
    for( i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(tc[u][*i]==false)
            DFSutil(u,*i);
    }
}
void Graph::transitiveclosure()
{
    for(int i=0;i<V;i++)
      DFSutil(i,i);

    cout<<endl;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<"\t"<<tc[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    Graph g(4);
     g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout<<"\ntransitive closure is:\n";
    g.transitiveclosure();
    return 0;
}
