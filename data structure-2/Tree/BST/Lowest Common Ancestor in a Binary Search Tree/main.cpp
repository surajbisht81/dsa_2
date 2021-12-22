#include<bits/stdc++.h>
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

Node *LCA(Node *root,int n1,int n2)
{
    if(!root)
        return nullptr;
    if(root->data<n1 && root->data<n2)
      return  LCA(root->right,n1,n2);
    if(root->data>n1 && root->data>n2)
      return   LCA(root->left,n1,n2);
    return root;
}
int main()
{
    Node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    Node *lca=LCA(root,n1,n2);
    cout<<"lowest common ancestor of "<<n1 <<"and"<<n2<<"is "<<lca->data;
    return 0;
}
