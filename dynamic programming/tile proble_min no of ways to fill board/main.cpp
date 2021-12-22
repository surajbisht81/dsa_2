#include<bits/stdc++.h>
using namespace std;

int count(int n,int m)
{
    int ways[n+1];
    ways[0]=0;

    for(int i=1;i<=n;i++)
    {
        if(i>m)
            ways[i]=ways[i-1]+ways[i-m];

        else if(i<m)
            ways[i]=1;
        else
            ways[i]=2;
    }
    return ways[n];
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<"no of ways:"<<count(n,m);
    return 0;
}
