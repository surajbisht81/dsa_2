// This code will not run in this ide
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int parent, rank;
};

vector<node> v;

int Find(int i)
{
    if(v[i].parent==-1)
        return i;

    return v[i].parent = Find(v[i].parent);
}

void Union(int fromt, int top)
{

    if(v[fromt].rank>v[top].rank)
        v[top].parent=fromt;

    else if(v[fromt].rank<v[top].rank)
        v[fromt].parent=top;

    else
    {
        v[fromt].parent=top;
        v[top].rank +=1;
    }
}

bool isCyclic(vector<pair<int, int>> make_pair)
{
   for(auto p:make_pair)
   {
       int fromt = Find(p.first);
       int top = Find(p.second);

       if(fromt==top)
        return true;

       Union(fromt, top);
   }
   return false;
}

int main()
{
  int E, V;
  cin>> V>> E;

  v.resize(V);
  for(int i=0; i<V; ++i)
  {
      v[i].parent=-1;
      v[i].rank=0;
  }

  int from, to;
  vector<pair<int, int>> make_edge;
  for(int i=0; i<E; ++i)
  {
      cin>>from>>to;
      make_edge.push_back(make_pair(from, to));
  }

  if(isCyclic(make_edge))
    cout<<"\ncycle is present.";
  else
    cout<<"\ncycle is not present.";
  return 0;
}
