#include <bits/stdc++.h>
using namespace std;
int min(int a,int b,int c)
{
    if(a<b && a<c)
        return a;
    else if(b<a && b<c)
        return b;
    else
        return c;
}
int max(int a,int b)
{
    return a>b?a:b;
}

int max_size_squareof1(int **matrix,int m,int n)
{
    int table[m][n];
    int maxx=0;
    for(int i=0;i<m;i++)
       table[i][0]=matrix[i][0];

    for(int j=0;j<n;j++)
       table[0][j]=matrix[0][j];

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(matrix[i][j]==0)
                table[i][j]=0;
            else
              table[i][j]=min(table[i-1][j],table[i-1][j-1],table[i][j-1])+1;

            maxx=max(maxx,table[i][j]);
        }
    }
    return maxx;
}
int main()
{
    int m,n;
    cout<<"\nenter row and column:";
    cin>>m>>n;
    int **matrix=new int*[m];
    for(int i=0;i<m;i++)
        matrix[i]=new int[n];
    cout<<"\nenter matrix:\n";
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];

    cout<<"\nmax sub-square is:"<<max_size_squareof1(matrix,m,n);
    return 0;
}
