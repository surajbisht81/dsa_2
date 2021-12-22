#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[],int n)
{
    int jumps[n];
    jumps[0]=0;

    if(arr[0]==0)
        return INT_MAX;

    for(int i=1;i<n;i++)
    {
        jumps[i]=INT_MAX;
        for(int j=0;j<i;j++)
        {
            if(i<=j+arr[j] && jumps[j]!=INT_MAX)
            {
                jumps[i]=min(jumps[i],jumps[j]+1);
            }
        }
    }
    return jumps[n-1];
}
int main()
{
    int arr[]={1,3,5,8,9,2,6,7,6,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nmin no of jumps= "<<minJumps(arr,n);
    return 0;
}
