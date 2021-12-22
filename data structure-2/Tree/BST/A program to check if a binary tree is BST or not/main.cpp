#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left,*right;
};
Node *node(int key)
{
    Node *temp=new Node;
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}

bool isBST(Node *root,int min,int max)
{
    if(!root)
        return 1;

    if(root->data<min or root->data>max)
        return 0;

    return isBST(root->left, min, root->data-1) and isBST(root->right, root->data-1, max);
}
int main()
{
    Node *root =  node(4);
    root->left = node(2);
    root->right = node(5);
    root->left->left = node(1);
    root->left->right = node(3);

    if(isBST(root, INT_MIN, INT_MAX))
        cout<<"it is BST.";
    else
        cout<<"it is not BST.";

    return 0;
}
