#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
};

Node *newNode(int key)
{
    Node *temp=new Node;
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}

void Morris_traversal(Node *root)
{
   
     Node *curr = root, *pre;
  
     while(curr!=NULL)
     {
       if(curr->left==NULL)
       {
          cout<<curr->data<<" ";
          curr = curr->right;
       }
       
       else
       {
           pre = curr->left;
           while(pre->right!=NULL && pre->right!=curr)
              pre = pre->right;
         
          if(pre->right==NULL)
          {
             pre->right = curr;
             curr = curr->left;
          }
         
          else
          {
              pre->right = NULL;
              cout<<curr->data<<" ";
              curr = curr->right;
          }
       }
     }
} 
}
int main()
{
    Node *root=NULL;
    root=newNode(1);
    root->left=newNode(2);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right=newNode(3);

    Morris_traversal(root);
    return 0;
}
