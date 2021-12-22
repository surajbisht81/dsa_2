#include <bits/stdc++.h>
using namespace std;

void update(int BIT[], int n, int index, int val)
{
    index++;
    while(index<=n)
    {
        BIT[index]^=val;
        index+= (index & (-index));
    }
}
int* constructBIT(int arr[], int n)
{
    int* BIT = new int[n+1];

    for(int i=1;i<=n;i++)
        BIT[i]=0;

    for(int i=0;i<n;i++)
        update(BIT, n, i, arr[i]);
 return BIT;
}

int RangeXor(int BIT[], int index)
{
    int ans=0;
    index++;
    while(index>0)
    {
        ans^=BIT[index];
        index-= (index & (-index));
    }
    return ans;
}

int getRangeXor(int BIT[], int l, int r)
{
    return RangeXor(BIT, r)-RangeXor(BIT, l-1);
}
int main()
{
     int A[] = { 2, 1, 1, 3, 2, 3,
                4, 5, 6, 7, 8, 9 };
    int n = sizeof(A) / sizeof(A[0]);

    vector<vector<int> > q
        = { { 1, 0, 9 },
            { 2, 3, 6 },
            { 2, 5, 5 },
            { 2, 8, 1 },
            { 1, 0, 9 } };

    int *BIT = constructBIT(A, n);

    for(int i=0;i<q.size();i++)
    {
        int idx=q[i][0];

        if(idx==1)
        {
            int l= q[i][1], r=q[i][2];
            cout<<"\nXor between"<<l<<"and"<< r<<"is :"<< getRangeXor(BIT, l, r);
        }
        else
        {
            int index=q[i][1], val=q[i][2];
            A[index]^=val;
            update(BIT, n, index, val);
        }
    }
    return 0;
}
