#include <bits/stdc++.h>
using namespace std;

struct node
{
    int arr[3];
};
node st[400004];
int lazy[400004];

void build(int si,int ss, int se)
{
    if(ss==se)
    {
        st[si].arr[0]=1;
        st[si].arr[1]=0;
        st[si].arr[2]=0;
        return;
    }
    int mid=(ss+se)/2;

    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);

    st[si].arr[0]=st[2*si].arr[0] + st[2*si+1].arr[0];
    st[si].arr[1]=st[2*si].arr[1] + st[2*si+1].arr[1];
    st[si].arr[2]=st[2*si].arr[2] + st[2*si+1].arr[2];
}

void shift(int si)
{
    int a=st[si].arr[0];
    st[si].arr[0]=st[si].arr[1];
    st[si].arr[1]=st[si].arr[2];
    st[si].arr[2]=a;
}
int query(int si, int ss, int se, int qs, int qe)
{
    if(lazy[si]!=0)
    {
        int dx=lazy[si];
        lazy[si]=0;
        if(ss!=se)
            lazy[2*si]+=dx,lazy[2*si+1]+=dx;

        dx=dx%3;
        for(int i=0;i<dx;i++)
            shift(si);
    }
    if(qe<ss or qe>se)
        return 0;
    if(qs<=ss and qe>=se)
        return st[si].arr[0];
    int mid=(ss+se)/2;

    return query(2*si,ss, mid, qs,qe)+
            query(2*si+1,mid+1,se,qs,qe);
}

void update(int si, int ss, int se, int qs,int qe)
{
    if(lazy[si]!=0)
    {
        int dx=lazy[si];
        lazy[si]=0;
        if(ss!=se)
            lazy[2*si]+=dx,lazy[2*si+1]+=dx;

        dx=dx%3;
        for(int i=0;i<dx;i++)
            shift(si);
    }

    if(qs>se or qe<ss)
        return;
    if(qs<=ss and qe>=se)
    {
        shift(si);
        if(ss!=se)
        {
            lazy[2*si]++;
            lazy[2*si+1]++;
        }
        return;
    }
    int mid=(ss+se)/2;
    update(2*si , ss , mid , qs , qe);
	update(2*si+1 , mid+1 , se , qs , qe);

	st[si].arr[0] = st[2*si].arr[0] + st[2*si+1].arr[0];
	st[si].arr[1] = st[2*si].arr[1] + st[2*si+1].arr[1];
	st[si].arr[2] = st[2*si].arr[2] + st[2*si+1].arr[2];
}
int main()
{
   int t,n;
   cout<<"\nenter the no of test cases and no of elements:";
   cin>>t>>n;

   int code,l,r;
   build(1,1,n);
   while(t--)
   {
       cout<<"\nenter the code(0 or 1) :";
       cin>>code;
       if(code==0) //update
       {
           cout<<"\nenter the l and r:";
           cin>>l>>r;
           update(1,1,n,l,r);
       }
       else
       {
           cout<<"\nenter the l and r for query:";
           cin>>l>>r;
           cout<<query(1,1,n,l,r)<<endl;
       }
   }
   return 0;
}
