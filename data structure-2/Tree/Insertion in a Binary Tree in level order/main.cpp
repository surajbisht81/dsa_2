#include<bits/stdc++.h>
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

void inorder(Node *root)
{
    if(!root)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node *insert_key(Node *root,int key)
{
    Node *curr=root;
    if(curr==NULL)
      return curr=new Node(key);
    queue<Node*>qu;

    qu.push(curr);
    while(!qu.empty())
    {
        Node *p=qu.front();
        qu.pop();

        if(p->left)
         qu.push(p->left);
        else
        {
            p->left=new Node(key);
            break;
        }

        if(p->right)
         qu.push(p->right);
        else
        {
            p->right=new Node(key);
            break;
        }
    }
    return root;
}

int main()
{
     Node* root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    cout<<"\ntree before inserting key.";
    inorder(root);

    root=insert_key(root,12);
    cout<<"\nafter inserting key.";
    inorder(root);
    return 0;
}
