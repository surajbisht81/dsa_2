#include <bits/stdc++.h>
using namespace std;


int countPaths(list<int> g[], int src, int dst, int v)
{
   int count=0;
   //bool visited[v];
   //memset(visited, false, sizeof(visited));

   queue<int> qu;
   qu.push(src);
   //visited[src]=true;
   list<int> :: iterator it;
   while(!qu.empty())
   {
       int p = qu.front();
       qu.pop();

       for( it=g[p].begin(); it!=g[p].end(); it++)
       {
           if( *it!=src)
           {
              // visited[it]=true;
               if(*it==dst)
                 count++;
               else
                 qu.push(*it);
           }
       }
   }
   return count;
}
int main()
{
    int v=4;
    list<int> *g = new list<int>[v];

    g[0].push_back(3);
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(3);
    g[2].push_back(0);
    g[2].push_back(1);

    int src=2, dst=3;
    cout<<"\ntotal path from src to dst is :"<<countPaths(g, src, dst, v);
    return 0;
}
