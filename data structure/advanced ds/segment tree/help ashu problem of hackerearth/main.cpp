#include <bits/stdc++.h>
using namespace std;

int arr[100001];
pair<int,int> st[400004];
void build(int si,int ss, int se)
{
    if(ss==se)
    {
        if(arr[ss]%2==0)
         st[si]={1,0};
        else
         st[si]={0,1};
        return;
    }
    int mid=(ss+se)/2;

    build(2*si, ss, mid);
    build(2*si+1, mid+1, se);

    st[si].first= st[2*si].first + st[2*si+1].first;
    st[si].second = st[2*si].second + st[2*si+1].second;
}
void update(int si, int ss, int se, int i, int x)
{
    if(ss==se)
    {
        if(arr[ss]%2==1)
          st[si]={1,0};
        else
          st[si]={0,1};
        arr[ss]=x;
        return;
    }
    int mid=(ss+se)/2;
    if(i<=mid)
        update(2*si, ss, mid, i,x);
    else
        update(2*si+1, mid+1, se, i,x);

    st[si].first=st[2*si].first +st[2*si+1].first;
    st[si].second=st[2*si].second+st[2*si+1].second;
}
int evenquery(int si, int ss, int se, int qs, int qe)
{
   if(qe<ss or qs>se)
    return 0;
   if(qs<=ss and qe>=se)
    return st[si].first;

   int mid=(ss+se)/2;
   int l=evenquery(2*si, ss, mid, qs, qe);
   int r=evenquery(2*si+1,mid+1, se, qs, qe);
   return l+r;
}
int oddquery(int si,int ss, int se, int qs, int qe)
{
   if(qs>se or qe<ss)
    return 0;
   if(qs<=ss and qe>=se)
    return st[si].second;

   int mid=(ss+se)/2;
   int l=oddquery(2*si, ss, mid, qs, qe);
   int r=oddquery(2*si+1, mid+1, se, qs, qe);
   return l+r;
}
int main()
{
    int n,q;
    cout<<"\nenter the no of elements and queries:";
    cin>>n>>q;

    for(int i=1;i<=n;i++)
        cin>>arr[i];
    build(1,1,n);
    while(q--)
    {
        int c;
        cout<<"\nenter the query (0,1, 2):";
        cin>>c;
        if(c==0)
        {
            int i;
            cout<<"\nenter the index to change:";
            cin>>i;
            int x;
            cout<<"\nenter x:";
            cin>>x;
            if((arr[i]%2) == (x%2))
                continue;
            else
              update(1,1,n,i,x);
        }
        else if(c==1)
        {
            int l, r;
            cout<<"\nenter l and r:";
            cin>>l>>r;
            cout<<evenquery(1, 1, n, l, r);
        }
        else
        {
            int l, r;
            cout<<"\nenter l and r:";
            cin>>l>>r;
            cout<<oddquery(1, 1, n, l, r);
        }
    }
     return 0;
}
