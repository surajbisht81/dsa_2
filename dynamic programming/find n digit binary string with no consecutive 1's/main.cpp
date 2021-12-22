#include <bits/stdc++.h>
using namespace std;
//using recursion;
/*int total_strings(int n,int last_digit)
{
    if(n==0)
        return 0;
    if(n==1)  // if only one digit is left
    {
        if(last_digit)
            return 1;
        else
            return 2;
    }
    if(last_digit==0)
        return total_strings(n-1,0)+total_strings(n-1,1);// if digit==0,we can put either 0 or 1;
    else
        return total_strings(n-1,0);// if digit==1, we can only put 0 to avoid consecutive 1
}
int main()
{
    int n;
    cin>>n;
    cout<<"\ntotal string :"<<total_strings(n,0);// we are passing 0 becoz we have to put 1 and 0 at nth digit;
    return 0;
}*/

//using dynamic programming

int total_strings(int n,int last_digit)
{
    int dp[n+1][2];//first state is for pos of digit and second state is for either 0 or 1;
    dp[0][0]=dp[0][1]=0;
    dp[1][0]=2,dp[1][1]=1;

    for(int i=2;i<=n;i++)
    {
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    return dp[n][0];
}
int main()
{
    int n;
    cin>>n;
    cout<<"\ntotal strings are :"<<total_strings(n,0);
    return 0;
}
