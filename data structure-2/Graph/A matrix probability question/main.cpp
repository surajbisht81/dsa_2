/*Given a rectangular matrix, we can move from current cell in 4 directions with equal probability.
 The 4 directions are right, left, top or bottom. Calculate the Probability that after N moves from a given position
 (i, j) in the matrix, we will not cross boundaries of the matrix at any point.*/

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int m, int n)
{
    return (x>=0 and x<m and y>=0 and y<n);
}
double findprobability(int m, int n, int N, int x, int y)
{
    if(!isSafe(x, y, m, n))
        return 0.0;

    if(N==0)
        return 1.0;

    double ans=0.0;

    ans+= findprobability(m, n, N-1, x+1, y)*0.25;
    ans+= findprobability(m, n, N-1, x-1, y)*0.25;
    ans+= findprobability(m, n, N-1, x, y+1)*0.25;
    ans+= findprobability(m, n, N-1, x, y-1)*0.25;
    return ans;
}

int main()
{
    int m=5, n=5;
    int N=2;

    int x=1, y=1;

    cout<<findprobability(m, n, N, x, y);
    return 0;
}
