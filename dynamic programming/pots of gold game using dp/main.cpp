#include <bits/stdc++.h>
using namespace std;

int max_coins(int arr[],int start,int end)
{
    if(start==end)
        return arr[start];
    if(start+1==end)
        return max(arr[start],arr[end]);

    int sumA;
    sumA=arr[end];
    sumA+=min(max_coins(arr,start+1,end-1),max_coins(arr,start,end-2));

    int sumAA;
    sumAA=arr[start];
    sumAA+=min(max_coins(arr,start+1,end-1),max_coins(arr,start+2,end));
    return max(sumA,sumAA);

}
int main()
{
    int arr[]={4,6,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nmax coins collected by player A is :"<<max_coins(arr,0,n-1);
    return 0;
}
