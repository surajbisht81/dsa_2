#include <iostream>
#include<list>
using namespace std;
class Graph
{
public:
    int vertex;
    list<int>*arr;
    bool *traversal;
    Graph(int v)
    {
        vertex=v;
        arr=new list<int>[vertex];
        traversal=new bool[vertex];
        for(int i=0;i<vertex;i++)
        {
            traversal[i]=false;
        }
    }
    void addnode(int u,int v);
    void DFStraversal(int s);
};

void Graph::addnode(int u,int v)
{
    arr[u].push_back(v);
}
void Graph::DFStraversal(int s)
{
    cout<<s<<" ";
    traversal[s]=true;
    list<int>::iterator it;
    for(it=arr[s].begin();it!=arr[s].end();it++)
    {
        if(!traversal[*it])
            DFStraversal(*it);  //recursion is used here;
    }
}
int main()
{
    Graph g(4);
    g.addnode(0,1);
    g.addnode(0,2);
    g.addnode(1,2);
    g.addnode(2,0);
    g.addnode(2,3);
    g.addnode(3,3);
    g.DFStraversal(2);
    return 0;
}
