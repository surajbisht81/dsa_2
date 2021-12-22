#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left,*right;
};
struct node* createnode(int data)
{
    struct node *newnode=new node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* insertnode(struct node* root, int data)
{
    if(root==NULL)
        return createnode(data);
    else if(data<=root->data)
           root->left= insertnode(root->left,data);
    else if(data>root->data)
         root->right=insertnode(root->right,data);
  return root;
}
void inorder(struct node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<"\t"<<root->data;
    inorder(root->right);
}
void preorder(struct node* root)
{
    if(root==NULL)
        return ;
    cout<<"\t"<<root->data;
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root)
{
    if(root==NULL)
        return ;
    postorder(root->left);
    postorder(root->right);
    cout<<"\t"<<root->data;
}
int main()
{
    struct node *root=NULL;

    root=insertnode(root,50);
    insertnode(root,40);
    insertnode(root,30);
    insertnode(root,45);
    insertnode(root,60);
    insertnode(root,55);
    insertnode(root,70);
    cout<<"\nbst is created.";
    cout<<"\ninorder traversal of bst:\n";
    inorder(root);
    cout<<"\npreorder traversal of bst:\n";
    preorder(root);
    cout<<"\npostorder traversal of bst:\n";
    postorder(root);
}
