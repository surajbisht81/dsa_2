#include <iostream>
#include<list>
#include<queue>
using namespace std;
class Graph
{
    int vertex;
    list<int> *adj;
public:
    Graph(int v)
    {
        vertex=v;
        adj=new list<int>[vertex];
    }
    void addEdge(int u,int v);
    void printlevel(int src);
    void BFS(int u,bool*,int []);
};
void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}
void Graph::BFS(int u,bool *visited,int level[])
{
    visited[u]=true;
    queue<int>qu;
    qu.push(u);
    while(!qu.empty())
    {
    int s=qu.front();
    qu.pop();
    list<int>::iterator i;
    for( i=adj[s].begin();i!=adj[s].end();i++)
    {
        if(!visited[*i])
        {
            qu.push(*i);
            level[*i]=level[s]+1;
            visited[*i]=true;
        }
    }
    }
}
void Graph::printlevel(int src)
{
    bool *visited=new bool[vertex];
    int level[vertex];
    for(int i=0;i<vertex;i++)
    {
        level[i]=0;
        visited[i]=false;
    }
            BFS(0,visited,level);
    cout<<"\nlevel of nodes are:\n";
    cout<<"vertices "<<"level\n";
    for(int i=0;i<vertex;i++)
       {
         cout<<i<<"\t"<<level[i];
         cout<<endl;
       }
}
int main()
{
    Graph g(8);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(2,6);
    g.addEdge(6,7);
    g.printlevel(0);
}
