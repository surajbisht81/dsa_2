/*Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the integers in the 
subsequence are sorted in increasing order. For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), if the input array 
is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) and if the input array is {10, 5, 4, 3}, then output should be 10*/

#include <bits/stdc++.h>
using namespace std;

int MSIS(int arr[],int n)
{
    int iss[n];
    for(int i=0;i<n;i++)
        iss[i]=arr[i];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i] && iss[i]<iss[j]+arr[i])
                iss[i]=iss[j]+arr[i];
        }
    }
    int maxx=INT_MIN;
    for(int x:iss)
        if(maxx<x)
        maxx=x;
    return maxx;
}
int main()
{
   int arr[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11};
   int n=sizeof(arr)/sizeof(arr[0]);
   cout<<"\nmax sum is: "<<MSIS(arr,n);
   return 0;
}
