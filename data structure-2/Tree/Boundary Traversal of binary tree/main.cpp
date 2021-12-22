#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}
void printleft(struct node *root)
{
    if(!root)
        return;

    if(root->left)
    {
        cout<<root->data<<" ";
        printleft(root->left);
    }
    else if(root->right)
    {
	cout<<root->data<<" ";
        printleft(root->right);
    }
}
void printright(struct node *root)
{
    if(!root)
        return;
    if(root->right)
    {
        cout<<root->data<<" ";
        printright(root->right);
    }
    else if(root->left)
    {
        printright(root->left);
    }
}
void printLeaves(struct node* root)
{
    if(!root)
        return;

    if(!root->left and !root->right)
         cout<<root->data<<" ";
    else
    {
        printLeaves(root->left);
        printLeaves(root->right);
    }
}
void printBoundary(struct node *root)
{
    if(!root)
        return;

    cout<<root->data<<" ";
    printleft(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printright(root->right);
}
int main()
{
      struct node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    printBoundary(root);

    return 0;
}
