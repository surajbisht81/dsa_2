#include <iostream>

using namespace std;
int max(int a,int b)
{
    return (a>b)?a:b;
}
int eggDrop(int n,int k)
{
    int res,i,j,x;
    int egg[n+1][k+1];

    for(i=1;i<=n;i++)
    {
        egg[i][0]=0;
        egg[i][1]=1;
    }
    for(j=0;j<=k;j++)
    {
        egg[0][j]=0;
        egg[1][j]=j;
    }

    for(i=2;i<=n;i++)
    {
        for(j=2;j<=k;j++)
        {
            egg[i][j]=INT_MAX;
            for(x=1;x<=j;x++)
            {
                res=1+max(egg[i-1][x-1],egg[i][j-x]);
                if(res<egg[i][j])
                    egg[i][j]=res;
            }
        }
    }
    return egg[n][k];
}
int main()
{
    int n = 2, k = 36;
    cout<<"\nMinimum number of trials in worst case with"<<n<<" eggs and "
             <<k<<"floors is \n"<< eggDrop(n, k);
    return 0;
}
