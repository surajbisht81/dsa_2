#include <bits/stdc++.h>
using namespace std;

int n=4;
int dist[4][4]={ {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}};

int VISITED_ALL= (1<<n)-1;

int dp[16][4];

int tsp(int mask,int pos)
{
    if(mask==VISITED_ALL)
        return dist[pos][0];

    if(dp[mask][pos]!=-1)
        return dp[mask][pos];

    int minn=INT_MAX;
    for(int city=0;city<n;city++)
    {
        if((mask&(1<<city))==0)
        {
           int res=dist[pos][city]+tsp(mask|(1<<city),city);
           minn=min(minn,res);
        }
    }
    return dp[mask][pos]=minn;
}
int main()
{
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<4;j++)
            dp[i][j]=-1;


    cout<<"\nmin cost is "<<tsp(1,0);
    return 0;
}
