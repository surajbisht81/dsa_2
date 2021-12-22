#include <bits/stdc++.h>

using namespace std;
struct Box
{
    int h,w,l;
};
int max(int a,int b)
{
    return (a>b)?a:b;
}
int min(int a,int b)
{
    return (a<b)?a:b;
}
int compare (const void *a, const void * b)
{
    return ( (*(Box *)b).l * (*(Box *)b).w ) -
           ( (*(Box *)a).l * (*(Box *)a).w );
}
int boxstacking(Box arr[],int n)
{
    //first of all, create all possible rotations of available boxes;
    //for that create array of 3n size;
    Box row[3*n];
    int index=0;
    for(int i=0;i<n;i++)
    {
        //print as it is the original box;
        row[index].h=arr[i].h;
        row[index].l=max(arr[i].l,arr[i].w);
        row[index].w=min(arr[i].l,arr[i].w);
        index++;

        //first rotation;
        row[index].h=arr[i].w;
        row[index].l=max(arr[i].h,arr[i].l);
        row[index].w=min(arr[i].h,arr[i].l);
        index++;

        //third rotation;
        row[index].h=arr[i].l;
        row[index].l=max(arr[i].h,arr[i].w);
        row[index].w=min(arr[i].h,arr[i].w);
        index++;
    }
    n=3*n;
    for(int i=0;i<n;i++)
        cout<<row[i].h<<" * "<<row[i].w<<" * "<<row[i].l<<endl;

     qsort (row, n, sizeof(row[0]), compare);
    //create an array to store height of all created boxes;
    int msh[n];
    for(int i=0;i<n;i++)
    {
        msh[i]=row[i].h;
    }
    int max=-1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(row[j].l>row[i].l && row[j].w>row[i].w && msh[i]<msh[j]+row[i].h)
                msh[i]=msh[j]+row[i].h;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(max<msh[i])
            max=msh[i];
    }
    return max;
}
int main()
{
    Box arr[]={ {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nmax length of box stack is="<<boxstacking(arr,n);
    return 0;
}
