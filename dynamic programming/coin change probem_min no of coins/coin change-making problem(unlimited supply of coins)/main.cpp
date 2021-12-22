#include <bits/stdc++.h>
using namespace std;

int min_noof_coins(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=0;

    for(int i=0;i<=sum;i++)
        dp[0][i]=INT_MAX;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=1+min(dp[i][j-arr[i-1]],dp[i-1][j-arr[i-1]]);
        }
    }
    return dp[n][sum];
}
int main()
{
    int arr[]={5,10,11,14};
    int n=sizeof(arr)/sizeof(arr[0]);

    int sum=10;
    cout<<"\nmin no of coins to make sum with unlimited supply of coins :"<<min_noof_coins(arr,n,sum);
    return 0;
}
