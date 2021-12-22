#include <iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left,*right;
};
struct Node *newNode(int key)
{
    struct Node *node=new Node;
    node->data=key;
    node->left=node->right=NULL;
    return node;
};

void printLevelOrder(struct Node *root)
{
    if(root==NULL)
        return;
        queue<Node *> q;
        q.push(root);
    while(q.empty()==false)
    {
        struct Node* p=q.front();
        cout<<p->data<<" ";
        q.pop();

        if(p->left!=NULL)
            q.push(p->left);
        if(p->right!=NULL)
            q.push(p->right);
    }
}
int main()
{
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}
