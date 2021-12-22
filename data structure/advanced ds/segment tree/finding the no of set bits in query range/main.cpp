#include <bits/stdc++.h>
using namespace std;

pair<int, int> st[40004];
int set_bits(int x)
{
    int parity=0;
    while(x!=0)
    {
        if(x&1)
            parity++;
        x=x>>1;
    }
    return parity;
}
void build(int si, int ss, int se, int arr[])
{
    if(ss==se)
    {
        st[si].first = set_bits(arr[ss]);
        st[si].second = arr[ss];
        return;
    }
    int mid=(ss+se)/2;
    build(2*si, ss, mid, arr);
    build(2*si+1, mid+1, se, arr);

    if(st[2*si].first > st[2*si+1].first)
    {
        st[si].first = st[2*si].first;
        st[si].second = st[2*si].second;
    }
    else if(st[2*si].first < st[2*si+1].first)
    {
        st[si].first = st[2*si+1].first;
        st[si].second = st[2*si+1].second;
    }
    else
    {
        st[si].first = st[2*si].first;
        st[si].second = max(st[2*si].second, st[2*si+1].second);
    }
}

int get_parity(int si, int ss, int se, int qs, int qe)
{
    if(qs>se or qe<ss)
        return 0;

    if(qs<=ss and qe>=se)
        return st[si].second;

    int mid=(ss+se)/2;

    int l=get_parity(2*si, ss, mid, qs, qe);
    int r=get_parity(2*si+1, mid+1, se, qs, qe);

    return max(l,r);
}
int main()
{
    int arr[] = { 18, 9, 8, 15, 14, 5 };
    int  n=sizeof(arr)/sizeof(arr[0]);

    build(1, 0, n-1, arr);

    cout<<"no of parity bits in range 1 to 4 is :"<<get_parity(1, 0, n-1, 1, 4)<<endl;
    cout<<"no of parity bits in range 0 to 2 is :"<<get_parity(1, 0, n-1, 0, 2);
    return 0;
}
