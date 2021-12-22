#include <bits/stdc++.h>
using namespace std;

int noofways(int coins[],int W,int n)
{
   int i,j;
   int ways[n+1][W+1];

   for(i=0;i<=n;i++)
     ways[i][0]=1;
   for(i=0;i<=W;i++)
      ways[0][i]=0;

   for(i=1;i<=n;i++)
   {
       for(j=1;j<=W;j++)
       {
           if(coins[i-1]>j)
             ways[i][j]=ways[i-1][j];
           else
           {
               ways[i][j]=ways[i-1][j]+ways[i][j-coins[i-1]];
           }
       }
   }
   return ways[n][W];
}
int main()
{
    int coins[]={3,5,10};
    int n=sizeof(coins)/sizeof(coins[0]);
    int W=13;
    cout<<"no of ways to calculate given sum="<<noofways(coins,W,n);
    return 0;
}
