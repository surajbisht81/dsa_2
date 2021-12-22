/*Given a binary tree, the task is to print the nodes of the tree in an anti-clockwise spiral manner.

Examples:

Input:
     1
   /  \
  2    3
 / \  / \
4   5 6  7
Output: 1 4 5 6 7 3 2*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int key)
    {
        data=key;
        left=right=NULL;
    }
};
int height(Node *root)
{
    if(!root)
        return 0;

    int l = height(root->left);
    int r = height(root->right);

    return max(l, r)+1;
}

void rightToleft(Node *root, int level)
{
    if(!root)
        return;

    if(level==1)
         cout<<root->data<<" ";

    if(level>1)
    {
        rightToleft(root->right, level-1);
        rightToleft(root->left, level-1);
    }
}

void leftToright(Node *root, int level)
{
    if(!root)
        return;

    if(level==1)
         cout<<root->data<<" ";

    if(level>1)
    {
        leftToright(root->left, level-1);
        leftToright(root->right, level-1);
    }
}

void AnticlockwiseSpiral(Node *root)
{
    int i = 1;
    int j = height(root);

    int flag=0;
    while(i<=j)
    {
        if(flag==0)
        {
            rightToleft(root, i);
            i++;
            flag=1;
        }
        else
        {
            leftToright(root, j);
            j--;
            flag=0;
        }
    }
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    root->left->left->left = new Node(10);
    root->left->left->right = new Node(11);
    root->right->right->left = new Node(8);

    AnticlockwiseSpiral(root);
    return 0;
}
