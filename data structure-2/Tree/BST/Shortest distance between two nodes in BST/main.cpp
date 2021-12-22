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

Node *insert(Node *root, int key)
{
    if(!root)
        return newNode(key);
    if(root->data>key)
        root->left=insert(root->left,key);
    else if(root->data<key)
        root->right=insert(root->right,key);
    return root;
}

int distance_from_CAncesstor(Node *root,int a)
{
    if(!root)
        return 0;
    if(a<root->data)
       return distance_from_CAncesstor(root->left,a) +1;

    else if(a>root->data)
       return distance_from_CAncesstor(root->right,a) +1;

    else if(root->data==a)
        return 0;
}
int find_distance(Node *root, int a, int b)
{
    if(!root)
        return 0;
    if(a<root->data and b<root->data)
       return find_distance(root->left,a,b);

    else if(a>root->data and b> root->data)
       return find_distance(root->right,a,b);

    return distance_from_CAncesstor(root,a) + distance_from_CAncesstor(root,b);
}
int main()
{
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 30);
    insert(root, 25);
    insert(root, 35);
    int a = 5, b = 15;
    if(a>b)
        swap(a,b);
    cout<<"\nshortest distance between a and b is:"<<find_distance(root, a, b);
    return 0;
}
