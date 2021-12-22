/*There is a m*n rectangular matrix whose top-left(start) location is (1, 1) and bottom-right(end) location is (m*n). There are k circles each with radius r.
 Find if there is any path from start to end without touching any circle.

The input contains values of m, n, k, r and two array of integers X and Y, each of length k. (X[i], Y[i]) is the centre of ith circle.*/

#include<bits/stdc++.h>
using namespace std;

bool isvalid(int x, int y, int A, int B)
{
    if(x<0 or x>A or y<0 or y>B)
     return false;
    return true;
}

bool liesInCircle(int x, int y, int C, int D, vector<int> &E, vector<int> &F) // C is no of circles and D is Radius of each circle.
{
      for(int i=0; i<C; i++)
      {
          int first = x-E[i];
          int second = y-F[i];
          if( (first*first)+(second*second)<=D*D)
            return true;
      }
      return false;
}

string Solution(int A, int B, int C, int D, vector<int> &E, vector<int> &F)
{
    bool visit[A+1][B+1];
    memset(visit, false, sizeof(visit));

    queue<pair<int, int>> qu;
    qu.push(make_pair(0, 0));

    visit[0][0]=true;

    if(liesInCircle(0, 0, C, D, E, F))
     return "NO";


    int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int col[] = {-1,  0,  1, -1,1, -1, 0, 1};

    while(!qu.empty())
    {
        pair<int, int> temp = qu.front();
        qu.pop();

        int x = temp.first;
        int y = temp.second;

        for(int i=0; i<8; i++)
        {
            int next_row=x+row[i], next_col=y+col[i];
            if(isvalid(next_row, next_col , A, B) and !liesInCircle(next_row, next_col, C, D, E, F) and !visit[next_row][next_col])
             {
                visit[next_row][next_col]=true;
                qu.push(make_pair(next_row, next_col));
             }
        }
    }
    if(visit[A][B])
     return "YES";
    else
    return "NO";
}

int main()
{
  int m1 = 5, n1 = 5, k1 = 2, r1 = 1;
  vector<int> X1 = {1, 3};
  vector<int> Y1 = {3, 3};
  cout<<Solution(m1, n1, k1, r1, X1, Y1);
  return 0;
}
