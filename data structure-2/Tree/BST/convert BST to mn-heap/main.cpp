#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left,*right;
};

Node *getNode(int key)
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
int countNodes(Node *root)
{
    if(!root)
        return 0;
    return countNodes(root->left)+countNodes(root->right)+1;
}
void BSTtoArray(Node *root,int arr[],int *index)
{
    if(!root)
        return;
    BSTtoArray(root->left,arr,index);

    arr[*index]=root->data;
    (*index)++;

    BSTtoArray(root->right,arr,index);
}
void ArrayToBST(Node *root,int arr[],int *index)
{
    //using preorder to convert BST into min-heap
    if(!root)
        return;
    root->data=arr[*index];
    (*index)++;
    ArrayToBST(root->left,arr,index);
    ArrayToBST(root->right,arr,index);
}
void convertBST(Node *root)
{
    int n=countNodes(root);
    int *arr=new int[n];

    int index=0;
    BSTtoArray(root,arr,&index);

    index=0;
    ArrayToBST(root,arr,&index);
}
int main()
{
    Node *root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);

    printInorder(root);

    convertBST(root);
    cout<<endl;
    printInorder(root);
    return 0;
}
