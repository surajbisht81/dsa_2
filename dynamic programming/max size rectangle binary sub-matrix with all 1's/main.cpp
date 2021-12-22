#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

int maxHist(int hist[])
{
    stack<int>s;
    int i=0;
    int top,max_area=0;

    while(i<C)
    {
        if(s.empty() or hist[s.top()]<=hist[i])
            s.push(i++);
        else
        {
            top=s.top();
            s.pop();
            max_area=hist[top]*(s.empty()?i:i-s.top()-1);
        }
    }
        while(!s.empty())
        {
            top=s.top();
            s.pop();
            max_area=hist[top]*(s.empty()?i:i-s.top()-1);
        }
        return max_area;
}
int maxRectangle(int A[][C])
{
    int maxx=maxHist(A[0]);

    for(int i=1;i<R;i++)
    {
        for(int j=0;j<C;j++)
            if(A[i][j]!=0)
             A[i][j]+=A[i-1][j];
        maxx=max(maxx,maxHist(A[i]));
    }
    return maxx;
}
int main()
{
    int A[][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 }};
    cout<<"\nmax rectangle area:"<<maxRectangle(A);
    return 0;
}
