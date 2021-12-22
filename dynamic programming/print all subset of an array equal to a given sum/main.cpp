#include <bits/stdc++.h>
using namespace std;

bool **dp;
void printsubsets(vector<int>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void find_subsets(int arr[],int i,int sum,vector<int>p)
{
    if(i==0 && sum!=0 && dp[0][sum])
    {
        p.push_back(arr[i]);
        printsubsets(p);
        return ;
    }
    if(i==0 && sum==0)
    {
        printsubsets(p);
        return ;
    }

    if(dp[i-1][sum])
    {
        vector<int>b=p;
        find_subsets(arr,i-1,sum,b);
    }
    if(sum>=arr[i] && dp[i-1][sum-arr[i]])
    {
        p.push_back(arr[i]);
        find_subsets(arr,i-1,sum-arr[i],p);
    }
}
void total_subsets(int arr[],int n,int sum)
{
    dp=new bool*[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=new bool[sum+1];
        dp[i][0]=true;
    }
    if(arr[0]<=sum)
    dp[0][arr[0]]=true;

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            dp[i][j]= arr[i]>j? dp[i-1][j] : dp[i-1][j] or dp[i-1][j-arr[i]];
        }
    }
    vector<int>p;
    if(dp[n-1][sum]==false)
        cout<<"\nno subsets are present.";
    else
    find_subsets(arr,n-1,sum,p);
}
int main()
{
    int arr[]={1,5,5,11};
    int sum=11;
    int n=sizeof(arr)/sizeof(arr[0]);
    total_subsets(arr,n,sum);
    return 0;
}
