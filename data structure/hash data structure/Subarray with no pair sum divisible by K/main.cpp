#include <bits/stdc++.h>
using namespace std;

void subarrayDivisibleByK(int arr[], int n, int k)
{
    unordered_map<int,int> mp;

    mp[arr[0]%k]++;

    int s=0, e=0, ms=0, me=0;
    for(int i=1;i<n;i++)
    {
        int mod = arr[i]%k;

        while(mp[k-mod]!=0 or (mod==0 and mp[mod]!=0))
        {
            mp[arr[s]%k]--;
            s++;
        }

        mp[mod]++;
        e++;

        if((e-s)> (me-ms))
        {
            ms=s;
            me=e;
        }
    }
    cout<<"\nsubarray is size"<<me-ms+1<<" is :"<<endl;
    for(int j=ms ;j<=me;j++)
        cout<<arr[j]<<" ";
}
int main()
{
    int k = 3;
    int arr[] = {5, 10, 15, 20, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    subarrayDivisibleByK(arr, n, k);
    return 0;
}
