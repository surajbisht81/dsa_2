#include <iostream>
#include<vector>
#include<map>
using namespace std;
struct Node
{
    int data;
    Node *left,*right;
};
struct Node* newNode(int key)
{
    struct Node* node=new Node;
    node->data=key;
    node->left=node->right=NULL;
    return node;
};

void gethorizontaldistance(int hd,map<int,vector<int>> &mp,struct Node* root)
{
    if(root==NULL)
        return;
    mp[hd].push_back(root->data);
    gethorizontaldistance(hd-1,mp,root->left);
    gethorizontaldistance(hd+1,mp,root->right);
}
void printVerticalOrder(struct Node *root)
{
    map<int,vector<int>> mp;
    int hd=0;
    gethorizontaldistance(hd,mp,root);

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        for(int i=0;i<it->second.size();i++)
        {
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
 Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is n";
    printVerticalOrder(root);
    return 0;
}
