#include <bits/stdc++.h>
using namespace std;
#define max 20
int dp[max][max];

void Diff_utility(string str1,string str2,int m,int n)
{
    if(m>0 && n>0 && str1[m-1]==str2[n-1])
    {
        Diff_utility(str1,str2,m-1,n-1);
        cout<<" "<<str1[m-1];
    }

    else if(m>0 &&(n==0 || dp[m][n-1]>=dp[m-1][n]))
    {
        Diff_utility(str1,str2,m,n-1);
        cout<<"-"<<str2[n-1];
    }
    else if(n>0 && (m==0 || dp[m-1][n]>dp[m][n-1]))
    {
        Diff_utility(str1,str2,m-1,n);
        cout<<"+"<<str1[m-1];
    }
}
int maxx(int a,int b)
{
    return a>b?a:b;
}
void lcs_length(string str1,string str2,int m,int n)
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=maxx(dp[i-1][j],dp[i][j-1]);
        }
    }
}
int main()
{
    string str1="XMJYAUZ";
    string str2="XMJAATZ";
    int m=str1.length();
    int n=str2.length();
    lcs_length(str1,str2,m,n);

    Diff_utility(str1,str2,m,n);
    return 0;
}

