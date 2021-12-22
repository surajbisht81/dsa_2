#include <iostream>

using namespace std;
void updateBIT(int BIT[],int index,int n,int value)
{
    index=index+1;
    while(index<=n)
    {
        BIT[index]+=value;
        index=index+ (index & (-index));
    }
}
int getsum(int BIT[],int n)
{
    n=n+1;
    int sum=0;
    while(n>0)
    {
        sum+=BIT[n];
        n=n-(n&(-n));
    }
    return sum;
}
int *constructBIT(int arr[],int n)
{
    int *BIT=new int[n+1];
    for(int i=1;i<=n;i++)
        BIT[i]=0;
    for(int i=0;i<n;i++)
        updateBIT(BIT,i,n,arr[i]);
    return BIT;
}
int main()
{
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);
    int *BIT=constructBIT(freq,n);
    cout<<"\nsum of elements in arr[0---5] is= "<<getsum(BIT,5);
    freq[3]+=6;
    updateBIT(BIT,3,n,6);
    cout<<"\nsum of elements in arr[0---5] is= "<<getsum(BIT,5);
    return 0;
}
