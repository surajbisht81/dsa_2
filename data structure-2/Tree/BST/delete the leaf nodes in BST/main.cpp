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

Node *insert(Node *root,int key)
{
    if(root==NULL)
        return newNode(key);
    if(key<root->data)
        root->left=insert(root->left,key);
    else
        root->right=insert(root->right,key);
    return root;
}
void printinorder(Node *root)
{
    if(!root)
        return;
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}
Node *delete_leafs(Node *root)
{
    if(!root)
        return NULL;
    if(root->left==NULL and root->right==NULL)
    {
        delete root;
        return NULL;
    }
    root->left=delete_leafs(root->left);
    root->right=delete_leafs(root->right);
    return root;
}
int main()
{
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 30);
    insert(root, 25);
    insert(root, 35);

    cout<<"\nbefore deleting leafs:";
    printinorder(root);

    delete_leafs(root);

    cout<<"\nafter deleting leafs:";
    printinorder(root);
}
