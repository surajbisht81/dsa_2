#include <bits/stdc++.h>
using namespace std;

// Lazy Propagation
const int MAX=10001;
int arr[MAX], st[4*MAX], lazy[4*MAX];

void build(int si, int ss, int se)
{
    if(ss==se)
    {
        st[si]=arr[ss];
        return;
    }

    int mid=(ss+se)/2;
    build(2*si, ss, mid);
    build(2*si+1, mid+1, se);

    st[si]= st[2*si] + st[2*si+1];
}
void update(int si, int ss, int se, int qs, int qe, int val)
{
     if(lazy[si]!=0)
     {
         int dx=lazy[si];
         lazy[si]=0;
         st[si]+= dx*(se-ss+1);

         if(ss!=se)
            lazy[2*si]+=dx, lazy[2*si+1]=dx;
     }

     if(qs>se or qe<ss)
        return;
     if(qs<=ss and qe>=se)
     {
         st[si]+=val*(se-ss+1);

         if(ss!=se)
            lazy[2*si]+=val,lazy[2*si+1]+=val;
         return;
     }
     int mid=(ss+se)/2;
     update(2*si, ss, mid, qs, qe, val);
     update(2*si+1, mid+1, se, qs, qe, val);

     st[si]=st[2*si]+st[2*si+1];
}

int query(int si, int ss, int se, int qs, int qe)
{
    if(lazy[si]!=0)
    {
        int dx=lazy[si];
        lazy[si]=0;
        st[si]+= dx*(se-ss+1);

        if(ss!=se)
            lazy[2*si]+=dx,lazy[2*si+1]+=dx;
    }

    int mid=(ss+se)/2;

    if(qs>se or qe<ss)
        return 0;
    if(qs<=ss and qe>=se)
        return st[si];

    return query(2*si, ss, mid, qs, qe)+
           query(2*si+1, mid+1, se, qs, qe);
}
int main()
{
    int n,q;
    cout<<"\nenter the no of elements and queries:";
    cin>>n>>q;

    int code,l,r,val;
    build(1,1,n);
    while(q--)
    {
        cout<<"\nenter the code:";
        cin>>code;
        if(code==0)
        {
            cout<<"\nenter l and r range to update:";
            cin>>l>>r;
            cout<<"\nenter value:";
            cin>>val;
            update(1,1,n,l,r,val);
        }
        else
        {
            cout<<"\nenter the l and r:";
            cin>>l>>r;
            cout<<query(1,1,n,l,r);
        }
    }
    return 0;
}
