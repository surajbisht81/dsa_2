#include <bits/stdc++.h>
using namespace std;

// using level order traversal;
struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int key)
{
   Node *new_node = new Node;
   new_node->data=key;
   new_node->left=new_node->right=NULL;
   return new_node;
}

vector<int> Kdistance(struct Node *root, int k)
{
    vector<vector<int>> level(100);                    //size dena necessary hai warna segmentation error aayega

    queue<struct Node*> qu;
    qu.push(root);
    int i=-1;

    while(!qu.empty())
    {
       int size=qu.size();
       i++;

       while(size--)
       {
         struct Node *p = qu.front();
         qu.pop();

         level[i].push_back(p->data);

         if(p->left)
          qu.push(p->left);

         if(p->right)
           qu.push(p->right);
       }
    }

    vector<int> res = level[k];
   return res;
}

int main()
{
    Node *root = newNode(3);
    root->left = newNode(2);
    root->left->right = newNode(1);
    root->left->right->left = newNode(5);
        root->left->right->right = newNode(3);

    int k = 3;
   vector<int> res = Kdistance(root, k);

   for(int i=0; i<res.size(); i++)
    cout<<res[i]<<" ";

    return 0;
}

/*
//using recursion;
// Recursive function to print right view of a binary tree.

void KdistanceUtil(struct Node *root,int k,vector<int> &nodes){
    // Base Case
    if (root==NULL)  return;

    if (k==0)
        nodes.push_back(root->data);

    // Recur for right subtree first, then left subtree
    KdistanceUtil(root->left, k-1,nodes);
    KdistanceUtil(root->right, k-1,nodes);
}

vector<int> Kdistance(struct Node *root, int k)
{
    vector<int> nodes;
    KdistanceUtil(root,k,nodes);
    return nodes;
}*/
