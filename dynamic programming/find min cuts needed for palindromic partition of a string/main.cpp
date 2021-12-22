#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string X,int i,int j)
{
    while(i<=j)
    {
        if(X[i++]!=X[j--])
            return false;
    }
    return true;
}
int min_cuts(string X,int i,int j)
{
    if(i==j or ispalindrome(X,i,j))
        return 0;

    int min=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int res=1+min_cuts(X,i,k)+min_cuts(X,k+1,j);

        if(min>res)
            min=res;
    }
    return min;
}
int main()
{
    string X="BABABCBADCD";
    int n=X.length();
    cout<<"\n min cuts required are :"<<min_cuts(X,0,n-1);
    return 0;
}


/*
 // using dp
#include <bits/stdc++.h>
using namespace std;

#define MAX 20

bool isPalindrome[MAX][MAX];

bool findAllPalindromes(string X, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j < n; j++)
		{
			if (i == j)
				isPalindrome[i][j] = true;
			else if (X[i] == X[j])
				isPalindrome[i][j] = ((j - i == 1) ? true :
									isPalindrome[i + 1][j - 1]);
			else
				isPalindrome[i][j] = false;
		}
	}
}

int minPalinPartition(int i, int j, auto &lookup)
{
	// base case: if starting index i and ending index j are equal
	// or X[i..j] is already a palindrome

	if (i == j || isPalindrome[i][j])
		return 0;

	// construct an unique map key from dynamic elements of the input
	// lookup[key] stores minimum number cuts needed to partition X[i..j]

	string key = to_string(i) + "|" + to_string(j);


	if (lookup.find(key) == lookup.end())
	{

		lookup[key] = INT_MAX;
		for (int k = i; k <= j - 1; k++)
		{
			// recur to get minimum cuts required in X[i..k] and X[k+1..j]
			int count = 1 + minPalinPartition(i, k, lookup) +
						minPalinPartition(k + 1, j, lookup);

			if (count < lookup[key])
				lookup[key] = count;
		}
	}

	return lookup[key];
}

int main()
{
	string X = "BABABCBADCD";
	int n = X.length();

	// create a map to store solutions of subproblems
	unordered_map<string, int> lookup;

	// find all substrings of X that are palindromes
	findAllPalindromes(X, n);

	cout << "The minimum cuts required are "
		 << minPalinPartition(0, n - 1, lookup);

	return 0;
}
*/