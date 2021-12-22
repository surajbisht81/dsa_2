#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll countways(int n,int k)
{
    ll total=0;
    if(n==0)
        return 0;
    if(n==1)
        return k;

    //this is for 2 posts or dp[2];
    ll same=k;
    ll diff=k*(k-1);

    // for more than 2 posts;
    for(int i=3;i<=n;i++)
    {
        ll prevdiff=diff;
        diff= (same + diff)*(k-1);
        same= prevdiff *1;
    }
    total=same+diff;
    return total%mod;
}
int main()
{
    int n,k;
    cout<<"\n enter n posts and k colors:";
    cin>>n>>k;
    cout<<"\n no of ways are:"<<countways(n,k);
    return 0;
}
