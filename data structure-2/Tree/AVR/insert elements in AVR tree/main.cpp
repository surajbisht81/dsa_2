#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    int height;
};

int max(int a, int b)
{
    return a>b ? a:b;
}
int height(Node *node)
{
    if(!node)
        return 0;
    return node->height;
}

int get_balance(Node *root)
{
    if(!root)
        return 0;
    return height(root->left)-height(root->right);
}

Node *newNode(int key)
{
    Node *temp= new Node;
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}
Node *leftRotate(Node *root)
{
    Node *temp=root->right;
    Node *new_temp = temp->left;

    //perform rotation
    temp->left=root;
    root->right=new_temp;

    //updating the heights
    root->height=max(height(root->left), height(root->right))+1;
    temp->height=max(height(temp->left), height(temp->right))+1;
    return temp;
}
Node *rightRotate(Node *root)
{
    Node *temp=root->left;
    Node *new_temp = temp->right;

    //perform rotation
    temp->right=root;
    root->left=new_temp;

    //updating the heights
    root->height=max(height(root->left), height(root->right))+1;
    temp->height=max(height(temp->left), height(temp->right))+1;
    return temp;
}
Node *insert(Node *root, int key)
{
    // first simply insert node as in BST
    if(!root)
        return newNode(key);
    if(key<root->data)
        root->left=insert(root->left,key);
    else if(key>root->data)
        root->right=insert(root->right,key);
    else
      return root;


    //update the height of ancestor of the node
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = get_balance(root);

    //there are 4 cases
    //left left case
    if(balance>1 and key<root->left->data)
        return rightRotate(root);
    //right right case
    if(balance<-1 and key>root->right->data)
        return leftRotate(root);
    //left right rotate
    if(balance >1 and key> root->left->data)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    //right left rotate
    if(balance<-1 and key<root->right->data)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void preorder(Node *root)
{
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{

    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    preorder(root);

    return 0;
}
