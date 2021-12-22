/*Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position, i.e., any i’th 
character in the two subsequences shouldn’t have the same index in the original string.*/


#include <bits/stdc++.h>
using namespace std;

#define max 20
int dp[max][max];
string findstring(string str,int m,int n)
{
    if(n==0 or m==0)
        return string(" ");

    if(str[m-1]==str[n-1] && (m-1)!=(n-1))
       return  findstring(str,m-1,n-1)+str[m-1];
    else
    {
        if(dp[m-1][n]>dp[m][n-1])
             return findstring(str,m-1,n);
        else
            return findstring(str,m,n-1);
    }
}
int maxx(int a,int b)
{
    return a>b?a:b;
}
int length(string str,int n)
{

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str[i-1]==str[j-1] && i!=j)
             dp[i][j]= dp[i-1][j-1] +1;

            else
            dp[i][j]= maxx(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}
int main()
{
  string str="aabb";
  int n=str.length();

  cout<<"\nlength of repeating subsequence is: "<<length(str,n);
  cout<<"\nthe string is"<<findstring(str,n,n);
  return 0;
}
