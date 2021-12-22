#include <bits/stdc++.h>
using namespace std;

int solve(int A[], int n)
{
    int cnt=0;
    int visit[n+1];
    int parent[n+1];

    memset(visit, 0, sizeof(visit));
    memset(parent, -1, sizeof(parent));

    for(int i=0; i<n; i++)
    {
        int j = i;

        while(parent[j]==-1)
        {
            parent[j]=i;
            j = (j+A[j]+1)%n;
        }

        if(parent[j]==i)
        {
            while(!visit[j])
            {
                visit[j]=1;
                cnt++;
                j = (j+A[j]+1)%n;
            }
        }
    }
    return cnt;
}
int main()
{
    int A[] = { 0, 0, 0, 2 };
    int n = sizeof(A)/sizeof(A[0]);

    cout<<solve(A, n);
    return 0;
}
