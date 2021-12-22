#include <iostream>
#include<map>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    int hd;
    struct Node *left,*right;
};
struct Node *newNode(int data)
{
    struct Node *node=new Node;
    node->key=data;
    node->left=node->right=NULL;
    return node;
};
void topview(struct Node *root)
{
    map<int,int> mp;

    queue<Node*> q;
    int hd=0;
    root->hd=hd;
    q.push(root);

    while(q.size())
    {
        hd=root->hd;
        if(mp.count(hd)==0)
            mp[hd]=root->key;
        if(root->left)
        {
            root->left->hd=hd-1;
            q.push(root->left);
        }
        if(root->right)
        {
            root->right->hd=hd+1;
            q.push(root->right);
        }
        q.pop();
        root=q.front();
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->second<<" ";
    }
}
int main()
{
     Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    topview(root);
    return 0;
}
