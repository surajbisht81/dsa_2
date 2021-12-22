#include <bits/stdc++.h>
using namespace std;

int st[40004];

int isArmstrong(int num)
{
    int n=to_string(num).size();
    int sum=0;
    int x=num;
    while(x)
    {
        int temp=x%10;
        sum+= pow(temp,n);
        x=x/10;
    }
    if(sum==num)
        return 1;
    else
        return 0;
}
void build(int si, int ss, int se, int arr[])
{
    if(ss==se)
    {
        st[si]=isArmstrong(arr[ss]);
        return;
    }
    int mid=(ss+se)/2;

    build(2*si+1, ss, mid, arr);
    build(2*si+2, mid+1, se, arr);
    st[si]= st[2*si+1] +st[2*si+2];
}

int query(int si, int ss, int se, int qs, int qe, int arr[])
{
    if(qs>se or qe<ss)
        return 0;
    if(qs<=ss and qe>=se)
        return st[si];

    int mid =(ss+se)/2;

    int l=query(2*si+1, ss, mid, qs, qe, arr);
    int r=query(2*si+2, mid+1, se, qs, qe, arr);
    return l+r;
}

void update(int si, int ss, int se, int i, int val, int arr[])
{
    if(ss==se)
    {
        st[si]=isArmstrong(val);
        arr[i]=val;
        return;
    }

    int mid=(ss+se)/2;

    if(i<=mid)
        update(2*si+1, ss, mid, i, val, arr);
    else
        update(2*si+2, mid+1, se, i, val, arr);

    st[si]=st[2*si+1] + st[2*si+2];
}
int main()
{
    int arr[] = { 18, 153, 8, 9, 14, 5 };
    int n=sizeof(arr)/sizeof(arr[0]);

    build(0, 0, n-1, arr);

    cout<<"\narmstrong no between index 0 and 4 is:"<<query(0, 0, n-1, 0, 4, arr);

    int i=3, val=11;
    update(0,0, n-1, i, val, arr);

     cout<<"\narmstrong no between index 0 and 4 is:"<<query(0, 0, n-1, 0, 4, arr);
    return 0;
}
