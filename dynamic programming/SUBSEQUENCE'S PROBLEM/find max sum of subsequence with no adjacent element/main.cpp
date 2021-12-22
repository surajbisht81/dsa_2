#include <bits/stdc++.h>
using namespace std;
//using recursion

int find_maxsum(int arr[],int start,int end, int prev)
{
    if(start==end)
        return 0;
    int inc=0, exc=0;

    exc= find_maxsum(arr,start+1,end, prev);

    if(prev+1!=start)
     inc= arr[start]+find_maxsum(arr,start+1,end, start);

    return max(inc,exc);
}
int main()
{
    int arr[]={5,  5, 10, 40, 50, 35};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nmax sum of subsequence with no adjacent element is :"<<find_maxsum(arr,0,n, INT_MIN);
    return 0;
}



//using dp
/*
int find_maxsum(int arr[],int n)
{
    if(n==1)
        return arr[n];

    int pre_prev=arr[0];
    int prev=max(arr[0],arr[1]);

    for(int i=2;i<n;i++)
    {
        int curr=max(arr[i],max(prev,pre_prev+arr[i]));
        pre_prev=prev;
        prev=curr;
    }
    return prev;
}
int main()
{
    int arr[]={1, 2, 9, 4, 5, 0, 4, 11, 6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nmax sum of subsequence with no adjacent element is :"<<find_maxsum(arr,n);
    return 0;
}
*/
