#include<bits/stdc++.h>
using namespace std;
#define M 5
int findmax_point(int mat[M][M],int i,int j)
{
    if(i<0 or i>=M or j<0 or j>=M or mat[i][j]==-1)
        return 0;
    int res=0;
    if(i&1)
       res=mat[i][j]+ max(findmax_point(mat,i,j-1),findmax_point(mat,i+1,j));

    else
        res=mat[i][j]+max(findmax_point(mat,i,j+1),findmax_point(mat,i+1,j));
    return res;
}
int main()
{
    int mat[M][M]={
         {1,1,-1,1,1},
         {1,0,0,-1,1},
         {1,1,1,1,-1},
         {-1,-1,1,1,1},
         {1,1,-1,-1,1}
         };
    cout<<"\nmax points are :"<<findmax_point(mat,0,0);
    return 0;
}

/*
 //dynamic programming solution

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// M x N matrix
#define M 5
#define N 5

// Function to collect maximum value from the first cell (0, 0)
int findMaximum(int mat[M][N])
{
	// T[i][j] stores maximum value that can be collected
	// from any cell to cell (i-1, j-1)
	int T[M+1][N+1];
	memset(T, 0, sizeof T);

	// process each row one by one and fill lookup table T[][]
	for (int i = 1; i<= M; i++)
	{
		// handle odd and even row separately
		if (i & 1)
		{
			// process current row from left to right
			for (int j = 1; j <= N; j++)
			{
				if (mat[i-1][j-1] == -1)
					T[i][j] = 0;
				else
					T[i][j] = mat[i-1][j-1] + max(T[i][j-1], T[i-1][j]);
			}
		}
		else
		{
			// process current row from right to left
			for (int j = N; j >= 1; j--)
			{
				if (mat[i-1][j-1] == -1)
					T[i][j] = 0;
				else
					T[i][j] = mat[i-1][j-1] + max(T[i][j+1], T[i-1][j]);
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << T[i][j] << " ";
		cout << endl;
	}

	
	int maxim = -1;
	for(int i=0; i<=M; i++)
	{
	    for(int j=0; j<=N; j++)
	    {
	        if(T[i][j]>maxim)
	         maxim = T[i][j];
	    }
	}

	return maxim;
}

int main()
{
	int mat[M][N] =
	{
		{  1,  1, -1,  1,  1 },
		{  1,  0,  0, -1,  1 },
		{  1,  1,  1,  1, -1 },
		{ -1, -1,  1,  1,  1 },
		{  1,  1, -1, -1,  1 }
	};

	cout << "Maximum value collected is " << findMaximum(mat);

	return 0;
}
*/