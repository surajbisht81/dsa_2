#include <bits/stdc++.h>
using namespace std;

#define M 5
#define N 5
 pair<int,int> p;
pair<int,int> findmaxsumsubarray(int mat[M][N],int k)
{
    int sum[M][N];
    sum[0][0]=mat[0][0];
    for(int i=1;i<N;i++)
        sum[0][i]=mat[0][i]+sum[0][i-1];
    for(int i=1;i<M;i++)
        sum[i][0]=mat[i][0]+sum[i-1][0];
        //preprocessing part of matrix;
    for(int i=1;i<M;i++)
    {
        for(int j=1;j<N;j++)
        {
            sum[i][j]=mat[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }

    int maxx=INT_MIN,total=0;
    for(int i=k-1;i<M;i++)
    {
        for(int j=k-1;j<N;j++)
        {
            total=sum[i][j];
            if(j-k>=0)
                total-=sum[i][j-k];
            if(i-k>=0)
                total-=sum[i-k][j];
            if(i-k>=0 && j-k>=0)
                total+=sum[i-k][j-k];
            if(maxx<total)
            {
                maxx=total;
                p=make_pair(i,j);
            }
        }
    }
    return p;
}
int main()
{
    int mat[N][N] =
	{
		{ 3, -4, 6, -5, 1 },
		{ 1, -2, 8, -4, -2 },
		{ 3, -8, 9, 3, 1 },
		{ -7, 3, 4, 2, 7 },
		{ -3, 7, -5, 7, -6 }
	};
	int k=3;
	p=findmaxsumsubarray(mat,k);
	//cout<<"\nmax sum is :"<<total;
	cout<<"\nmatrix is :\n";
	for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            cout<<mat[p.first-(k-1)+i][p.second-(k-1)+j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
