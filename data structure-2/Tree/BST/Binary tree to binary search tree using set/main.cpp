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
void printInorder(Node *root)
{
    if(!root)
        return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}
void BinaryToSet(Node *root,set<int>&s)
{
    if(!root)
        return;
    BinaryToSet(root->left,s);
    s.insert(root->data);
    BinaryToSet(root->right,s);
}
void SetToBST(Node *root,set<int>&s)
{
    if(!root)
        return;
    SetToBST(root->left,s);

    auto it=s.begin();
    root->data=*it;
    s.erase(*it);

    SetToBST(root->right,s);
}
void BinaryToBST(Node *root)
{
    set<int> s;

    BinaryToSet(root, s);

    SetToBST(root,s);
}
int main()
{
     Node* root = newNode(5);
    root->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(11);

    BinaryToBST(root);
    printInorder(root);
    return 0;
}
