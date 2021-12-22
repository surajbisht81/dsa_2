/*Given a Binary search Tree that contains positive integer values greater then 0. The task is to check whether the BST contains a dead end or not. 
Here Dead End means, we are not able to insert any element after that node.*/

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

void fill_sets(Node *root, unordered_set<int>&all_nodes, unordered_set<int>&all_leaf)
{
    if(!root)
        return;
    all_nodes.insert(root->data);

    if(root->left==NULL && root->right==NULL)
        all_leaf.insert(root->data);

    fill_sets(root->left, all_nodes, all_leaf);
    fill_sets(root->right, all_nodes, all_leaf);
}
bool dead_End(Node *root)
{
    unordered_set<int> all_nodes, all_leaf;
    all_nodes.insert(0);   // for exception of 1, if 1 is present then 0 must be there in set to create dead end;

    fill_sets(root, all_nodes, all_leaf);

    for(auto i=all_leaf.begin(); i!=all_leaf.end(); i++)
    {
        int it= (*i);
        if(all_nodes.find(it+1)!=all_nodes.end() && all_nodes.find(it-1)!=all_nodes.end())
            return true;
    }
    return false;
}
int main()
{
    Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);

   if(dead_End(root))
    cout<<"Yes.";
   else
    cout<<"No";
   return 0;
}


/*
 // Another method, use of if binary tree is bst or not; 
bool deadEnd(Node* root, int min=1, int max=INT_MAX) 
{ 
    // if the root is null or the recursion moves 
    // after leaf node it will return false 
    // i.e no dead end. 
    if (!root) 
        return false; 
  
    // if this occurs means dead end is present. 
    if (min == max) 
        return true; 
  
    // heart of the recursion lies here. 
    return deadEnd(root->left, min, root->data - 1) || 
           deadEnd(root->right, root->data + 1, max); 
} 
*/