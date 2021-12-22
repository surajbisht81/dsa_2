/*Given a matrix that is filled with ‘O’, ‘G’, and ‘W’ where ‘O’ represents open space, ‘G’ represents guards and ‘W’ represents walls in a Bank.
 Replace all of the O’s in the matrix with their shortest distance from a guard, without being able to go through any walls. Also, replace the guards with 0 and 
walls with -1 in output matrix.
Expected Time complexity is O(MN) for a M x N matrix.*/

#include <bits/stdc++.h>
using namespace std;
#define N 5

int row[]={1, 0, -1, 0};
int col[]={0, 1, 0, -1};
struct queuenode
{
    int i, j, dist;
};

bool isSafe(int x, int y, char matrix[][N], int output[][N])
{
    if(x<0 or x>=N or y<0 or y>=N or matrix[x][y]=='W' or output[x][y]!=-1)
        return false;
    return true;
}

void ShortestDistance(char matrix[][N])
{
    int output[N][N];
    queue<queuenode> qu;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            output[i][j]=-1;

            if(matrix[i][j]=='G')
                {
                    queuenode pos = {i, j, 0};
                    qu.push(pos);
                    output[i][j]=0;
                }
        }
    }

    while(!qu.empty())
    {
        queuenode p = qu.front();
        qu.pop();
        int x=p.i, y=p.j, dist=p.dist;

        for(int i=0; i<4; i++)
        {
            if(isSafe(p.i+row[i], p.j+col[i], matrix, output))
              {
                    output[x+row[i]][y+col[i]]=dist+1;
                    queuenode pos = {x+row[i], y+col[i], dist+1};
                    qu.push(pos);
              }
        }
    }

    for(int i=0; i<N; i++)
    {
        cout<<endl;
        for(int j=0; j<N; j++)
        {
            cout<<setw(3)<<output[i][j];
        }
    }
}

int main()
{
 char matrix[][N] =
    {
        {'O', 'O', 'O', 'O', 'G'},
        {'O', 'W', 'W', 'O', 'O'},
        {'O', 'O', 'O', 'W', 'O'},
        {'G', 'W', 'W', 'W', 'O'},
        {'O', 'O', 'O', 'O', 'G'}
    };

    ShortestDistance(matrix);
    return 0;
}
