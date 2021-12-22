#include <iostream>

using namespace std;
struct node
{
    int data;
    node *left,*right;
};
int found=0;
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
int findmin(struct node* root)
{
    if(root==NULL)
       {cout<<"\nerror.";
        return -1;
       }
    else if(root->left==NULL)
        return root->data;
  return findmin(root->left);
}
int findmax(struct node* root)
{
    if(root==NULL)
    {
        cout<<"\nerror.";
        return -1;
    }
    else if(root->right==NULL)
        return root->data;
    return findmax(root->right);
}
struct node* findgivenvalue(struct node* root,int value)
{
    if(root==NULL ||  root->data==value)
        return  root;
    else if(value<root->data)
    {
        return findgivenvalue(root->left,value);
    }
    else if(value>root->data)
    {
        return findgivenvalue(root->right,value);
    }
    return root;
}
int main()
{
    struct node *root=NULL;
     int value;
    root=insertnode(root,50);
    insertnode(root,40);
    insertnode(root,30);
    insertnode(root,45);
    insertnode(root,60);
    insertnode(root,55);
    insertnode(root,70);
    cout<<"\nbst is created.";
    cout<<"\nminimum node is:"<<findmin(root);
    cout<<"\nmaximum node is:"<<findmax(root);
    cout<<"\nenter value to found:";
    cin>>value;
    root=findgivenvalue(root,value);
    cout<<"\nvalue is found at:"<<root;
    return 0;
}
