#include <bits/stdc++.h>
using namespace std;

int pair<int, int>st[40004], lazy[40004];
void build(int si, int ss, int se, int arr[])
{
    if(ss==se)
    {
        st[si].first=arr[ss];
        st[si].second=arr[ss];
        return;
    }
    int mid=(ss+se)/2;

    build(2*si, ss, mid, arr);
    build(2*si+1, mid+1, se, arr);

    st[si].first= st[2*si].first + st[2*si+1].first;
    st[si].second= max(st[2*si], st[2*si+1]);
}

int  querysum(int si, int ss, int se, int l, int r)
{
    if(lazy[si]!=0)
    {
        int dx=lazy[si];
        lazy[si]=0;

        st[si].first+= (r-l+1)*dx;
        if(ss!=se)
            lazy[2*si]+=dx, lazy[2*si+1]+=dx;
        return;
    }
    if(l>se or r<ss)
        return 0;
    if(l<=ss and r>=se)
     return st[si];

    int mid=(ss+se)/2;
    int l = query(2*si, ss, mid, l, r);
    int r = query(2*si+1, mid+1, se, l, r);

    return l+r;
}

int  querymax(int si, int ss, int se, int l, int r)
{
    if(lazy[si]!=0)
    {
        int dx=lazy[si];
        lazy[si]=0;

        st[si].first+= (r-l+1)*dx;
        if(ss!=se)
            lazy[2*si]+=dx, lazy[2*si+1]+=dx;
        return;
    }
    if(l>se or r<ss)
        return INT_MIN;

    if(l<=ss and r>=se)
     return st[si];

    int mid=(ss+se)/2;
    int l = query(2*si, ss, mid, l, r);
    int r = query(2*si+1, mid+1, se, l, r);

    return max(l,r);
}

void update(int si, int ss, int se, int qs, int qe, int arr[], int val)
{
    if(lazy[si]!=0)
    {
        int dx=lazy[si];

        lazy[si]=0;
        st[si]=
    }
}
int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int n=sizeof(arr)/sizeof(arr[0]);

    build(1, 0, n-1, arr);

    int l=2, r=4;
    cout<<"\nmax sum is :"<<querysum(1, 0, n-1, l, r);
    cout<<"\nmax element is :"<<querymax(1, 0, n-1, l, r);

    int lu=2, ru=4, val=3;
    update(1, 0, n-1, lu, ru, arr, val);
}
