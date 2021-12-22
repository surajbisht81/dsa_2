#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 4

int mincost(int matrix[][C])
{
    int temp[R][C];
    temp[0][0]=matrix[0][0];
    for(int i=1;i<C;i++)
        temp[0][i]=matrix[0][i]+temp[0][i-1];

    for(int i=1;i<R;i++)
        temp[i][0]=matrix[i][0]+temp[i-1][0];

    for(int i=1;i<R;i++)
    {
        for(int j=1;j<C;j++)
        {
            temp[i][j]=min(matrix[i][j]+temp[i-1][j],matrix[i][j]+temp[i][j-1]);
        }
    }
    return temp[R-1][C-1];
}
int main()
{
    int matrix[R][C]={{1,3,5,8},{4,2,1,7},{4,3,2,3}};
    cout<<"\nmin cost= "<<mincost(matrix);
    return 0;
}
