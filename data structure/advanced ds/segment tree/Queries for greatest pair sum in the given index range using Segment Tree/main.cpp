#include <bits/stdc++.h>
using namespace std;

struct node
{
    int maxval, greatestPsum;
}st[100009];


node util(node x, node y)
{
    node ans;

    ans.greatestPsum = max( x.maxval+y.maxval, max(x.greatestPsum, y.greatestPsum));
    ans.maxval = max( x.maxval, y.maxval);
    return ans;
}
node build(int si, int ss, int se,int arr[])
{
    if(ss==se)
    {
        st[si].maxval = arr[ss];
        st[si].greatestPsum = 0;
        return st[si];
    }

    int mid= (ss+se)/2;

    st[si]= util( build(2*si, ss, mid, arr), build(2*si+1, mid+1, se, arr));
    return st[si];
}

node query(int si, int ss, int se, int qs, int qe)
{
    if(qs<=ss and qe>=se)
        return st[si];

    node temp;
    temp.greatestPsum=-1;
    temp.maxval=-1;

    if(qs> se or qe< ss)
        return temp;

    int mid = (ss+se)/2;

    return util( query(2*si, ss, mid, qs, qe), query(2*si+1, mid+1, qe, qs, qe));
}
int main()
{
    int arr[] = { 1, 3, 2, 7, 9, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int L=1, R=4;

    build(1, 0, n-1, arr);

    node temp = query(1, 0, n-1, L, R);
    cout<<"\ngreatest pair sum is :"<<temp.greatestPsum;
    return 0;
}
