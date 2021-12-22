#include <bits/stdc++.h>
using namespace std;

int pairs(int arr[], int n)
{
    unordered_map<int, int> mp;
    int res=0;

    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }

    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        int cnt = it->second;
        res+=  (cnt * (cnt-1))/2;
    }
    return res;
}
int main()
{
    int a[] = { 1, 2, 1, 2, 4 };
    int n= sizeof(a)/sizeof(a[0]);

    cout<<pairs(a, n);
    return 0;
}
