#include <bits/stdc++.h>
using namespace std;

int arr[100001],st[400004];
void build(int si,int ss,int se)
{
    if(ss==se)
    {
        st[si]=arr[ss];
        return;
    }
    int mid=(ss+se)/2;
    build(2*si, ss, mid);
    build(2*si+1, mid+1, se);
    st[si]=st[2*si] + st[2*si+1];
}

int query(int si, int ss, int se, int l, int r)
{
    if(r<ss or l>se)
        return 0;
    if(l<=ss and r>=se)
        return st[si];
    int mid=(ss+se)/2;

    int left=query(2*si, ss, mid, l, r);
    int right=query(2*si+1, mid+1, se, l, r);
    return left+right;
}
int main()
{
    int q,n;
    cout<<"enter the no of elements and queries:";
    cin>>n>>q;
    cout<<"\nenter the elements:";
    for(int i=1;i<=n;i++)
         cin>>arr[i];

    build(1,1,n);
    while(q--)
    {
        int l,r;
        cout<<"\nenter l and r of query:";
        cin>>l>>r;
        cout<<query(1,1,n,l,r);
        cout<<endl;
    }
    return 0;
}
