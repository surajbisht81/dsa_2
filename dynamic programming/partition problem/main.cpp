#include <bits/stdc++.h>
using namespace std;

int **dp;
void printsets(vector<int>v)
{
   for(int i=0;i<v.size();i++)
   {
       cout<<v[i]<<" ";
   }
   cout<<endl;
}
void all_subsets(int arr[],int i,int sum,vector<int>p)
{
    if(i==0 && sum && dp[0][sum])
    {
        p.push_back(arr[i]);
        printsets(p);
        return;
    }
    if(i==0 && sum==0)
    {
        printsets(p);
        return;
    }
    if(dp[i-1][sum])
    {
       // vector<int>b=p;
        all_subsets(arr,i-1,sum,p);
    }
    if(arr[i]<=sum && dp[i-1][sum-arr[i]])
    {
        p.push_back(arr[i]);
        all_subsets(arr,i-1,sum-arr[i],p);
    }
}
void  issubset_possible(int arr[],int n,int sum)
{
  dp=new int*[n];
  for(int i=0;i<n;i++)
  {
      dp[i]=new int[sum+1];
      dp[i][0]=1;
  }

   if(arr[0]<=sum)
    dp[0][arr[0]]=1;

   for(int i=1;i<n;i++)
   {
       for(int j=1;j<=sum;j++)
       {
           if(arr[i]>j)
            dp[i][j]=dp[i-1][j];
           else
            dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i]];
       }
   }
   vector<int>p;
   if(dp[n-1][sum])
    all_subsets(arr,n-1,sum,p);
    else
        cout<<"\nno subsets are possible.";
}
int main()
{
    int arr[]={1,5,11,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    for(int x:arr)
        sum+=x;
    issubset_possible(arr,n,sum/2);
    return 0;
}
