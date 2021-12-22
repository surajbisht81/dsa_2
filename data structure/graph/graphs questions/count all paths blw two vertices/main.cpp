#include <iostream>
#include<list>
#include<bits/stdc++.h>
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
    void addEdge(int u,int v);
    int countpath(int s,int d);
    void countpathUTIL(int ,int,bool [],int &);
};
void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}
int Graph::countpath(int s,int d)
{
    bool *visited=new bool[V];
    memset(visited,false,sizeof(bool));
    int paths=0;
    countpathUTIL(s,d,visited,paths);
    return paths;
}
void Graph::countpathUTIL(int u,int d,bool visited[],int &paths)
{
    visited[u]=true;
    if(u==d)
        paths++;
    else
    {
        list<int>::iterator i;
        for(i=adj[u].begin();i!=adj[u].end();i++)
        {
            if(!visited[*i])
                countpathUTIL(*i,d,visited,paths);
        }
    }
    visited[u]=false;
}

int main()
{
     Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);

    int s = 2, d = 3;
    cout << g.countpath(s, d);

    return 0;
}
