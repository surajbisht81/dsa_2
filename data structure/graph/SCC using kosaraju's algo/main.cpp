#include <iostream>
#include<list>
#include<stack>
using namespace std;

class Graph
{
    int vertex;
    list<int>*adj;
    void fillorder(int v,bool visited[], stack<int>&Stack);
    void DFSutil(int v,bool visited[]);

public:
    Graph(int v)
    {
        vertex=v;
        adj=new list<int>[vertex];
    }
    void addEdge(int u,int v);
    Graph getTraspose();
    void printSCC();
};
void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}

void Graph::fillorder(int v,bool visited[],stack<int>&Stack)
{
    list<int>::iterator i;
    visited[v]=true;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
            fillorder(*i,visited,Stack);
    }
    Stack.push(v);
}

Graph Graph::getTraspose()
{
    Graph g(vertex);
    for(int i=0;i<vertex;i++)
    {
        list<int>::iterator it;
        for(it=adj[i].begin();it!=adj[i].end();it++)
        {
            g.adj[*it].push_back(i);
        }
    }
    return g;
}

void Graph::DFSutil(int v,bool visited[])
{
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();++i)
    {
        if(!visited[*i])
           {
               DFSutil(*i,visited);
           }
    }
}
void Graph::printSCC()
{
    stack<int>Stack;
    bool *visited=new bool[vertex];
    for(int i=0;i<vertex;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
          fillorder(i,visited,Stack);
    }
    Graph gr=getTraspose();
    for(int i=0;i<vertex;i++)
        visited[i]=false;

    while(Stack.empty()==false)
    {
        int v=Stack.top();
        Stack.pop();
            if(visited[v]==false)
             {
                 gr.DFSutil(v,visited);
                cout<<endl;
             }
     }
}
int main()
{
    Graph g(5);

    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCC();
    return 0;
}
