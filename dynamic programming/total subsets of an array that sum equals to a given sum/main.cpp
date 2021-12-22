#include <bits/stdc++.h>
using namespace std;

int total_subsets(int arr[],int n,int sum)
{
    int dp[n][sum+1];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++)
        dp[i][0]=1;

    dp[0][arr[0]]=1;

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i]>j)
                dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=dp[i-1][j];
                dp[i][j]+=dp[i-1][j-arr[i]];
            }
        }
    }
    return dp[n-1][sum];
}
int main()
{
    int arr[]={2,3,7,1,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=7;
    cout<<"total subsets = "<<total_subsets(arr,n,sum);
    return 0;
}
