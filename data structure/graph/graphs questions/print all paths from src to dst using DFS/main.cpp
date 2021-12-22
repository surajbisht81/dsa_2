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
    void printAllPaths(int s,int d);
    void printpathutil(int,int,bool [],int [],int &);
};
void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}

void Graph::printpathutil(int s,int d,bool visited[],int path[],int &path_index)
{
    visited[s]=true;
    path[path_index]=s;
    path_index++;
    if(s==d)
    {
        for(int i=0;i<path_index;i++)
            cout<<path[i]<<" ";
        cout<<endl;
    }
    else
    {
      list<int>::iterator it;
      for(it=adj[s].begin();it!=adj[s].end();it++)
      {
          if(!visited[*it])
            printpathutil(*it,d,visited,path,path_index);
      }
    }
    visited[s]=false;
    path_index--;
}
void Graph::printAllPaths(int s,int d)
{
    bool *visited=new bool[vertex];
    int *path=new int[vertex];
    int path_index=0;
    for(int i=0;i<vertex;i++)
        visited[i]=false;
    printpathutil(s,d,visited,path,path_index);
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
    cout << "Following are all different paths from " << s
        << " to " << d << endl;
    g.printAllPaths(s, d);

    return 0;
}
