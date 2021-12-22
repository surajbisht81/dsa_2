/*Last Updated: 28-09-2018
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up
 the rod and selling the pieces. For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)


length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20*/

#include <bits/stdc++.h>
using namespace std;

//using recursion
/*int maxProfit(int arr[],int n)
{
    if(n==0)
        return 0;

    int res=0;
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        res=maxProfit(arr,n-i);
        res+=arr[i-1];
        if(maxx<res)
            maxx=res;
    }
    return maxx;
}
int main()
{
    int arr[]={3,5,8,9,10,17,17,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nmax profit= "<<maxProfit(arr,n);
    return 0;
}
*/
int maxProfit(int arr[],int n)
{
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    dp[1]=arr[0];

    for(int i=2;i<=n;i++)
    {
        int maxx=0;
      for(int j=1;j<=i;j++)
      {
          int temp=arr[j-1]+dp[i-j];
          if(maxx<temp)
            maxx=temp;
      }
      dp[i]=maxx;
    }
    return dp[n];
}
int main()
{
    int arr[]={3,5,8,9,10,17,17,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nmax profit= "<<maxProfit(arr,n);
    return 0;
}
