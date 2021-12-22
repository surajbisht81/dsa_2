#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int key)
{
    Node *newnode = new Node;
    newnode->data=key;
    newnode->left=newnode->right=NULL;
    return newnode;
}

Node *TreeToLLUtil(Node *root)
{
    if(!root)
        return root;

    if(root->left)
    {
        Node *temp = TreeToLLUtil(root->left);

        for( ; temp->right!=NULL; temp = temp->right);

        temp->right = root;
        root->left = temp;
    }
    if(root->right)
    {
        Node *temp = TreeToLLUtil(root->right);

        for( ; temp->left!=NULL; temp = temp->left);

        temp->left = root;
        root->right = temp;
    }
    return root;
}

Node *TreeToLL(Node *root)
{
    if(!root)
        return root;

    TreeToLLUtil(root);

    while(root->left!=NULL)
            root = root->left;
    return root;
}
void print_List(Node *root)
{
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root = root->right;
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

    Node *temp = TreeToLL(root);
    print_List(temp);
    return 0;
}

/*
 Another method of doing same problem

  void BinaryTree2DoubleLinkedList(node *root, node **head)
{
	if(!root)
       return;

    static Node* prev = NULL;

    BinaryTree2DoubleLinkedList(root->left, head);

    if(prev==NULL)
      head = root;
    else
    {
      root->left = prev;
      prev->right = root;
    }
   prev = root;

   BinaryTree2DoubleLinkedList(root->right, head);

}
*/

