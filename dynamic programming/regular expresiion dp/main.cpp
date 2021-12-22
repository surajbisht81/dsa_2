#include <bits/stdc++.h>
using namespace std;

bool regular_exp(string text,string pattern)
{
    int n=text.length();
    int m=pattern.length();
    bool dp[n+1][m+1];
    dp[0][0]=true;

    // if a* or a*b* or a*b*c*
    for(int i=1;i<=m;i++)
    {
        if(pattern[i-1]=='*')
            dp[0][i]=dp[0][i-2];
        else
            dp[0][i]=false;
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=false;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(text[i-1]==pattern[j-1] or pattern[j-1]=='.')
                dp[i][j]=dp[i-1][j-1];

            else if(pattern[j-1]=='*')
             {
                dp[i][j] = dp[i][j-2];
                if(pattern[j-2]==text[i-1] or pattern[j-2]=='.')
                   dp[i][j]=dp[i][j] or dp[i-1][j];
             }
             else
               dp[i][j]=false;
        }
    }
    return dp[n][m];
}
int main()
{
    string text="xaabyc";
    string pattern="xa*b.c";
    if(regular_exp(text,pattern))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
