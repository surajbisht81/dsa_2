#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left,*right;
    Node(int key)
    {
        data=key;
        left=right=NULL;
    }
};

void preorder(Node *root)
{
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inserting_inorder(Node *root,vector<int> &v)
{
    if(!root)
        return;
    inserting_inorder(root->left,v);
    v.push_back(root->data);
    inserting_inorder(root->right,v);
}

void inorder_pre_succUtil(Node *root,vector<int>v,int *i)
{
    if(!root)
        return;
    inorder_pre_succUtil(root->left,v,i);

    root->data= v[*i-1]+v[*i+1];
    ++*i;
    inorder_pre_succUtil(root->right,v,i);
}
void inorder_pre_succ(Node *root)
{
    vector<int>v;
    v.push_back(0);
    inserting_inorder(root,v);
    v.push_back(0);
    int i=1;
    inorder_pre_succUtil(root,v,&i);
}
int main()
{
   struct Node* root = new Node(1); /*         1        */
    root->left = new Node(2);        /*       /   \      */
    root->right = new Node(3);       /*     2      3     */
    root->left->left = new Node(4);  /*    /  \  /   \   */
    root->left->right = new Node(5); /*   4   5  6   7   */
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<"\nbefore insetion.\n";
    preorder(root);
    inorder_pre_succ(root);
    cout<<"\nafter insertion.\n";
    preorder(root);
    return 0;
}
