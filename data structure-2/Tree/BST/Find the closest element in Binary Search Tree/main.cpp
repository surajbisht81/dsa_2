#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

Node *newnode(int key)
{
    Node *temp=new Node;
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}

void closest_element(Node *root, int k, int &min,int &min_diff_key)
{
    if(!root)
        return ;

    if(root->data==k)
    {
        min_diff_key=root->data;
        return;
    }

    if(min>abs(root->data-k))
    {
        min=abs(root->data-k);
        min_diff_key=root->data;
    }

    if(root->data>k)
        closest_element(root->left, k, min, min_diff_key);
    else if(root->data<k)
        closest_element(root->right, k, min, min_diff_key);
}
int main()
{
    Node *root = newnode(9);
    root->left    = newnode(4);
    root->right   = newnode(17);
    root->left->left = newnode(3);
    root->left->right = newnode(6);
    root->left->right->left = newnode(5);
    root->left->right->right = newnode(7);
    root->right->right = newnode(22);
    root->right->right->left = newnode(20);
    int k=18;

    int min_diff_key=-1,min=INT_MAX;
    closest_element(root, k,min, min_diff_key);
    cout<<min_diff_key;
    return 0;
}
