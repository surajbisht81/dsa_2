#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

void inorder(struct Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void flatten(Node *root)
{
    if(!root or (!root->left and !root->right))
         return ;

    if(root->left)
    {
        flatten(root->left);
        Node *tempRight = root->right;

        root->right = root->left;
        root->left = NULL;

        Node *t = root->right;
        while(t->right!=NULL)
             t = t->right;
        t->right = tempRight;
    }
    flatten(root->right);
}
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);

    flatten(root);
    inorder(root);
    return 0;
}
