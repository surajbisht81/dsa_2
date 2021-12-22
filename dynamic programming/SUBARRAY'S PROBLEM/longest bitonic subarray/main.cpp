#include <bits/stdc++.h>
using namespace std;

int longest_bitonic_subarray(int arr[],int n)
{
    int lis[n];
    int lds[n];
    for(int i=0;i<n;i++)
    {
         lis[i]=1;
         lds[i]=1;
    }

    for(int i=0;i<n-1;i++)
    {
        if(arr[i]<arr[i+1] && lis[i+1]<lis[i]+1)
            lis[i+1]=lis[i]+1;
    }

    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>arr[i+1] && lds[i]<lds[i+1]+1)
            lds[i]=lds[i+1]+1;
    }
    int maxx=lis[0]+lds[0]-1;
    int start=0,end=0;
    for(int i=1;i<n;i++)
    {
        if(maxx<lis[i]+lds[i]-1)
           {
             maxx=lis[i]+lds[i]-1;
             start=i-lis[i]+1;
             end=i+lds[i]-1;
           }
    }
    cout<<"\nstart and end position in array is :"<<start<<"and"<<end<<endl;
    return maxx;
}
int main()
{
    int arr[]={12, 4, 78, 90, 45, 23};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nlongest bitonic subarray is : "<<longest_bitonic_subarray(arr,n);
    return 0;
}
