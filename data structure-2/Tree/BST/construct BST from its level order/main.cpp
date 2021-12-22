#include <bits/stdc++.h>
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

Node *levelOrder(Node *root,int data)
{
    if(root==NULL)
    {
        root=getNode(data);
        return root;
    }
    if(data<=root->data)
        root->left=levelOrder(root->left,data);
    else
        root->right=levelOrder(root->right,data);
    return root;
}
Node *convert_ToBST(int arr[], int n)
{
    Node *root=NULL;

    for(int i=0;i<n;i++)
        root=levelOrder(root,arr[i]);
    return root;
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
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n=sizeof(arr)/sizeof(arr[0]);

    Node *root=convert_ToBST(arr,n);
    printInorder(root);
    return 0;
}
