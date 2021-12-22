#include <bits/stdc++.h>
using namespace std;

int countWays(int n)
{
    int dp[n+1];
    dp[0]=dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+ dp[i-2]*(i-1);
    }
    return dp[n];
}
int main()
{
    int n;
    cout<<"\nenter no of friends:";
    cin>>n;
    cout<<"\n total no of ways in which friends can be paired up or remain single : "<<countWays(n);
    return 0;
}
