#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left,*right;
};
Node *newNode(int key)
{
    Node *temp=new Node;
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}
void printInorder(Node *root)
{
    if(!root)
        return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
void BSTto_Array(Node *root, int arr[], int *index)
{
    if(!root)
        return;
    BSTto_Array(root->left,arr,index);

    arr[*index]=root->data;
    (*index)++;

    BSTto_Array(root->right,arr,index);
}
int *mergeArray(int arr1[],int arr2[], int m,int n)
{
    int *mergedArr=new int[m+n];
    int i=0,j=0,k=0;
    while(i<m && j<n)
    {
        if(arr1[i]<arr2[j])
        {
            mergedArr[k]=arr1[i];
            i++;
        }
        else
        {
            mergedArr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<m)
    {
        mergedArr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n)
    {
        mergedArr[k]=arr2[j];
        j++;
        k++;
    }
    return mergedArr;
}

Node *ArrayTo_BST(int arr[],int start,int end)
{
    if(start>end)
        return NULL;

    int mid=(start+end)/2;
    Node *root=newNode(arr[mid]);

    root->left=ArrayTo_BST(arr,start, mid-1);
    root->right=ArrayTo_BST(arr,mid+1, end);
    return root;
}
Node *mergeTrees(Node *root1, Node *root2, int m, int n)
{
    int *arr1=new int[m];
    int index=0;
    BSTto_Array(root1, arr1,&index);

    int *arr2=new int[n];
    index=0;
    BSTto_Array(root2,arr2,&index);

    int *mergedArr=mergeArray(arr1,arr2,m,n);

    return ArrayTo_BST(mergedArr,0,m+n-1);
}
int main()
{
        /* Create following tree as first balanced BST
        100
        / \
        50 300
    / \
    20 70
    */
    Node *root1 = newNode(100);
    root1->left     = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);

    /* Create following tree as second balanced BST
            80
        / \
        40 120
    */
    Node *root2 = newNode(80);
    root2->left     = newNode(40);
    root2->right = newNode(120);

    Node *root = mergeTrees(root1, root2, 5,3);
    printInorder(root);
    return 0;
}
