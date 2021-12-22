#include <bits/stdc++.h>
using namespace std;

int st[40004];
void build(int si,int ss,int se, int arr[])
{
    if(ss==se)
    {
        st[si]=arr[ss];
        return;
    }
    int mid=(ss+se)/2;

    build(2*si, ss, mid,arr);
    build(2*si+1, mid+1, se, arr);
    st[si] = st[2*si]^st[2*si+1];
}

int query(int si, int ss, int se,int qs, int qe, int arr[])
{
    if(qs>se or qe<ss)
        return 0;
    if(qs<=ss and qe>=se)
        return st[si];
    int mid=(ss+se)/2;

   int l= query(2*si, ss, mid, qs, qe, arr);
   int r= query(2*si+1, mid+1, se, qs, qe, arr);
    return l^r;
}
void update(int si, int ss, int se, int i, int val, int arr[])
{
    if(ss == se)
    {
        st[si]= val;
        arr[i]=val;
        return;
    }
    int mid=(ss+se)/2;
    if(i<=mid)
      update(2*si, ss, mid, i, val, arr);
    else
      update(2*si+1, mid+1, se, i, val, arr);

    st[si]= st[2*si]^st[2*si+1];
}
int main()
{
    int n;
    cout<<"\nenter the value of n:";
    cin>>n;
    int arr[n];

    for(int i=1;i<=n;i++)
        cin>>arr[i];

    build(1, 1, n, arr);

    cout<<"\nxor of range 2 to 4 is :"<<query(1, 1, n, 2, 4, arr);

    int i;
    cout<<"\nenter the index to update:";
    cin>>i;

    update(1,1,n, i, 10, arr);
    cout<<"\nxor of range 1 to 3 is:"<<query(1, 1, n, 1, 3, arr);
    return 0;
}
