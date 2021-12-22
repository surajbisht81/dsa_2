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

void specific_levelOrderUtil(Node *root,stack<Node*>&s)
{
   if(!root)
    return;

   if(root->left==NULL)
    return;

   queue<Node*>qu;
   qu.push(root->left);
   qu.push(root->right);

   Node *first,*second;
   while(!qu.empty())
   {
       first=qu.front();
       qu.pop();
       second=qu.front();
       qu.pop();

       s.push(second->left);
       s.push(first->right);
       s.push(second->right);
       s.push(first->left);

       if(first->left->left)
       {
           qu.push(first->right);
           qu.push(second->left);
           qu.push(first->left);
           qu.push(second->right);
       }
   }
}
void specific_levelOrder(Node *root)
{
    if(!root)
        return;
    stack<Node *>s;
    s.push(root);
    if(root->left==NULL)
    return;

    s.push(root->right);
    s.push(root->left);

    if(root->left->left)
        specific_levelOrderUtil(root,s);
    while(!s.empty())
    {
        cout<<s.top()->data<<" ";
        s.pop();
    }
}
int main()
{
   Node* root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    root->right->right->right  = newNode(15);

    root->left->left->left->left  = newNode(16);
    root->left->left->left->right  = newNode(17);
    root->left->left->right->left  = newNode(18);
    root->left->left->right->right  = newNode(19);
    root->left->right->left->left  = newNode(20);
    root->left->right->left->right  = newNode(21);
    root->left->right->right->left  = newNode(22);
    root->left->right->right->right  = newNode(23);
    root->right->left->left->left  = newNode(24);
    root->right->left->left->right  = newNode(25);
    root->right->left->right->left  = newNode(26);
    root->right->left->right->right  = newNode(27);
    root->right->right->left->left  = newNode(28);
    root->right->right->left->right  = newNode(29);
    root->right->right->right->left  = newNode(30);
    root->right->right->right->right  = newNode(31);

    cout<<"\nspecific level order traversal is :\n";
    specific_levelOrder(root);
    return 0;
}
