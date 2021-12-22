#include <bits/stdc++.h>
using namespace std;

void longest(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int start=0, end=0;
    int l=0, now=0;

    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;

        if(mp[arr[i]]==1)
            now++;

        while(now>k)
        {
            mp[arr[l]]--;

            if(mp[arr[l]]==0)
                now--;
            l++;
        }

        if(i-l+1>=end-start+1)
        {
            end=i;
            start=l;
        }
    }
    for(int i=start; i<=end; i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int a[] = { 6, 5, 1, 2, 3, 2, 1, 4, 5 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 3;

    longest(a, n, k);
    return 0;
}
