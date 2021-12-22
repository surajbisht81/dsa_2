#include <bits/stdc++.h>
using namespace std;

// this is recursion approach or top down approach
int countWays(int n)
{
    if(n<=1)
      return 1;
    int res=0;
    res=countWays(n-1) +countWays(n-2);
    return res;
}

int main()
{
    int n;
    cout<<"\nenter no of stairs:";
    cin>>n;
    cout<<"\nno of ways="<<countWays(n);
    return 0;
}

// this is dp or bottom up manner approach
/*int countWays(int n)
{
     int fb[n+1];
    fb[0]=fb[1]=1;

    for(int i=2;i<=6;i++)
    {
        fb[i]=fb[i-1]+fb[i-2];
    }
    return fb[n];
}

int main()
{
    int n;
    cout<<"\nenter no of stairs:";
    cin>>n;
    cout<<"\nno of ways="<<countWays(n);
    return 0;
}
*/
