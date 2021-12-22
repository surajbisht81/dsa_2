#include <bits/stdc++.h>
using namespace std;

bool interleaving(string X,string Y, string S,int n,int m,int p)
{
    if(!n && !m && !p)
        return true;
    if(!p  or (!p && m && n))
        return false;

    bool x=(X[0]==S[0]) &&  interleaving(X.substr(1),Y,S.substr(1),n-1,m,p-1);

    bool y=(Y[0]==S[0]) &&  interleaving(X,Y.substr(1),S.substr(1),n,m-1,p-1);
    return x or y;
}
int main()
{
    string X="ABC";
    string Y="ACD";
    string S="ACDABC";

    int n=X.length();
    int m=Y.length();
    int p=S.length();
    if(interleaving(X,Y,S,n,m,p))
        cout<<"\nyes.";
    else
        cout<<"\nno.";
    return 0;
}

/*
using dp memorization
#include <iostream>
#include <unordered_map>
using namespace std;

// Function to check if string X and Y are interleaving of
// string S or not
bool interleaved(string X, string Y, string S, auto &dp)
{
	// return true if we have reached end of all strings
	if (!X.length() && !Y.length() && !S.length())
		return true;

	// return false if we have reached the end of String S
	// but string X or Y are not empty

	if (!S.length())
		return false;

	// calculate unique map key by using delimiter "|"
	string key = (X + "|" + Y + "|" + S);

	// if sub-problem is seen for the first time
	if (dp.find(key) == dp.end())
	{
		// if string X is not empty and its first character matches with
		// first character of S, recur for remaining substring

		bool x = (X.length() && S[0] == X[0]) &&
				interleaved(X.substr(1), Y, S.substr(1), dp);

		// if string Y is not empty and its first character matches with
		// first character of S, recur for remaining substring

		bool y = (Y.length() && S[0] == Y[0]) &&
				interleaved(X, Y.substr(1), S.substr(1), dp);

		dp[key] = x || y;
	}

	return dp[key];
}

int main()
{
	string X = "ABC";
	string Y = "ACD";
	string S = "ACDABC";

	// map to store solution to already computed sub-problems
	unordered_map<string, bool> dp;

	if (interleaved(X, Y, S, dp))
		cout << "Given string is interleaving of X and Y";
	else
		cout << "Given string is not an interleaving of X and Y";

	return 0;
}
*/