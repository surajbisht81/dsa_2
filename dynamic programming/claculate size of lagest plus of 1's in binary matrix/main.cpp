#include <bits/stdc++.h>
using namespace std;

#define N 10
int min(int a,int b)
{
    return a<b?a:b;
}
int minn(int a,int b,int c,int d)
{
    return min(min(a,b),min(c,d));
}
int largest_plus(int grid[N][N])
{
    int top[N][N],bottom[N][N],right[N][N],left[N][N];
    memset(top,0,sizeof(top));
    memset(bottom,0,sizeof(bottom));
    memset(right,0,sizeof(right));
    memset(left,0,sizeof(left));

        for(int i=0;i<N;i++)
        {
            top[0][i]=grid[0][i];
            bottom[N-1][i]=grid[N-1][i];

            right[i][N-1]=grid[i][N-1];
            left[i][0]=grid[i][0];
        }

        for(int i=1;i<N;i++)
        {
            for(int j=1;j<N;j++)
            {
                if(grid[i][j]==1)
                    top[i][j]=top[i-1][j]+1;

                if(grid[i][j]==1)
                    left[i][j]=left[i][j-1]+1;

                if(grid[N-1-j][i]==1)
                    bottom[N-1-j][i]=bottom[N-j][i]+1;

                if(grid[i][N-1-j]==1)
                   right[i][N-1-j]=right[i][N-j]+1;
            }
        }
    int res=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int len=minn(top[i][j],bottom[i][j],right[i][j],left[i][j]);
            if(len>=res)
                res=len-1;
        }
    }
    return res;
}
int main()
{
     int grid[N][N] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
        { 1, 1, 0, 0, 1, 0, 1, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
    };
    int bar=largest_plus(grid);
    if(bar)
        cout<<"\nmax size of plus is :"<<4*bar +1;
    else
        cout<<"\nno plus is present.";
    return 0;
}
