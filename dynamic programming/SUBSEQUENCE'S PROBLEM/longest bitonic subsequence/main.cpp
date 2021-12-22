/*Given an array arr[0 … n-1] containing n positive integers, a subsequence of arr[] is called Bitonic if it is first increasing, then decreasing. Write a
 function that takes an array as argument and returns the length of the longest bitonic subsequence.
A sequence, sorted in increasing order is considered Bitonic with the dec*/

#include <iostream>

using namespace std;
int lbs(int arr[],int n)
{
    int i,j;
    int *lis=new int[n];
    for( i=0;i<n;i++)
        lis[i]=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
    int *lds=new int[n];
    for(i=0;i<n;i++)
        lds[i]=1;
    for(i=n-2;i>=0;i--)
    {
        for(j=n-1;j>=i;j--)
        {
            if(arr[i]>arr[j] &&  lds[i]<lds[j]+1)
                lds[i]=lds[j]+1;
        }
    }
    int max=lis[0]+lds[0] -1;
    for(i=1;i<n;i++)
    {
        if(max<lis[i]+lds[i]-1)
            max=lis[i]+lds[i]-1;
    }
    return max;
}
int main()
{
    int arr[]={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
              13, 3, 11, 7, 15};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<lbs(arr,n);
    return 0;
}
