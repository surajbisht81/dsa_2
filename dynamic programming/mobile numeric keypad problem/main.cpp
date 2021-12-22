#include <bits/stdc++.h>
using namespace std;
#define M 4
#define N 3
int lookup[10][5];
int Count_combinations(char mat[M][N],int i,int j,int pos,int n)
{
    if(i<0 or i>=M or j<0 or j>=N or mat[i][j]=='*' or mat[i][j]=='#')
        return 0;
    if(pos==n-1)
        return 1;

    int res=0;

    int num=mat[i][j]-'0';
    if(lookup[num][pos]==0)
    {
     res+=Count_combinations(mat,i,j,pos+1,n);
     res+=Count_combinations(mat,i,j-1,pos+1,n);
     res+=Count_combinations(mat,i,j+1,pos+1,n);
     res+=Count_combinations(mat,i-1,j,pos+1,n);
     res+=Count_combinations(mat,i+1,j,pos+1,n);
     lookup[num][pos]=res;
    }
   return lookup[num][pos];
}
int main()
{
    char mat[M][N]={{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'},
                    {'*','0','#'}
                   };

    int total=0;
    int n=5;
   for(int i=0;i<M;i++)
   {
       for(int j=0;j<N;j++)
       {
           //if(mat[i][j]!='*' and mat[i][j]!='#')
           total+=Count_combinations(mat,i,j,0,n);
       }
   }
   cout<<"\ntotal combinations are :"<<total;
   return 0;
}


//using tabulation method
/*
// A Dynamic Programming based C program to count number of 
// possible numbers of given length 
#include <stdio.h> 

// Return count of all possible numbers of length n 
// in a given numeric keyboard 
int getCount(char keypad[][3], int n) 
{ 
	if(keypad == NULL || n <= 0) 
		return 0; 
	if(n == 1) 
		return 10; 

	// left, up, right, down move from current location 
	int row[] = {0, 0, -1, 0, 1}; 
	int col[] = {0, -1, 0, 1, 0}; 

	// taking n+1 for simplicity - count[i][j] will store 
	// number count starting with digit i and length j 
	int count[10][n+1]; 
	int i=0, j=0, k=0, move=0, ro=0, co=0, num = 0; 
	int nextNum=0, totalCount = 0; 

	// count numbers starting with digit i and of lengths 0 and 1 
	for (i=0; i<=9; i++) 
	{ 
		count[i][0] = 0; 
		count[i][1] = 1; 
	} 

	// Bottom up - Get number count of length 2, 3, 4, ... , n 
	for (k=2; k<=n; k++) 
	{ 
		for (i=0; i<4; i++) // Loop on keypad row 
		{ 
			for (j=0; j<3; j++) // Loop on keypad column 
			{ 
				// Process for 0 to 9 digits 
				if (keypad[i][j] != '*' && keypad[i][j] != '#') 
				{ 
					// Here we are counting the numbers starting with 
					// digit keypad[i][j] and of length k keypad[i][j] 
					// will become 1st digit, and we need to look for 
					// (k-1) more digits 
					num = keypad[i][j] - '0'; 
					count[num][k] = 0; 

					// move left, up, right, down from current location 
					// and if new location is valid, then get number 
					// count of length (k-1) from that new digit and 
					// add in count we found so far 
					for (move=0; move<5; move++) 
					{ 
						ro = i + row[move]; 
						co = j + col[move]; 
						if (ro >= 0 && ro <= 3 && co >=0 && co <= 2 && 
						keypad[ro][co] != '*' && keypad[ro][co] != '#') 
						{ 
							nextNum = keypad[ro][co] - '0'; 
							count[num][k] += count[nextNum][k-1]; 
						} 
					} 
				} 
			} 
		} 
	} 

	// Get count of all possible numbers of length "n" starting 
	// with digit 0, 1, 2, ..., 9 
	totalCount = 0; 
	for (i=0; i<=9; i++) 
		totalCount += count[i][n]; 
	return totalCount; 
} 

// Driver program to test above function 
int main(int argc, char *argv[]) 
{ 
char keypad[4][3] = {{'1','2','3'}, 
						{'4','5','6'}, 
						{'7','8','9'}, 
						{'*','0','#'}}; 
printf("Count for numbers of length %d: %dn", 1, getCount(keypad, 1)); 
printf("Count for numbers of length %d: %dn", 2, getCount(keypad, 2)); 
printf("Count for numbers of length %d: %dn", 3, getCount(keypad, 3)); 
printf("Count for numbers of length %d: %dn", 4, getCount(keypad, 4)); 
printf("Count for numbers of length %d: %dn", 5, getCount(keypad, 5)); 

return 0; 
} 
*/