#include <bits/stdc++.h>
using namespace std;

/*int countWays(int n,int m)
{
    if(n<=1)
        return 1;

    int res=0;
    for(int i=1;i<=m;i++)
    {
        res+=countWays(n-i,m);
    }
    return res;
}

int main()
{
    int n,m;
    cout<<"\nenter no of stairs and moves :";
    cin>>n>>m;
    cout<<"\nno of ways="<<countWays(n,m);
    return 0;
}*/
// 2nd method using dynamic programming
int countWays(int n,int m)
{
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m && j<=i;j++)
        {
            dp[i]+=dp[i-j];
        }
    }
    return dp[n];
}

int main()
{
    int n,m;
    cout<<"\nenter no of stairs and moves :";
    cin>>n>>m;
    cout<<"\nno of ways="<<countWays(n,m);
    return 0;
}
