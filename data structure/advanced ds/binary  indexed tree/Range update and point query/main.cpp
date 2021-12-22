#include <bits/stdc++.h>
using namespace std;

void update(int BIT[], int n, int index, int val)
{
    index++;
    while(index<=n)
    {
        BIT[index]+=val;
        index+= (index & (-index));
    }
}
int *constructBIT(int bit[], int n)
{
     int *BIT = new int[n+1];
     for(int i=1;i<=n;i++)
        BIT[i]=0;

     for(int i=0;i<n;i++)
        update(BIT, n, i, bit[i]);
    return BIT;
}

void updaterange(int BIT[], int l, int r, int n,int val)
{
    update(BIT, n, l, val);
    update(BIT, n, r+1, -val);
}
int getsum(int BIT[], int index)
{
    index++;
    int sum=0;
    while(index>0)
    {
        sum+=BIT[index];
        index-= (index & (-index));
    }
    return sum;
}
int main()
{
    int arr[] = {0, 0, 0, 0, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    int *BIT = constructBIT(arr, n);

    int l=2, r=4, val=2;
    updaterange(BIT, l, r, n, val);

    int index=4;
    cout<<"\nelement at index 4 is :"<<getsum(BIT, index);

     l=0, r=3, val=4;
    updaterange(BIT, l, r, n, val);

    index=3;
    cout<<"\nelement at index 3 is :"<<getsum(BIT, index);
    return 0;
}
