#include <iostream>

using namespace std;

class node
{
    public:
    int data;
    node *left,*right;
    int height;
};

int maxvalue(int a,int b)
{
    return (a>b)?a:b;
}
node *createnode(int data)
{
    node *newnode=new node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=1;
    return newnode;    // height of leaf node is always 1;
}
int height(node *current)
{
    if(current==NULL)
        return 0;
    return current->height;
}

int balancefactor(node *current)
{
    if(current==NULL)
        return 0;
    return  (height(current->left)-height(current->right));
}
node *rotateleft(node *root)
{
    node *y=root->right;
    node *temp=y->left;
    //perform left rotation
    y->left=root;
    root->right=temp;
    //update height;
    root->height=1+maxvalue(height(root->left),height(root->right));
    y->height=1+maxvalue(height(y->left),height(y->right));
    return y;
}
node *rotateright(node *root)
{
    node *y=root->left;
    node *temp=y->right;
    //perform right rotation
    y->right=root;
    root->left=temp;
    //update height;
    root->height=1+maxvalue(height(root->left),height(root->right));
    y->height=1+maxvalue(height(y->left),height(y->right));

    return y;
}

node *insertnode(node *root,int data)
{
    //creating bst or avl unbalanced tree;
    if(root==NULL)
        return createnode(data);
    if(data<root->data)
        root->left=insertnode(root->left,data);
    else if(data>root->data)
        root->right=insertnode(root->right,data);
    else
        return root;
    // updating the height of ancestor node;
   root->height=1+ (maxvalue(height(root->left),height(root->right)));

    // checking the balance factor of bst to make it avl tree
    int balance=balancefactor(root);
    //four cases arises
    if(balance>1 && root->left->data>data)
       return  rotateright(root);
    if(balance>1 && root->left->data<data)
      {
         root->left=rotateleft(root->left);
        return rotateright(root);
      }
    if(balance<-1 && root->right->data<data)
        return rotateleft(root);
    if(balance<-1 && root->right->data>data)
       {
         root->right= rotateright(root->right);
        return rotateleft(root);
       }
    return root;
}
void preorder(node *root)
{
   if(root!=NULL)
   {cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
   }
}
int main()
{
   node* root=NULL;
      root = insertnode(root, 9);
      root = insertnode(root, 5);
    root = insertnode(root, 10);
    root = insertnode(root, 0);
    root = insertnode(root, 6);
    root = insertnode(root, 11);
    root = insertnode(root, -1);
    root = insertnode(root, 1);
    root = insertnode(root, 2);
   cout<<"\npreorder traversal is:\n";
   preorder(root);
   return 0;
}
