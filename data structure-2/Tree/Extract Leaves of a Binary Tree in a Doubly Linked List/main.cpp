#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int key)
{
    Node *newnode = new Node;
    newnode->data=key;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void print(Node *root)
{
    if(!root)
        return;

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
void Print_DLL(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->right;
    }
}

Node *convertLeavesToDLL(Node *root, Node **head_ref)
{
    if(!root)
        return NULL;

    if(!root->left and !root->right)
    {
        root->right = *head_ref;

        if(*head_ref!=NULL)
            (*head_ref)->left = root;

        *head_ref = root;

        return NULL;
    }

    root->right = convertLeavesToDLL(root->right, head_ref);
    root->left = convertLeavesToDLL(root->left, head_ref);
    return root;
}

int main()
{
    Node *head = NULL;
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(8);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    cout<<"\ninorder traversal of tree: ";
    print(root);

    convertLeavesToDLL(root, &head);

    cout<<"\nlinked list of leaves is: ";
    Print_DLL(head);

    cout<<"\nmodified tree is: ";
    print(root);
    return 0;
}
