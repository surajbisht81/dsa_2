#include <bits/stdc++.h>
using namespace std;

int min(int a ,int b)
{
    return (a<b)?a:b;
}
int min_no_of_coins(int coin[],int W,int n)
{
    int res[n+1][W+1];
    int i,j;
    for(i=0;i<=n;i++)
        res[i][0]=0;
    for(i=0;i<=W;i++)
        res[0][i]=i;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=W;j++)
        {
            if(coin[i-1]>j)
                res[i][j]=res[i-1][j];
            else
                res[i][j]=min(res[i-1][j],1+res[i][j-coin[i-1]]);
        }
    }
    return res[n][W];
}
int main()
{
    int coin[]={2,5,6};
    int W=2;
    int n=sizeof(coin)/sizeof(coin[0]);
    cout<<"min no of coins required="<<min_no_of_coins(coin,W,n);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int min(int a ,int b)
{
    return (a<b)?a:b;
}
int min_no_of_coins(int coin[],int W,int n)
{
    int res[n+1][W+1];
    int i,j;
    for(i=0;i<=n;i++)
        res[i][0]=0;
    for(i=1;i<=W;i++)
        res[0][i]=9999;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=W;j++)
        {
            if(coin[i-1]>j and coin[i-1]<=W )
                res[i][j]=res[i-1][j];
            else if(coin[i-1]<=W)
                res[i][j]=min(res[i-1][j],1+res[i][j-coin[i-1]]);
        }
    }
    return res[n][W];
}
int main()
{
    int coin[]={12, 13};
    int W=11;
    int n=sizeof(coin)/sizeof(coin[0]);
    cout<<"min no of coins required="<<min_no_of_coins(coin,W,n);
    return 0;
}
*/
