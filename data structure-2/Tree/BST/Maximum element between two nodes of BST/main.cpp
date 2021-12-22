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

Node *insert(Node *root,int key)
{
    if(root==NULL)
        return newNode(key);
    if(key<root->data)
        root->left=insert(root->left,key);
    else
        root->right=insert(root->right,key);
    return root;
}
int max_node(Node *root, int a)
{
    int maxx=INT_MIN;
    while(root->data!=a)
    {
        if(root->data>a)
        {
            maxx=max(maxx, root->data);
            root=root->left;
        }

        else if(root->data<a)
        {
            maxx=max(maxx, root->data);
            root=root->right;
        }
    }
    return max(a,maxx);
}
int maxEmt(Node *root, int a, int b)
{
    Node *curr=root;
    if(curr==NULL)
        return 0;
    while((curr->data>a and curr->data>b) or (curr->data<a and curr->data<b))
    {
        if(curr->data>a and curr->data>b)
            curr=curr->left;
        else if(curr->data<a and curr->data<b)
            curr=curr->right;
    }
    return max(max_node(curr,a), max_node(curr, b));
}
int main()
{
    int arr[] = { 18, 36, 9, 6, 12, 10, 1, 8 };
    int a = 1, b = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = NULL;
    for(int i=0 ;i<n;i++)
        root=insert(root,arr[i]);

    cout<<"\nmax element between a and b is:"<<maxEmt(root, a, b);
    return 0;
}
