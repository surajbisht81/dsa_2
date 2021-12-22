/*We have been given N balloons, each with a number of coins associated with it. On bursting a balloon i, the number of coins gained is equal to A[i-1]*A[i]*A[i+1].
 Also, balloons i-1 and i+1 now become adjacent. Find the maximum possible profit earned after bursting all the balloons. Assume an extra 1 at each boundary.*/

#include <bits/stdc++.h>
using namespace std;

int getmaxCost(int A[],int n)
{
    int dp[n+2][n+2];

    int B[n+2];
    B[0]=B[n+1]=1;

    for(int i=1;i<=n;i++)
        B[i]=A[i-1];

    memset(dp,0,sizeof(dp));

    for(int length=1;length<=n;length++)
    {
        for(int i=1;i<=n-length+1;i++)
          {
             int j=i+length-1;
             for(int k=i;k<=j;k++)
             {
                 dp[i][j]=max(dp[i][j] ,  dp[i][k-1] + B[i-1]*B[k]*B[j+1] + dp[k+1][j]);
             }
          }
    }
    return dp[1][n];
}
int main()
{
    int A[]={1,2,3,4,5};
    int n=sizeof(A)/sizeof(A[0]);
    cout<<"\nmax coin= "<<getmaxCost(A,n);
    return 0;
}
