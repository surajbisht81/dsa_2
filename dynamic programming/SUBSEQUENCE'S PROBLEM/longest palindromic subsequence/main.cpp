/*Given a sequence, find the length of the longest palindromic subsequence in it.
 As another example, if the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest palindromic subsequence in it*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    return (a>b)?a:b;
}
int lps(char *str)
{
    int n=strlen(str);
    int L[n][n];

    memset(L,0,sizeof(L));
    int i,j,k;
    for(i=0;i<n;i++)
      L[i][i]=1;

    for(k=2;k<=n;k++)
    {
        for(i=0;i<n-k+1;i++)
        {
            j=i+k-1;
            if(str[i]==str[j])
                L[i][j]=L[i+1][j-1]+2;
            else
                L[i][j]=max(L[i][j-1],L[i+1][j]);
        }
    }
    return L[0][n-1];
}
int main()
{
    char seq[] = "abbdcacb";
    cout<<"The lnegth of the LPS is:"<<lps(seq);
    return 0;
}
