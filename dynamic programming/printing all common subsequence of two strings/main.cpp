#include <bits/stdc++.h>
using namespace std;

#define max 20
int dp[max][max];
string lcs(string x,string y,int n,int m)
{
    if(n==0 or m==0)
        return string(" ");
    if(x[n-1]==y[m-1])
        return lcs(x,y,n-1,m-1)+x[n-1];

    if(dp[n-1][m]>dp[n][m-1])
        return lcs(x,y,n-1,m);
    else
        return lcs(x,y,n,m-1);
}
int maxx(int a,int b)
{
    return a>b?a:b;
}
void lcs_length(string x,string y,int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=maxx(dp[i][j-1],dp[i-1][j]);
        }
    }
}
int main()
{
    string x="xmjyauz";
    string y="mzjawxu";
    int n=x.length();
    int m=y.length();
    lcs_length(x,y,n,m);
    cout<<lcs(x,y,n,m);
    return 0;
}
