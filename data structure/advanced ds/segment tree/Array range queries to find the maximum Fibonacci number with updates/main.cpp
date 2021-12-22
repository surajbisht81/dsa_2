#include <bits/stdc++.h>
using namespace std;

int st[400004];
set<int>fibonacci;
void create_fibonacci(int maxx)
{
    int i=0;
    int j=1;
    fibonacci.insert(i);
    fibonacci.insert(j);
    while(j<=maxx)
    {
        int temp = i+j;
        fibonacci.insert(temp);
        i=j;
        j=temp;
    }
}
void build(int si, int ss, int se, int arr[])
{
    if(ss== se)
    {
        if(fibonacci.find(arr[ss])!=fibonacci.end())
            st[si]=arr[ss];
        else
            st[si]=-1;
        return;
    }
    int mid=(ss+se)/2;

    build(2*si, ss, mid, arr);
    build(2*si+1, mid+1, se, arr);

    st[si]= max(st[2*si], st[2*si+1]);
}

int query(int si, int ss, int se, int qs, int qe)
{
    if(qs>se or qe<ss)
        return 0;
    if(qs<=ss and qe>=se)
        return st[si];

    int mid=(ss+se)/2;

    int l=query(2*si, ss, mid, qs, qe);
    int r=query(2*si+1, mid+1, se, qs, qe);
    return max(l,r);
}

void update(int si, int ss, int se, int i, int val, int arr[])
{
    if(ss==se)
    {
        if(fibonacci.find(val)!=fibonacci.end())
            st[si]=val;
        arr[i]=val;
        return;
    }

    int mid=(ss+se)/2;

    if(i<=mid)
        update(2*si, ss, mid, i, val, arr);
    else
        update(2*si+1, mid+1, se, i, val, arr);

    st[si]=max(st[2*si], st[2*si+1]);
}
int main()
{
    int arr[] = { 1, 3, 5, 7, 9, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxx = *max_element(arr, arr+n);
    create_fibonacci(maxx);

    build(1, 0, n-1, arr);

    int start=1, end=3;
    cout<<"\nmax fibonacci term between 1 and 3 is :"<<query(1, 0, n-1, start, end);

    int i=3, val=8;
    update(1, 0, n-1, i, val, arr);

    cout<<"\nmax fibonacci term between 1 and 3 after update is :"<<query(1, 0, n-1, start, end);
    return 0;
}
