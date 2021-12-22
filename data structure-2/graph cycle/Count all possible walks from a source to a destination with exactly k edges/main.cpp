/*Given a directed graph and two vertices ‘u’ and ‘v’ in it, count all possible walks from ‘u’ to ‘v’ with exactly k edges on the walk.*/

#include <bits/stdc++.h>
using namespace std;
#define V 4

int PossibleWalks(int graph[][V], int u, int v, int k)
{
    if(k==0 and u==v)
        return 1;
    if(k==1 and graph[u][v])
        return 1;
    if(k<=0 and u!=v)
        return 0;
    int count=0;

    for(int i=0; i<V; i++)
    {
        if(graph[u][i])
            count+=PossibleWalks(graph, i, v, k-1);
    }
    return count;
}

int main()
{
     int graph[V][V] = { { 0, 1, 1, 1 },
                        { 0, 0, 0, 1 },
                        { 0, 0, 0, 1 },
                        { 0, 0, 0, 0 } };
     int u=0, v=3, k=2;
     cout<<PossibleWalks(graph, u, v, k);
     return 0;
}
