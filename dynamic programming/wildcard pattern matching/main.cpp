#include <bits/stdc++.h>
using namespace std;

bool wildcard_pattern(string text,string pattern)
{
    int n=text.length();
    int m=pattern.length();
    int dp[n+1][m+1];

    dp[0][0]=true;
    for(int i=1;i<=n;i++)
        dp[i][0]=false;
    for(int i=1;i<=m;i++)
    {
        dp[0][i]=false;
    }
    if(pattern[0]=='*')
        dp[0][1]=true;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(text[i-1]==pattern[j-1])
                dp[i][j]=dp[i-1][j-1];
            else if(pattern[j-1]=='?')
                dp[i][j]=dp[i-1][j-1];
            else if(pattern[j-1]=='*')
                dp[i][j]=dp[i][j-1] or dp[i-1][j];
            else
                dp[i][j]=false;
        }
    }
    return dp[n][m];
}

int main()
{
    string text="baaabab";
    string pattern="a*ab";
    if(wildcard_pattern(text,pattern))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
