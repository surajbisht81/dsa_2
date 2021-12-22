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

void inorder(Node *root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void transform_tree(Node *root,int *sum)
{
    if(!root)
        return;

    transform_tree(root->right,sum);

    *sum = *sum+root->data;
    root->data= *sum - root->data;

    transform_tree(root->left,sum);
}
int main()
{
    Node *root = newNode(11);
    root->left = newNode(2);
    root->right = newNode(29);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(40);
    root->right->right->left = newNode(35);

    cout<<"before transformation. :";
    inorder(root);

    int sum=0;
    transform_tree(root,&sum);
    cout<<"\nafter transformation. :";
    inorder(root);
    return 0;
}
