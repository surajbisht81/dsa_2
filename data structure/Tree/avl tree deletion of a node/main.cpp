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
    return (height(current->left)-height(current->right));
}
node *rotateright(node *root)
{
    node *y=root->left;
    node *temp=y->right;
    //rotate right;
    y->right=root;
    root->left=temp;
    root->height=1+maxvalue(height(root->left),height(root->right));
     y->height=1+maxvalue(height(y->left),height(y->right));
    return y;
}
node *rotateleft(node *root)
{
    node *y=root->right;
    node *temp=y->left;
    //left rotate;
    y->left=root;
    root->right=temp;
    root->height=1+maxvalue(height(root->left),height(root->right));
    y->height=1+maxvalue(height(y->left),height(y->right));


    return y;
}
node *findmax(node *temp)
{
    if(temp->right!=NULL)
        return findmax(temp->right);
    return temp;
}
node *deletenode(node *root,int data)
{
    if(root==NULL)
        return root;
    if(data<root->data)
       root->left=deletenode(root->left,data);
    else if(data>root->data)
         root->right=deletenode(root->right,data);
    else
    {
        //for one child or no child
        if(root->right==NULL)
        {
            node *temp=root->left;
            delete(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            node *temp=root->right;
            delete(root);
            return temp;
        }

        else

        {
            node *max=findmax(root->left);
            root->data=max->data;
            root->left=deletenode(root->left,max->data);
        }

    }
    root->height=1+maxvalue(height(root->left),height(root->right));
    int balance=balancefactor(root);
    if(balance>1 && balancefactor(root->left)>=0)
        return rotateright(root);
    if(balance>1 && balancefactor(root->left)<0)
    {
        root->left=rotateleft(root->left);
        return rotateright(root);
    }
    if(balance<-1 && balancefactor(root->right)<=0)
        return rotateleft(root);
    if(balance<-1 && balancefactor(root->right)>0)
    {
        root->right=rotateright((root->right));
        return rotateleft(root);
    }
    return root;
}
node *createnode(int data)
{
    node *newnode=new node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=1;
    return newnode;
}
node *insertnode(node *root,int data)
{
    if(root==NULL)
        return createnode(data);
    if(data<root->data)
        root->left=insertnode(root->left,data);
    else if(data>root->data)
        root->right=insertnode(root->right,data);
    else
        return root;
        //updating height of ancestor height;
    root->height=1+maxvalue(height(root->left),height(root->right));

    int balance=balancefactor(root);

    if(balance>1 && data<root->left->data)
        return rotateright(root);
    if(balance>1 && data>root->left->data)
    {
        root->left=rotateleft(root->left);
        return rotateright(root);
    }
    if(balance<-1 && data>root->right->data)
        return rotateleft(root);
    if(balance<-1 && data<root->right->data)
    {
        root->right=rotateright(root->right);
        return rotateleft(root);
    }
    return root;
}

void preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
  node *root=new node();
   root=NULL;
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

   root=deletenode(root,10);
   cout << "\nPreorder traversal after"
         << " deletion of 10 \n";
    preorder(root);
   return 0;
}
