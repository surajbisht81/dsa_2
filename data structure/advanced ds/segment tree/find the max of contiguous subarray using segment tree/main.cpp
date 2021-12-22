#include <bits/stdc++.h>
using namespace std;

int st[40004];
void build(int si, int ss, int se, int arr[])
{
    if(ss==se)
    {
        st[si]=arr[ss];
        return;
    }
    int mid=(ss+se)/2;
    build(2*si, ss, mid, arr);
    build(2*si+1, mid+1, se, arr);
    st[si]= max(st[2*si], st[2*si+1]);
}

int getmax(int si, int ss, int se, int qs, int qe)
{
    if(qs>se or qe<ss)
        return INT_MIN;

    if(qs<=ss and qe>=se)
        return st[si];

    int mid=(ss+se)/2;

    int l=getmax(2*si, ss, mid, qs, qe);
    int r=getmax(2*si+1, mid+1, se, qs, qe);
    return max(l,r);
}
int main()
{
     int k = 4;
    int arr[] = { 8, 5, 10, 7, 9, 4, 15,
                  12, 90, 13 };

    int n=sizeof(arr)/sizeof(arr[0]);
    build(1, 0, n-1, arr);

    cout<<"\nmax of contiguous subarray is:\n";
    for(int i=0;i<n;i++)
    {
        if((k+i-1)<n)
         cout<<getmax(1, 0, n-1, i, k+i-1)<<" ";
        else
            break;
    }
    return 0;
}
