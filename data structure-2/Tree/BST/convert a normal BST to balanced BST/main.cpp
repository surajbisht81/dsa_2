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
    cout<<root->data<<" ";
    printInorder(root->left);
    printInorder(root->right);
}

void BSTtoVector(vector<Node*>&v, Node *root)
{
    if(!root)
        return;
    BSTtoVector(v,root->left);
    v.push_back(root);
    BSTtoVector(v,root->right);
}

Node *VectorToBST(vector<Node*>&v,int start,int end)
{
        if(start>end)
            return NULL;

        int mid=(start+end)/2;
        Node *root = v[mid];

        root->left = VectorToBST(v,start,mid-1);
        root->right = VectorToBST(v,mid+1,end);

    return root;
}
Node *buildTree(Node *root)
{
    vector<Node*> v;
    BSTtoVector(v,root);

    int n=v.size();
    return VectorToBST(v, 0,n-1);
}
int main()
{
    Node* root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);

    root=buildTree(root);
    printInorder(root);
    return 0;
}
