/*Given a tree (not necessarily a binary tree) and a number of queries such that every query takes two nodes of tree as parameters. For every query pair,
 find if two nodes are on the same path from root to the bottom.

For example, consider the below tree, if given queries are (1, 5), (1, 6) and (2, 6), then answers should be true, true and false respectively.
Check if two nodes are on same path in a tree*/

#include <bits/stdc++.h>
using namespace std;

int V = 9;
vector<int > graph[9+1];
int c=0;
void DFSutil(int src, int dst, bool visit[])
{
    visit[src]=true;
    for(auto u=graph[src].begin(); u!=graph[src].end(); u++)
    {
        if(!visit[*u])
        {
            if(*u==dst)
                c=1;
             DFSutil(*u, dst, visit);
        }
    }
}

void DFS(int src, int dst)
{
      bool visit[V];
      memset(visit, false, sizeof(visit));

      if(visit[src]==false)
      {
        DFSutil(src, dst, visit);
        if(c==1)
          cout<<"true"<<endl;
        else
          cout<<"false"<<endl;
      }
}

int main()
{
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[3].push_back(6);
    graph[2].push_back(4);
    graph[2].push_back(5);
    graph[5].push_back(7);
    graph[5].push_back(8);
    graph[5].push_back(9);

    DFS(2, 6);
    DFS(1,6);
    DFS(1,9);
    return 0;
}
