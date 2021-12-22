/*Given a Binary Tree where each node has the following structure, write a function to populate the next pointer for all nodes. The next pointer for every node 
should be set to point to inorder successor.
struct node 
{ 
  int data; 
  struct node* left; 
  struct node* right; 
  struct node* next; 
} 
Initially, all next pointers have NULL values. Your function should fill these next pointers so that they point to inorder successor.*/


#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left,*right,*next;
    Node(int key)
    {
        data=key;
        left=right=NULL;
    }
};
void inorderSuccessor(Node *root)
{
    static Node *temp=NULL;
    if(root)
    {
        inorderSuccessor(root->right);

        root->next=temp;

        temp=root;

        inorderSuccessor(root->left);
    }
}
int main()
{
     Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);

    inorderSuccessor(root);

    while(root->left!=NULL)
    {
        root=root->left;
    }

    while(root)
    {
        cout<<"\nnext of "<<root->data<<" is:"<< (root->next ?root->next->data: -1)<<endl;
        root=root->next;
    }
    return 0;
}
