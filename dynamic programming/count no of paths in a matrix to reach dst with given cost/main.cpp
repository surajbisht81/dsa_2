#include <bits/stdc++.h>
using namespace std;
#define N 4
#define M 4

unordered_map<string, int> mp;
int Total_paths(int mat[][N], int i, int j, int cost)
{
    if(i==M-1 and j==N-1)
     {
       if(mat[i][j]-cost==0)
         return 1;
       else
         return 0;
     }
      
    if(i>=M or j>=N)
     return 0;
    
    if(i==M-1 and j==N-1 and cost-mat[i][j]!=0)
      return 0;
      
    string str = to_string(i) + "|" + to_string(j) + "|" + to_string(cost);
      
    int res = 0;
    if(mp.find(str)==mp.end())
    {
     res = res + Total_paths(mat, i+1, j, cost-mat[i][j]);
     res = res + Total_paths(mat, i, j+1, cost-mat[i][j]);
     mp[str] = res;
    }
    return mp[str];
}

int main() {
    
    int mat[M][N] =
	{
		{ 4, 7, 1, 6 },
		{ 5, 7, 3, 9 },
		{ 3, 2, 1, 2 },
		{ 7, 1, 6, 3 }
	};

	int cost = 28;
	
	cout<<"\ntotal paths are: "<<Total_paths(mat, 0, 0, cost);
	return 0;
}