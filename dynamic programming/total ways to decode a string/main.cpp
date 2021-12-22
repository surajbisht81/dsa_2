#include <bits/stdc++.h>
using namespace std;
// using recursion;
/*int countDecoding(char str[],int n,int pos)
{
    int count=0;
    //base case
    if(n==0 or n==1)
        return 1;
     if(str[0]=='0')
        return 0;

     if(str[pos]>'0')
        count=countDecoding(str,n-1,pos+1);
     if(str[pos]=='1' or (str[pos]=='2' && str[pos+1]<'7'))
        count+=countDecoding(str,n-2,pos+2);
     return count;
}
int main()
{
    char str[]="1723";
    int n=strlen(str);
    cout<<"count= "<<countDecoding(str,n,0);
    return 0;
}*/


//using dynamic programming
int countDecoding(char str[],int n)
{
    int dp[n+1];
    dp[0]=dp[1]=1;

    if(str[0]=='0')
        return 0;
    for(int i=2;i<=n;i++)
    {
        dp[i]=0;

       if(str[i-1]>'0')
        dp[i]=dp[i-1];

       if(str[i-2]=='1' or (str[i-2]=='2' and str[i-1]<'7'))
        dp[i]+=dp[i-2];
    }
    return dp[n];
}
int main()
{
    char str[]="1723";
    int n=strlen(str);
    cout<<"count= "<<countDecoding(str,n);
    return 0;
}
