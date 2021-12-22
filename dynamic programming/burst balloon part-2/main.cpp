#include <bits/stdc++.h>
using namespace std;

int getCoins(int A[],int n)
{
    int B[n+2];
    B[0]=B[n+1]=1;
    for(int i=1;i<=n;i++)
        B[i]=A[i-1];

    int dp[n+2][n+2];
    memset(dp,0,sizeof(dp));

    for(int length=1;length<=n;length++)
    {
        for(int i=1;i<=n-length+1;i++)
        {
            int j=i+length-1;
                for(int k=i;k<=j;k++)
                {
                    if(length==n)
                        dp[i][j]=max(dp[i][j], dp[i][k-1]+ B[k] +dp[k+1][j]);
                    else
                        dp[i][j]=max(dp[i][j], dp[i][k-1]+ B[i-1]*B[j+1] +dp[k+1][j]);
                }
        }
    }
    return dp[1][n];
}
int main()
{
    int A[]={1, 2, 3, 4};
    int n=sizeof(A)/sizeof(A[0]);
    cout<<"\nmax score= "<<getCoins(A,n);
    return 0;
}
