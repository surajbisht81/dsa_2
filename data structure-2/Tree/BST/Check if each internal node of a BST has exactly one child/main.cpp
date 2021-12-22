/*Given Preorder traversal of a BST, check if each non-leaf node has only one child. Assume that the BST contains unique entries.*/


#include <bits/stdc++.h>
using namespace std;

bool only_child(int pre[],int n)
{
    int min,max;
    if(pre[n-1]>pre[n-2])
    {
        max=pre[n-1];
        min=pre[n-2];
    }
    else
    {
        max=pre[n-2];
        min=pre[n-1];
    }

    for(int i=n-3;i>=0;i--)
    {
        if(pre[i]<min)
            min=pre[i];
        else if(pre[i]>max)
            max=pre[i];
        else
            return false;
    }
    return true;
}
int main()
{
    int pre[]= {8, 3, 5, 7, 6};
    int n=sizeof(pre)/sizeof(pre[0]);

    if(only_child(pre,n))
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
