#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;
};
Node *newNode(int key)
{
    Node *newnode=new Node;
    newnode->data=key;
    newnode->left=nullptr;
    newnode->right=nullptr;
    return newnode;
}

void convert(Node *root)
{
    queue<Node*>qu;
    qu.push(root);
    Node *first=NULL,*second=NULL;

    while(!qu.empty())
    {
        first=qu.front();
        qu.pop();

        if(first->left)
            qu.push(first->left);
        if(first->right)
            qu.push(first->right);

        first->left=second;
        first->right=qu.front();
        second=first;
    }
}
void print_list(Node *root)
{
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->right;
    }
}
int main()
{
     Node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    convert(root);
    print_list(root);
    return 0;
}
