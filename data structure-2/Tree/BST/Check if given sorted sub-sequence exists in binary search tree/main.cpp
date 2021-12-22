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
Node *insert(Node *root, int key)
{
    if(root==NULL)
        return newNode(key);
    else if(root->data>key)
        root->left=insert(root->left,key);
    else if(root->data<key)
        root->right=insert(root->right,key);
    return root;
}
void subExistUtil(Node *root,int sub[],int *idx)
{
    if(root==NULL)
        return;
    subExistUtil(root->left,sub,idx);

    if(sub[*idx]==root->data)
    (*idx)++;

    subExistUtil(root->right,sub,idx);
}
bool subExist(Node *root,int sub[],int n)
{
    if(root==NULL)
        return 0;
    int index=0;
    subExistUtil(root,sub,&index);

    if(index==n)
        return true;
    else
        return false;
}
int main()
{
    Node *root=NULL;
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);

    int sub[]= {4, 6, 8, 14};
    int n=sizeof(sub)/sizeof(sub[0]);

    subExist(root,sub,n)?cout<<"present." : cout<<"Not present.";
    return 0;
}
