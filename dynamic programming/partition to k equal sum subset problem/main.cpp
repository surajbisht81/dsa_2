#include <bits/stdc++.h>
using namespace std;
#define M 20
bool can_partition(int arr[],int k,int start,int end,int i_sum,int sum,int used[])
{
    if(k==1)
        return true;
    if(i_sum==sum)
        can_partition(arr,k-1,start,end,0,sum,used);

    for(int k=start;k<=end;k++)
    {
        if(used[k]==-1)
        {
            used[k]=1;
            if(can_partition(arr,k,start+1,end,i_sum+arr[start],sum,used))
                return true;
        }
        used[k]=-1;
    }
    return false;
}
int main()
{
    int arr[]={4,3,2,3,5,2,1};
    int k=4;
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=accumulate(arr,arr+n,0);

    int used[n];
    memset(used,-1,sizeof(used));
    if(sum%k!=0)
        cout<<"\npartition not possible.";
    else
        if(can_partition(arr,k,0,n-1,0,sum/k,used))
            cout<<"\npartition is possible.";
        else
            cout<<"\npartition is not possible.";
    return 0;
}
