#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left,*right;
};
Node *newNode(int key)
{
    Node *temp=new Node;
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}
void printInorder(Node *root)
{
    if(!root)
        return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void ConvertBST(Node *root,int *sum)
{
    if(!root)
        return;
    ConvertBST(root->left,sum);

    *sum = *sum +root->data;
    root->data=*sum;

    ConvertBST(root->right,sum);
}
int main()
{
    Node* root = newNode(9);
    root->left = newNode(6);
    root->right = newNode(15);
    root->left->left=newNode(3);
    root->left->right=newNode(7);

    printInorder(root);
    int sum=0;
    ConvertBST(root,&sum);

    cout<<endl;
    printInorder(root);
    return 0;
}
