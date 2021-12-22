#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *adj;

    void fillorder(int i, bool traverse[], stack<int> &st);
    void printSSC();
    void addEdge(int u, int v);
    void DFSUtil(int v, bool visited[]);

    Graph getTranspose();
    Graph(int v)
    {
        V=v;
        adj = new list<int>[V];
    }
};
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::fillorder(int i, bool traverse[], stack<int>&st)
{
    traverse[i]=true;

    for(auto it=adj[i].begin(); it!=adj[i].end(); it++)
    {
        if(!traverse[*it])
            fillorder(*it, traverse, st);
    }
    st.push(i);
}

Graph Graph::getTranspose()
{
    Graph g(V);

    for(int i=0;i<V;i++)
    {
        for(auto it=adj[i].begin(); it!=adj[i].end(); it++)
        {
            g.adj[*it].push_back(i);
        }
    }
    return g;
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v]=true;
    cout<<v<<" ";

    for(auto it=adj[v].begin(); it!=adj[v].end(); it++)
    {
        if(!visited[*it])
        DFSUtil(*it, visited);
    }
}

void Graph::printSSC()
{
    stack<int> st;
    bool *transpose = new bool[V];
    for(int i=0;i<V;i++)
        transpose[i]=false;

    for(int i=0;i<V;i++)
        if(transpose[i]==false)
         fillorder(i,transpose, st);

    Graph gr = getTranspose();

    for(int i=0;i<V;i++)
        transpose[i]=false;

    while(!st.empty())
    {
        int s=st.top();
         st.pop();

        if(!transpose[s])
        {
            gr.DFSUtil(s, transpose);
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

    cout<<"\n Strongly connected components are :\n";
    g.printSSC();
}
