#include <bits/stdc++.h>
using namespace std;

bool findpairs(int arr[], int n)
{
    unordered_map<int, pair<int, int>> mp;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum = arr[i]+arr[j];
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=make_pair(arr[i], arr[j]);
            }
            else
            {
                pair<int, int> p = mp[sum];
                cout<<p.first<<" "<<p.second<<" "<<arr[i]<<" "<<arr[j];
                return true;
            }
        }
    }
    cout<<"\n no pairs found.";
    return false;
}
int main()
{
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n  =  sizeof arr / sizeof arr[0];

    findpairs(arr, n);
    return 0;
}
