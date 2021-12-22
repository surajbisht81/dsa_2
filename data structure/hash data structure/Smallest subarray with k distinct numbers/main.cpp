#include <bits/stdc++.h>
using namespace std;

void smallest(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int start=0, end=999;
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

        if( (i-l+1)<(end-start+1) && now==k)
        {
            end=i;
            start=l;
        }
    }
    cout<<start<<" "<<end;
}
int main()
{
    int arr[] = { 1, 1, 2, 2, 3, 3, 4, 5};
    int n= sizeof(arr)/sizeof(arr[0]);
    int k=3;

    smallest(arr, n, k);
    return 0;
}
