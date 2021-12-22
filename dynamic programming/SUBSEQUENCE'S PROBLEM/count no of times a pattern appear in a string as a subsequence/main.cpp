#include <bits/stdc++.h>

using namespace std;
/*
int totalCount(string X,string Y,int m,int n)
{
    // base cases
    if(m==0 &&n==0)
        return 1;
    if(m==0 && n!=0)
        return 0;
    if(n==0 && m!=0)
        return 1;

    if(X[m-1]==Y[n-1])
        return totalCount(X,Y,m-1,n-1)+totalCount(X,Y,m-1,n);
    else
        return totalCount(X,Y,m-1,n);

}
int main()
{
    string str="GeeksforGeeks";
    string patt="Gks";
    int m=str.length();
    int n=patt.length();
    cout<<"\n total no of times patt appear in string str :"<<totalCount(str,patt,m,n);
    return 0;
}*/

//using dp
int totalCount(string X,string Y,int m,int n)
{
    int dp[m+1][n+1]={{0}};  // first state representing string X and 2nd string Y

    for(int i=0;i<=n;i++)
        dp[0][i]=0;
    for(int i=0;i<=m;i++)
        dp[i][0]=1;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1])
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[m][n];
}
int main()
{
    string str="Geeks";
    string patt="Gks";
    int m=str.length();
    int n=patt.length();
    cout<<"\n total no of times patt appear in string str :"<<totalCount(str,patt,m,n);
    return 0;
}
//Time complexity of above solutions is O(MN).
//Auxiliary space used by the program is O(MN).
