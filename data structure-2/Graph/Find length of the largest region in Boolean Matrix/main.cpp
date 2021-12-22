/*Consider a matrix with rows and columns, where each cell contains either a ‘0’ or a ‘1’ and any cell containing a 1 is called a filled cell. Two cells are said
 to be connected if they are adjacent to each other horizontally, vertically, or diagonally. If one or more filled cells are also connected, they form a region.
 find the length of the largest region.*/


#include <bits/stdc++.h>
using namespace std;
#define Row 4
#define Col 5

bool isSafe(int x, int y, int M[][Col], bool visit[][Col])
{
    return (x>=0 and x<Row and y>=0 and y<Col and M[x][y]!=0 and visit[x][y]==false);
}

void DFS(int M[][Col], int x, int y, bool visit[][Col], int &count)
{
    int xmove[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int ymove[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    visit[x][y]=true;
    for(int k=0; k<8; k++)
    {
        if(isSafe(x+xmove[k], y+ymove[k], M, visit))
        {
            count++;
            DFS(M, x+xmove[k], y+ymove[k], visit, count);
        }
    }
}
int largestRegion(int M[][Col])
{
   bool visit[Row][Col];
   memset(visit, false, sizeof(visit));

   int ans=INT_MIN;
   int count;
   for(int i=0; i<Row; i++)
   {
       for(int j=0; j<Col; j++)
       {
          if(!visit[i][j] and M[i][j]!=0)
          {
              count=1;
              DFS(M, i, j, visit, count);
              ans=max(ans, count);
          }
       }
   }
   return ans;
}

int main()
{
    int M[][Col] =  { { 0, 0, 1, 1, 0 },
                     { 1, 0, 1, 1, 0 },
                     { 0, 1, 0, 0, 0 },
                     { 0, 0, 0, 0, 1 } };
    cout<<"\nlargest region :"<<largestRegion(M);
    return 0;
}
