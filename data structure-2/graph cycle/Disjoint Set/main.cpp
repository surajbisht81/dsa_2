// This disjoint set is used to detect any cycle in undirected graph.
#include <bits/stdc++.h>
using namespace std;
#define V 4
#define E 3
int parent[V];

int Find(int v)
{
    if(parent[v]==-1)
        return v;
    return Find(parent[v]);
}

void Union(int fromp, int top)
{
    fromp = Find(fromp);
    top = Find(top);

    parent[fromp]=top;
}

bool isCyclic(vector<pair<int, int>> v)
{
   for(int i=0; i<v.size(); i++)
   {
       pair<int, int> p = v[i];

       int fromp = p.first;
       int top = p.second;

       if(Find(fromp)==Find(top))
        return true;

       Union(fromp, top);
   }
   return false;
}

int main()
{
     vector<pair<int, int>> v;

     memset(parent, -1, sizeof(parent));

     cout<<"\nenter the edge list:\n";
     int from, to;
     for(int i=0; i<E; i++)
     {
         cin>>from>>to;
         v.push_back(make_pair(from, to));
     }
     if(isCyclic(v))
      cout<<"\ncycle is present.";
     else
      cout<<"\ncycle is not present.";
     return 0;
}
