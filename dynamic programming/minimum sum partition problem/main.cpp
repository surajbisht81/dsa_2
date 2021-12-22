#include <bits/stdc++.h>
using namespace std;
unordered_map<string ,int>mp;
int ispossible(int arr[],int n,int s1,int s2)
{
    if(n<=0)
        return abs(s1-s2);
    string key=to_string(n) + to_string(s1);
    if(mp.find(key)==mp.end())
    {

    int inc=ispossible(arr,n-1,s1+arr[n-1],s2);

    int exc=ispossible(arr,n-1,s1,s2+arr[n-1]);
    mp[key]= min(inc,exc);
    }
    return mp[key];
}
int main()
{
    int arr[]={10,20,15,5,25};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<ispossible(arr,n,0,0);
    return 0;
}


/*
//using tabulation
// A Recursive C program to solve minimum sum partition 
// problem. 
#include <bits/stdc++.h> 
using namespace std; 

// Returns the minimum value of the difference of the two sets. 
int findMin(int arr[], int n) 
{ 
	// Calculate sum of all elements 
	int sum = 0; 
	for (int i = 0; i < n; i++) 
		sum += arr[i]; 

	// Create an array to store results of subproblems 
	bool dp[n+1][sum+1]; 

	// Initialize first column as true. 0 sum is possible 
	// with all elements. 
	for (int i = 0; i <= n; i++) 
		dp[i][0] = true; 

	// Initialize top row, except dp[0][0], as false. With 
	// 0 elements, no other sum except 0 is possible 
	for (int i = 1; i <= sum; i++) 
		dp[0][i] = false; 

	// Fill the partition table in bottom up manner 
	for (int i=1; i<=n; i++) 
	{ 
		for (int j=1; j<=sum; j++) 
		{ 
			// If i'th element is excluded 
			dp[i][j] = dp[i-1][j]; 

			// If i'th element is included 
			if (arr[i-1] <= j) 
				dp[i][j] |= dp[i-1][j-arr[i-1]]; 
		} 
	} 

	// Initialize difference of two sums. 
	int diff = INT_MAX; 
	
	// Find the largest j such that dp[n][j] 
	// is true where j loops from sum/2 t0 0 
	for (int j=sum/2; j>=0; j--) 
	{ 
		// Find the 
		if (dp[n][j] == true) 
		{ 
			diff = sum-2*j; 
			break; 
		} 
	} 
	return diff; 
} 

// Driver program to test above function 
int main() 
{ 
	int arr[] = {3, 1, 4, 2, 2, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "The minimum difference between 2 sets is "
		<< findMin(arr, n); 
	return 0; 
} 
*/