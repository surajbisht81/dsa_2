#include <bits/stdc++.h>
using namespace std;

int st[400001] , arr[100001];

void build(int si,int ss,int se)
{
    if(ss==se)
    {
        st[si]=arr[ss];
        return;
    }
    int mid=(ss+se)/2;
    //left child of segment tree;
    build(2*si,ss,mid);
    //right child of segment tree;
    build(2*si+1,mid+1,se);
    st[si]=min(st[2*si],st[2*si+1]);
}
int query(int si,int ss,int se,int qs,int qe)
{
    if(qs>se || qe<ss)
        return INT_MAX;
    else if(qs<=ss && qe>=se)
        return st[si];

    int mid=(ss+se)/2;
    int l=query(2*si,ss,mid,qs,qe);
    int r=query(2*si+1,mid+1,se,qs,qe);
    return min(l,r);
}
int main()
{
    int n;
    cout<<"enter no of elements in actual array:";
    cin>>n;
    cout<<"\nenter elements:\n";
    for(int i=1;i<=n;i++)
        cin>>arr[i];

    build(1,1,n);

    int q,l,r;
    cout<<"\nenter no of query:";
    cin>>q;
    while(q--)
    {
        cout<<"\nenter left and right bound of query:";
        cin>>l>>r;
        cout<<"\nminimum of this query is:"<<query(1,1,n,l,r);
    }
    return 0;
}
