#include <bits/stdc++.h>
using namespace std;

int st[400004];

int even_parity(int num)
{
    int parity=0;
    while(num)
    {
        if(num&1)
            parity++;
        num=num>>1;
    }
    if(parity%2==0)
        return 1;
    else
        return 0;
}
void build(int si, int ss, int se, int arr[])
{
    if(ss== se)
    {
        st[si]=even_parity(arr[ss]);
        return;
    }
    int mid=(ss+se)/2;

    build(2*si, ss, mid, arr);
    build(2*si+1, mid+1, se, arr);

    st[si]=st[2*si]+st[2*si+1];
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
    return l+r;
}

void update(int si, int ss, int se, int i, int val, int arr[])
{
    if(ss==se)
    {
        st[si]=even_parity(val);
        arr[i]=val;
        return;
    }

    int mid=(ss+se)/2;

    if(i<=mid)
        update(2*si, ss, mid, i, val, arr);
    else
        update(2*si+1, mid+1, se, i, val, arr);

    st[si]=st[2*si] + st[2*si+1];
}
int main()
{
    int arr[] = { 18, 15, 8, 9, 14, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    build(1, 0, n-1, arr);

    int start = 0;
    int end = 4;
    cout<<"\n no of even parity nos. between 0 and 4 are :"<<query(1, 0, n-1, start, end);

    //update the value
    int i = 3;
    int x = 11;
    update(1, 0, n-1, i, x, arr);

     cout<<"\n no of even parity nos. between 0 and 4 after update are :"<<query(1, 0, n-1, start, end);
    return 0;
}
