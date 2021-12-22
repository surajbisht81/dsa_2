#include <bits/stdc++.h>
using namespace std;

class Job
{
    public:
    int start,finish,profit;
};

bool jobcompare(Job a,Job b)
{
    return (a.finish<b.finish);
}

int maxprofit(Job arr[],int n)
{
    sort(arr,arr+n,jobcompare);

    int temp[n];
    for(int i=0;i<n;i++)
        temp[i]=arr[i].profit;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j].finish<=arr[i].start)
                temp[i]=max(temp[i],temp[j]+arr[i].profit);
        }
    }
  return *max_element(temp,temp+n);
}
int main()
{
    Job arr[]={{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nmax profit= "<<maxprofit(arr,n);
    return 0;
}
