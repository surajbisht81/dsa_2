/*A sequence {x1, x2, .. xn} is alternating sequence if its elements satisfy one of the following relations :

  x1 < x2 > x3 < x4 > x5 < …. xn or 
  x1 > x2 < x3 > x4 < x5 > …. xn */

#include <bits/stdc++.h>
using namespace std;

int lookup[10][2];

int LAS(int arr[],int start,int end,bool flag)
{
    int res=0;
    if(lookup[start][flag]==0)
    {
        for(int i=start;i<=end;i++)
         {
            if(flag && arr[i]>arr[i-1])
              res=max(res,1+LAS(arr,i+1,end,!flag));

            else if(!flag && arr[i]<arr[i-1])
              res=max(res,1+LAS(arr,i+1,end,!flag));

            else
              res=max(res,LAS(arr,i+1,end,flag));
        }
        lookup[start][flag]=res;
    }
    return lookup[start][flag];
}
int main()
{
    int arr[]={8,9,6,4,5,7,3,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    int res=0;
    res=1+max(LAS(arr,1,n-1,true),LAS(arr,1,n-1,false));
    cout<<"\nlongest alternating subsequence is :"<<res;
    return 0;
}
