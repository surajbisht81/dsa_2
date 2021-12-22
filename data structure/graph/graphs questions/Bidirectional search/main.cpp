#include <iostream>
#include<bits/stdc++.h>
#include<list>
#include<vector>
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
    int biDirSearch(int s,int t);
    void BFS(list<int>*,bool*,int*);
    int isintersection(bool *s_visited,bool *t_visited);
    void printpath(int *s_parent,int *t_parent,int s,int t,int intersectingnode);
};
void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Graph::BFS(list<int>*qu ,bool *visited,int *parent)
{
    int current=qu->front();
    qu->pop_front();
    for(auto it=adj[current].begin();it!=adj[current].end();it++)
    {
        if(!visited[*it])
        {
            parent[*it]=current;
            visited[*it]=true;
            qu->push_back(*it);
        }
    }
};
int Graph::isintersection(bool *s_visited,bool *t_visited)
{
        int intersectingnode=-1;
    for(int i=0;i<vertex;i++)
    {
        if(s_visited[i] && t_visited[i])
            return i;
    }
    return -1;
};
int Graph::biDirSearch(int s,int t)
{
    bool s_visited[vertex],t_visited[vertex];
    int s_parent[vertex],t_parent[vertex];

    for(int i=0;i<vertex;i++)
    {
        s_visited[i]=false;
        t_visited[i]=false;
    }
    list<int> s_queue,t_queue;
    int intersectingnode=-1;

    s_queue.push_back(s);
    s_visited[s]=true;
    s_parent[s]=-1;

    t_queue.push_back(t);
    t_visited[t]=true;
    t_parent[t]=-1;

    while(!s_queue.empty() && !t_queue.empty())
    {
        BFS(&s_queue,s_visited,s_parent);
        BFS(&t_queue,t_visited,t_parent);

        intersectingnode=isintersection(s_visited,t_visited);

        if(intersectingnode!=-1)
        {
            cout<<"path exist blw source and target";
            cout<<"\nintersection node is:"<<intersectingnode;
            cout<<"\npath is:\n";
            printpath(s_parent,t_parent,s,t,intersectingnode);
            exit(0);
        }
    }
    return -1;
}
void Graph::printpath(int *s_parent,int *t_parent,int s,int t,int intersectingnode)
{
    vector<int> path;
    path.push_back(intersectingnode);
    int i=intersectingnode;
    while(i!=s)
    {
        path.push_back(s_parent[i]);
        i=s_parent[i];
    }
    reverse(path.begin(),path.end());

    i=intersectingnode;
    while(i!=t)
    {
        path.push_back(t_parent[i]);
        i=t_parent[i];
    }
    for(auto it=path.begin();it!=path.end();it++)
    {
        cout<<" "<<*it;
    }
};
int main()
{
    int n=15;
    int s=0;
    int t=14;
    Graph g(n);
    g.addEdge(0, 4);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(8, 10);
    g.addEdge(9, 11);
    g.addEdge(9, 12);
    g.addEdge(10, 13);
    g.addEdge(10, 14);
    if (g.biDirSearch(s, t) == -1)
        cout << "Path don't exist between "
             << s << " and " << t << "\n";

    return 0;
}
