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
int countNodes(Node *root)
{
    if(!root)
        return 0;
    return countNodes(root->left)+countNodes(root->right)+1;
}

int compare(const void *a,const void *b)
{
    return ( *(int*)a - *(int*)b);
}
void binaryToarray(int arr[], int *i,Node *root)
{
    if(!root)
        return;
    binaryToarray(arr, i,root->left);
    arr[*i]=root->data;
    (*i)++;
    binaryToarray(arr, i,root->right);
}

void arrayToBST(int arr[],int *i,Node *root)
{
    if(!root)
        return;

    arrayToBST(arr, i,root->left);
    root->data=arr[*i];
    (*i)++;
    arrayToBST(arr, i,root->right);
}
void convert_binaryToBST(Node *root)
{
    if(!root)
        return;

    int n=countNodes(root);
    int *arr= new int[n];
    int i=0;
    binaryToarray(arr, &i,root);

    // sort the array using quick sort using quick sort library
    qsort(arr,n,sizeof(arr[0]),compare);

    //convert binary tree to bst using sorted array
    i=0;
    arrayToBST(arr,&i,root);
}
void printInorder(Node *root)
{
    if(!root)
        return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
int main()
{
    Node *root=NULL;
     /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /      \
      20       5   */
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    convert_binaryToBST(root);
    printInorder(root);
    return 0;
}
