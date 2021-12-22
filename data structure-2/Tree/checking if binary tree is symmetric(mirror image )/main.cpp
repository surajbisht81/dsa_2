/*Given a binary tree, check whether it is a mirror of itself.

For example, this binary tree is symmetric:

     1
   /   \
  2     2
 / \   / \
3   4 4   3*/

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

bool check_for_symmetry(Node *root1,Node *root2)
{
    if(root1==NULL  && root2==NULL)
        return true;

    if(root1 && root2 && root1->data==root2->data)
        return check_for_symmetry(root1->left,root2->right) && check_for_symmetry(root1->right,root2->left);

    return false;
}
int main()
{

    Node *root        = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(2);
    root->left->left  = new Node(3);
    root->left->right = new Node(4);
    root->right->left  = new Node(4);
    root->right->right = new Node(3);
    if(check_for_symmetry(root,root))
            cout<<"symmetric";
    else
        cout<<"\nnot symmetric.";
    return 0;
}
