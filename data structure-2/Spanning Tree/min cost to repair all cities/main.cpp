#include <bits/stdc++.h>
using namespace std;

int minDis(int key[], bool mstSet[], int V)
{
    int min_idx, minn=INT_MAX;
    for(int i=0; i<V; i++)
    {
        if(mstSet[i]==false and minn>key[i])
            minn=key[i], min_idx=i;
    }
    return min_idx;
}
void MinCost(vector<vector<int>> city, int V)
{
   int parent[V];
   int key[V];
   bool mstSet[V];
   for(int i=0; i<V; i++)
        mstSet[i]=false, key[i]=INT_MAX;
   parent[0]=-1;
   key[0]=0;

   for(int i=0; i<V-1; i++)
   {
       int u = minDis(key, mstSet, V);
       mstSet[u]=true;

       for(int v=0; v<V; v++)
       {
           if(city[u][v] and mstSet[v]==false and key[v]>city[u][v])
             parent[v]=u, key[v]=city[u][v];
       }
   }
   int cost=0;
   for(int i=1; i<V; i++)
   {
       cost+=city[parent[i]][i];
   }
   cout<<cost;
}

int main()
{
    int V1=5;
    vector<vector<int>> city1 = {{0, 1, 2, 3, 4},
                               {1, 0, 5, 0, 7},
                               {2, 5, 0, 6, 0},
                               {3, 0, 6, 0, 0},
                               {4, 7, 0, 0, 0}};

    MinCost(city1, V1);
    return 0;
}
