#include <iostream>
#include<list>
using namespace std;
class Graph
{
    int vertex;
    list<int>*adj;
public:
    Graph(int v)
    {
        vertex=v;
        adj=new list<int>[vertex];
    }
    void addEdge(int u,int v);
    void BFSutil(int src,int dst);
};
void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}
void Graph::BFSutil(int src,int dst)
{
    bool *visit=new bool[vertex];
    for(int i=0;i<vertex;i++)
    {
        visit[i]=false;
    }
    visit[src]=true;
    list<int>qu;
    qu.push_back(src);
    while(!qu.empty())
    {
        int s=qu.front();
        qu.pop_front();
        int index[vertex]=s;

        if(dst==s)
        {
            for(int i=0;i<index;i++)
                cout<<"-->"<<
        }
        for(auto it=adj[s].begin();it!=adj[s].end();it++)
        {
            if(!visit[*it])
            {
                qu.push_back(*it);
            }
        }
}
}
int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(2,0);
    g.addEdge(2,1);
    cout<<"\nall possible paths are:"<<g.BFSutil(2,3);
    return 0;
}
