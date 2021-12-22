/*Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace
All of the above operations are of equal cost.*/

/*#include <iostream>
#include<bits/stdc++.h>
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

int editdistance(string s1,string s2,int m,int n)
{
    int dp[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++)
    {

        for(j=0;j<=n;j++)
        {

            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
        }
    }
    return dp[m][n];
}
int main()
{
     string str1 = "sunday";
    string str2 = "saturday";
    cout<<"min operations are :"<<editdistance(str1,str2,str1.length(),str2.length());
    return 0;
}
*/

/*
// recurssion problem
int editDist(string str1, string str2, int m, int n) 
{ 
    // If first string is empty, the only option is to 
    // insert all characters of second string into first 
    if (m == 0) 
        return n; 
  
    // If second string is empty, the only option is to 
    // remove all characters of first string 
    if (n == 0) 
        return m; 
  
    // If last characters of two strings are same, nothing 
    // much to do. Ignore last characters and get count for 
    // remaining strings. 
    if (str1[m - 1] == str2[n - 1]) 
        return editDist(str1, str2, m - 1, n - 1); 
  
    // If last characters are not same, consider all three 
    // operations on last character of first string, recursively 
    // compute minimum cost for all three operations and take 
    // minimum of three values. 
    return 1 + min(editDist(str1, str2, m, n - 1), // Insert 
                   editDist(str1, str2, m - 1, n), // Remove 
                   editDist(str1, str2, m - 1, n - 1) // Replace 
                   ); 
} 
  
// Driver program 
int main() 
{ 
    // your code goes here 
    string str1 = "sunday"; 
    string str2 = "saturday"; 
  
    cout << editDist(str1, str2, str1.length(), str2.length()); 
  
    return 0; 
} 
*/