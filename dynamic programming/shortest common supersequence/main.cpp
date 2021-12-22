#include <bits/stdc++.h>
using namespace std;
#define max 20
int dp[max][max];
string super_sequence(string x,string y,int m,int n)
{
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        dp[i][0]=i;
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
              dp[i][j]=1+dp[i-1][j-1];
            else
              dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    int index=dp[m][n];
    cout<<index<<endl;
    string str;

    int i=m,j=n;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            str.push_back(x[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            str.push_back(y[j-1]);
            j--;
        }
        else
        {
            str.push_back(x[i-1]);
            i--;
        }
    }
    while(i>0)
    {
        str.push_back(x[i-1]);
        i--;
    }
    while(j>0)
    {
        str.push_back(y[j-1]);
        j--;
    }
    reverse(str.begin(),str.end());
    return str;
}

int main()
{
    string x="AGGTAB";
    string y="GXTXAYB";
    cout<<"\nshortest common supersequence: "<<super_sequence(x,y,x.length(),y.length());
    return 0;
}
