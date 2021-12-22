#include <bits/stdc++.h>
using namespace std;

//this que is similar to the coin change problem(total no of ways to make sum with given denomination of coins;
int total_solutions(int arr[],int rhs,int n)
{
    if(rhs==0)
        return 1;
    if(rhs<0 or n<0)
        return 0;
    int res=0;
    //including last element;
    res+=total_solutions(arr,rhs-arr[n],n);
    //excluding last element;
    res+=total_solutions(arr,rhs,n-1);
    return res;
}
int main()
{
    int arr[]={1,3,5,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int rhs=8;
    cout<<"\ntotal solution of linear eqn is: "<<total_solutions(arr,rhs,n-1);
    return 0;
}
