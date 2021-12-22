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
void K_th_largestelmt(Node *root,int k,int *cnt)
{
    if(root==NULL)
        return ;
    K_th_largestelmt(root->right,k,cnt);

    (*cnt)++;
    if(*cnt==k)
        cout<<"Kth largest element is :"<<root->data;

    K_th_largestelmt(root->left,k,cnt);
}
int main()
{
     Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout<<"\nkth largest element is:";
    int k=3;
    int cnt=0;
    K_th_largestelmt(root,k,&cnt);
    return 0;
}
