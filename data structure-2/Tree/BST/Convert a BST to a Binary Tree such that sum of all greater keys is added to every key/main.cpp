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
    ConvertBST(root->right,sum);

    *sum = *sum +root->data;
    root->data=*sum;

    ConvertBST(root->left,sum);
}
int main()
{
    Node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(13);

    printInorder(root);
    int sum=0;
    ConvertBST(root,&sum);

    cout<<endl;
    printInorder(root);
    return 0;
}
