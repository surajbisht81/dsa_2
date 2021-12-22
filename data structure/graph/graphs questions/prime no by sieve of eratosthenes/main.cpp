#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void sieveoferatosthenes(int n)
{
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(int p=2; p*p<=n;p++)
    {
        if(prime[p]==true)
        {
            for(int i=2; p*i<=n; i++)
                prime[p*i]=false;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        cout<<"\t"<<i;
    }
}
int main()
{
    int n=30;
    cout<<"\nprime no equal to n or less than n are:\n";
    sieveoferatosthenes(n);
    return 0;
}
