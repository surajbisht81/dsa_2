/*Given a weighting scale and an array of different positive weights where we have an infinite supply of each weight. Our task is to put weights on left and
 right pans of scale one by one in such a way that pans move to that side where weight is put i.e. each time, pans of scale moves to alternate sides.

We are given another integer ‘steps’, times which we need to perform this operation.
Another constraint is that we can’t put same weight consecutively i.e. if weight w is taken then in next step while putting the weight on opposite pan we can’t 
take w again.*/

#include <bits/stdc++.h>
using namespace std;

bool DFS(int arr[], int n, int steps, int wgt[], int residue, int currsteps)
{
    if(currsteps>steps)
        return true;

    for( int i=0; i<n; i++)
    {
        if(arr[i]>residue and arr[i]!=wgt[currsteps-1])
        {
            wgt[currsteps]=arr[i];
            if(DFS(arr, n, steps, wgt, arr[i]-residue, currsteps+1) )
            return true;
        }
    }
}

void PrintWeights(int arr[], int n, int steps)
{
    int wgt[steps]={0};

    if(DFS(arr, n, steps, wgt, 0, 0))
       {
           for(int i=0; i<steps; i++)
            cout<<wgt[i]<<" ";
       }
    else
        cout<<"\nNot possible.";
}
int main()
{
    int arr[] = {2, 3, 5, 6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int steps=10;

    PrintWeights(arr, n, steps);
    return 0;
}
