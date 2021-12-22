#include <iostream>
#include<list>
#include<vector>

using namespace std;

class Graph
{
    int vertex;
    list<int> *adj;
public:
    Graph(int v);
    void addEdge(int u,int v);
    void DFSutil(int v,vector<bool>&visited);
    int findMother();
};

Graph::Graph(int v)
{
    vertex=v;
    adj=new list<int>[vertex];
}
void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}

void Graph::DFSutil(int v,vector<bool>&visited)
{
    visited[v]=true;
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
            DFSutil(*i,visited);
    }
}
int Graph::findMother()
{
    int v=0;
    vector<bool>visited(vertex,false);
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
         {
             DFSutil(i,visited);
             v=i;
         }
    }
    //now check if v is actually a mother vertex or not;
    //perform DFS from vertex v and check whether all nodes are traversed from v or not;
    fill(visited.begin(),visited.end(),false);
    DFSutil(v,visited);
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
            return -1;
    }
    return v;
}
int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);

    cout << "A mother vertex is " << g.findMother();

    return 0;
}
