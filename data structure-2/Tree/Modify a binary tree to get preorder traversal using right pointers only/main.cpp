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
    Node *new_node=new Node;
    new_node->data=key;
    new_node->left=new_node->right=NULL;
    return new_node;
}

void preorder(Node *root)
{
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void usingRightPointer(Node *root)
{
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->right;
    }
}
void modify_tree(Node *root)
{
    if(!root)
        return;
    stack<Node*>s;
    s.push(root);

    Node *prev=NULL;
    while(!s.empty())
    {
        Node *p=s.top();
        s.pop();

        if(p->right)
         s.push(p->right);
        if(p->left)
         s.push(p->left);

       if(prev!=NULL)
       {
           prev->right=p;
       }
       prev=p;
    }
}
int main()
{
   Node *root=newNode(10);
   root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    cout<<"\ninitial preorder traversal is:\n";
    preorder(root);

    modify_tree(root);

    cout<<"\npreorder using only right pointers:\n";
    usingRightPointer(root);
    return 0;
}
