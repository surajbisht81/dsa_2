#include <bits/stdc++.h>
using namespace std;

void update(int BIT[], int n, int index, int val)
{
   index++;

   while(index<=n)
   {
       BIT[index]+=val;
       index = index + (index & (-index));
   }
}

int *constructBIT(int arr[], int n)
{
    int *BIT=new int[n+1];
    for(int i=1;i<=n;i++)
        BIT[i]=0;

    for(int i=0;i<n;i++)
        update(BIT, n, i, arr[i]);
    return BIT;
}

int sumquery(int BIT[], int index)
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
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);

    int *BIT = constructBIT(freq, n);

    cout<<"\nsum of range 0-5 is :"<<sumquery(BIT, 5);

    freq[3]+=6;
    update(BIT, n, 3, 6);
    cout<<"\nsum of range 0-5 is :"<<sumquery(BIT, 5);
    return 0;
}
