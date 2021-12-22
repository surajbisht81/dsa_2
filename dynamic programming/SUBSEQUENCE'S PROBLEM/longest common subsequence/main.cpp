/* Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order,
 but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int max(int a,int b);
int lcs(string X, string Y, int m, int n)
{
    int l[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++)
    {
        for( j=0;j<=n;j++)
        {
            if(i==0 ||j==0)
                l[i][j]=0;
            else if(X[i-1]==Y[j-1])
                l[i][j]=l[i-1][j-1]+1;
            else
                l[i][j]=max(l[i-1][j],l[i][j-1]);
        }
    }
    return l[m][n];
}
int max(int a,int b)
{
   if(a>b)
    return a;
   else
    return b;
}
int main()
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    int m=str1.length();
    int n=str2.length();
    int len=lcs(str1, str2, m, n);
    cout<<"\nlength of lcs = "<<len;
    return 0;
}
