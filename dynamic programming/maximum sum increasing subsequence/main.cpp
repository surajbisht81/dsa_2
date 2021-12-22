#include <bits/stdc++.h>
using namespace std;

int maxsuminc_sub(int n,int arr[])
{
    int msis[n+1];

    for(int i=0;i<n;i++)
        msis[i]=arr[i];

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && msis[i]<msis[j]+ arr[i])
                msis[i]=msis[j]+arr[i];
        }
    }
    int maxx=*max_element(msis,msis+n);
    return maxx;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"\nmax sum inc subse. :"<<maxsuminc_sub(n,arr);
    return 0;
}
