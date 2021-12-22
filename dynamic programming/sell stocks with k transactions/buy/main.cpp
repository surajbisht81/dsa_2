#include <bits/stdc++.h>
using namespace std;

//  this is not efficient solution;
/*int maxProfit(int price[],int n,int k)
{
    int T[k+1][n];

    for(int i=0;i<=k;i++)
        T[i][0]=0;
    for(int i=0;i<n;i++)
        T[0][i]=0;

    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<n;j++)
        {
            int temp=INT_MIN;
            for(int m=0;m<j;m++)
            {
               temp= max(temp,price[j]-price[m]+T[i-1][m]);
            }
            T[i][j]=max(T[i][j-1],temp);
        }
    }
    return T[k][n-1];
}*/

// this is 2nd method or efficient method
int maxProfit(int price[],int n,int k)
{
    int T[k+1][n];
    for(int i=0;i<n;i++)
        T[0][i]=0;
    for(int i=0;i<=k;i++)
        T[i][0]=0;

   for(int i=1;i<=k;i++)
   {
        int maxdiff=-price[0];
       for(int j=1;j<n;j++)
       {
          T[i][j]=max(T[i][j-1],price[j]+maxdiff);
          maxdiff=max(maxdiff,T[i-1][j]-price[j]);
       }
   }
    return T[k][n-1];
}
int main()
{
     int price[] = { 100, 180, 260, 310,
                    40, 535, 695 };
     int n=sizeof(price)/sizeof(price[0]);
     int k=3;
     cout<<"\nmax profit ="<<maxProfit(price,n,k);
     return 0;
}
