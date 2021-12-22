#include <bits/stdc++.h>
using namespace std;

int st[40004];
void build(int si, int ss, int se,int arr[])
{
    if(ss==se)
    {
        st[si]=arr[ss];
    }
    else
    {
        int mid=(ss+se)/2;
        build(2*si, ss, mid, arr);
        build(2*si+1, mid+1, se, arr);
        st[si]= ( st[2*si] | st[2*si+1]);
    }
}

int query(int si, int ss, int se, int start, int end, int arr[])
{
    if(start> se or end<ss)
        return 0;
    if(start<=ss and end>=se)
        return st[si];

    int mid=(ss+se)/2;
    int l= query(2*si, ss, mid, start, end, arr);
    int r= query(2*si+1, mid+1, se, start, end, arr);

    return (l | r);
}
void orsum(int arr[],int n, int q, int k[])
{
    build(1, 0, n-1, arr);

    for(int i=0;i<q;i++)
    {
        int j=k[i]%(n/2);

        int sec=query(1, 0, n-1, n/2-j, n-j-1, arr);

        int first= ( query(1, 0, n-1, 0, n/2-j-1, arr) | query(1, 0, n-1, n-i, n-1, arr) );
        int temp = (first + sec);
        cout<<temp<<endl;
    }
}
int main()
{
     int arr[] = { 7, 44, 19, 86, 65, 39, 75, 101 };
     int n=sizeof(arr)/sizeof(arr[0]);
     int q=2;
     int k[q]={4, 2};
      orsum(arr,n,q, k);
      return 0;
}
