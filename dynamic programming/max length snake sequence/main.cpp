#include <bits/stdc++.h>
using namespace std;

#define M 5


vector<int> max_length(int i,int j,int grid[M][M],vector<int>&v)
{
    if(i==(M-1) && j==(M-1))
    {
        v.push_back(grid[i][j]);
        return v;
    }

            if(abs(grid[i][j]-grid[i+1][j])==1 && i+1<M)
            {
                v.push_back(grid[i][j]);
                max_length(i+1,j,grid,v);
            }
            if(abs(grid[i][j]-grid[i][j+1])==1 && j+1<M)
            {
                v.push_back(grid[i][j]);
                max_length(i,j+1,grid,v);
            }
            v.pop_back();
    return v;
}

int main()
{
    int grid[M][M] =
	{
		{ 7, 5, 2, 3, 1 },
		{ 3, 4, 1, 4, 4 },
		{ 1, 5, 6, 7, 8 },
		{ 3, 4, 5, 8, 9 },
		{ 3, 2, 2, 7, 6 }
	};
	int res=0,maxx=INT_MIN;
	vector<int>v,v_final;
   for(int i=0;i<M;i++)
    {
        for(int j=0;j<M;j++)
        {
            v= max_length(i,j,grid,v);
            res=v.size();
            if(res>maxx)
             {
                    maxx=res;
                    v_final=v;
             }
        }
    }
    cout<<"\nsnake is :\n";
    for(auto it=v_final.begin();it!=v_final.end();it++)
        cout<<*it<<" ";
  cout<<"\nmax length of snake is :"<<maxx;
}


/*
//using dp
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

// define size of square matrix
#define N 5

// pair to store snake's tail coordinates
typedef pair<int, int> Point;

// Construct maximum length snake sequence from given tail and L[] matrix
vector<Point> constructPath(int L[][N], int grid[][N], Point tail)
{
	vector<Point> path;
	path.push_back(tail);

	int i = tail.first;
	int j = tail.second;

	// start from snake's tail till snake's head
	while (L[i][j])
	{
		if (i - 1 >= 0 && L[i][j] - L[i - 1][j] == 1
			&& abs(grid[i - 1][j] - grid[i][j]) == 1)
		{
			path.push_back(make_pair(i - 1, j));
			i--;
		}
		// note that there can be multiple paths - hence we have placed else
		else if (j - 1 >= 0 && (L[i][j] - L[i][j - 1] == 1)
				&& abs(grid[i][j - 1] - grid[i][j]) == 1)
		{
			path.push_back(make_pair(i, j - 1));
			j--;
		}
	}

	// return vector containing path
	return path;
}

// Function to find maximum length of snake sequence in given matrix
vector<Point> findMaxLengthSnakeSequence(int grid[N][N])
{
	// L[i][j] stores the maximum length of snake sequence
	// ending at cell (i, j)
	int L[N][N];

	// stores maximum length of Snake sequence
	int max_so_far = 0;

	// Pair to store coordinates of snake's tail
	Point tail;

	// process the matrix in bottom-up fashion
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// initialize each element by 0
			L[i][j] = 0;

			// compare current cell with top cell and check absolute diff
			if (i - 1 >= 0 && abs(grid[i - 1][j] - grid[i][j]) == 1)
			{
				L[i][j] = L[i - 1][j] + 1;
				if (max_so_far < L[i][j])
				{
					max_so_far = L[i][j];
					tail = make_pair(i, j);
				}
			}

			// compare current cell with left cell and check absolute diff
			if (j - 1 >= 0 && abs(grid[i][j - 1] - grid[i][j]) == 1)
			{
				// L[i][j] can be non-zero at this point, hence take maximum
				L[i][j] = max(L[i][j], L[i][j - 1] + 1);
				if (max_so_far < L[i][j])
				{
					max_so_far = L[i][j];
					tail = make_pair(i, j);
				}
			}
		}
	}

	// construct maximum length snake sequence
	return constructPath(L, grid, tail);
}

int main()
{
	int grid[N][N] =
	{
		{ 7, 5, 2, 3, 1 },
		{ 3, 4, 1, 4, 4 },
		{ 1, 5, 6, 7, 8 },
		{ 3, 4, 5, 8, 9 },
		{ 3, 2, 2, 7, 6 }
	};

	vector<Point> path = findMaxLengthSnakeSequence(grid);

	cout << "Maximum length Snake sequence : ";

	// use reverse iterator to print the vector (from snake head to tail)
	for (auto it = path.rbegin(); it != path.rend(); it++)
		cout << grid[it->first][it->second] << " - ";

	cout << endl << "Length is : " << path.size() - 1;

	return 0;
}
*/