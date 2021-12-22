#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int lis(int arr[], int n)
{
    int lis[n],max=INT_MIN;
    lis[0]=1;
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }
   // return *max_element(lis,lis+n);
   for(int i=0;i<n;i++)
   {
       if(max<lis[i])
        max=lis[i];
   }
   return max;
}
int main()
{

    int arr[] =  {3, 10, 2, 1, 20};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nlongest increasing subsequence is="<<lis(arr,n);
    return 0;
}
