#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 5

int kedanes(int row[],int *start,int *finish)
{
    int max_so_far=0,max_ending_here=0;
    int s=0;

    for(int i=0;i<R;i++)
    {
        max_ending_here+=row[i];
        if(max_ending_here>max_so_far)
        {
            max_so_far=max_ending_here;
            *start=s;
            *finish=i;
        }
        if(max_ending_here<0)
        {
            max_ending_here=0;
            s=s+i;
        }
    }
    return max_so_far;
}
void findmax_sum(int M[][C])
{
    int row[R];
    int maxleft,maxright,maxup,maxdown;
    int start,finish;

    int sum=0,maxx=INT_MIN;
    for(int i=0;i<C;i++)
    {
        memset(row,0,sizeof(row));
        for(int j=i;j<C;j++)
        {
            for(int k=0;k<R;k++)
                row[k]+=M[k][j];

            sum=kedanes(row,&start,&finish);

            if(sum>maxx)
            {
                 maxx=sum;
                 maxleft=i;
                 maxright=j;
                 maxup=start;
                 maxdown=finish;
            }
        }
    }
    cout<<"\nstarting top-left of rectangle is ="<<maxup+1<<","<<maxleft;
    cout<<"\nstarting down-bottom of rectangle is ="<<maxdown<<","<<maxright;
    cout<<"\nmax sum of rectangle is ="<<maxx;
}
int main()
{
    int M[R][C]={{1, 2, -1, -4, -20},
                 {-8, -3, 4, 2, 1},
                 {3, 8, 10, 1, 3},
                 {-4, -1, 1, 7, -6}};
  findmax_sum(M);
  return 0;
}
