#include <iostream>
#include<list>
#include<queue>

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
      void addlist(int u,int v);
      void BFStraversal(int s);
};
void Graph::addlist(int u,int v)
{
    arr[u].push_back(v);
}

void Graph::BFStraversal(int s)
{
    list<int> qu;
    traversal[s]=true;
    qu.push_back(s);

    list<int>::iterator it;
    while(!qu.empty())
    {
        s=qu.front();
        cout<<s<<" ";
        qu.pop_front();
        for(it=arr[s].begin();it!=arr[s].end();it++)
        {
            if(!traversal[*it])
            {
                traversal[*it]=true;
                qu.push_back(*it);
            }
        }
    }
}
int main()
{
   Graph g(4);
   g.addlist(0,1);
   g.addlist(0,2);
   g.addlist(1,2);
   g.addlist(2,0);
   g.addlist(2,3);
   g.addlist(3,3);
   g.BFStraversal(2);
   return 0;
}
