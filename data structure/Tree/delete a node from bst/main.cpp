#include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
struct node* createnode(int data)
{
    node *newnode=new node();
    newnode->data=data;
    newnode->left= newnode->right=NULL;
    return newnode;
};
struct node* insertnode(struct node* root,int data)
{
    if(root==NULL)
        return createnode(data);
    else if(data<root->data)
       root->left=insertnode(root->left,data);
    else if(data>root->data)
        root->right=insertnode(root->right,data);
    return root;
};
void inorder(struct node* root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<"\t"<<root->data;
    inorder(root->right);
}

struct node* findmin(struct node *temp)
{
    if(temp->left!=NULL)
        return findmin(temp->left);
    return temp;
};
struct node* deletenode(struct node* root,int data)
{
    if(root==NULL)
    {
        cout<<"\ntree is empty.";
        return root;
    }
    else if(data<root->data)
        root->left=deletenode(root->left,data);
    else if(data>root->data)
        root->right=deletenode(root->right,data);
    else
    {
        //DELETING NODE HAVING ONE OR NO CHILD;
        if(root->left==NULL)
        {
            node *temp=root->right;
            delete(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node *temp=root->left;
            delete(root);
            return temp;
        }
        //DELETING NODE HAVING TWO CHILD;
        //find the minimum node in right subtree(find inorder successor in right subtree);
        node *temp=findmin(root->right);
        root->data=temp->data;
        root->right=deletenode(root->right,temp->data);
    }
    return root;
};
int main()
{
    int data,choice;
    node *root=NULL;
    while(1)
    {
    cout<<"\n1.insert node \n2.delete node. \n3.inorder traversal \n4.exit";
    cout<<"\nenter your choice:";
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"\nenter node to inert:";
        cin>>data;
        root=insertnode(root,data);
        break;
    case 2:
      cout<<"\nenter the data of node to delete:";
      cin>>data;
      deletenode(root,data);
      break;
    case 3:
      cout<<"\ninorder tversal of modified bst is:\n";
      inorder(root);
      break;
    case 4:
        exit(0);
        break;
    default:
        cout<<"\nenter valid no.";
        break;
    }
}
}
