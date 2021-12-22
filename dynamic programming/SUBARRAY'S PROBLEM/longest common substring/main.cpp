#include <bits/stdc++.h>
using namespace std;

void lcs(string str1,string str2)
{
    int n=str1.length();
    int m=str2.length();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));

    int maxx=INT_MIN;
    int ending_index=n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                if(maxx<dp[i][j])
                {
                     maxx=dp[i][j];
                     ending_index=i;
                }
            }
        }
    }
    string res=str1.substr(ending_index-maxx,maxx);
    cout<<res;
}
int main()
{
    string str1="abcdaf";
    string str2="zbcdf";
    lcs(str1,str2);
    return 0;
}
