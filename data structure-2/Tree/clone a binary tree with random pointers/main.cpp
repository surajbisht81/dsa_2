#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right, *random;
};
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = temp->random = NULL;
    return temp;
}

void PrintTree(Node *root)
{
    if(root==NULL)
        return;

    PrintTree(root->left);

    cout<<"["<<root->key<<" ";
    if(root->random==NULL)
      cout<<"NULL],";
    else
        cout<<root->random->key<<"],";

    PrintTree(root->right);
}

Node *CopyLeftRightNode(Node *root, unordered_map<Node *, Node * > &mp)
{
    if(root==NULL)
        return root;
    Node *clone = newNode(root->key);
    mp[root] = clone;

    clone->left = CopyLeftRightNode(root->left, mp);
    clone->right = CopyLeftRightNode(root->right, mp);
    return clone;
}

void CopyRandom(Node *root, Node *cloneTree, unordered_map<Node*, Node*> &mp)
{
    if(cloneTree==NULL)
        return;
    cloneTree->random = root->random;
    CopyRandom(root->left, cloneTree->left, mp);
    CopyRandom(root->right, cloneTree->right, mp);
}

Node *clone(Node *root)
{
    unordered_map<Node *, Node *> mp;
    Node *cloneTree = CopyLeftRightNode(root, mp);
    CopyRandom(root, cloneTree, mp);
    return cloneTree;
}
int main()
{
    Node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->random = tree->left->right;
    tree->left->left->random = tree;
    tree->left->right->random = tree->right;

     cout<<"\noriginal Tree:\n";
     PrintTree(tree);

     Node *cloneNode = clone(tree);

     cout<<"\nClone Tree:\n";
     PrintTree(cloneNode);

     return 0;
}
*/
