/*Given a Binary Tree having positive and negative nodes, the task is to find maximum sum level in it.*/

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

int maxLevelSum(Node *root)
{
    int max_sum=INT_MIN;
    queue<Node*>qu;
    qu.push(root);

    while(!qu.empty())
    {
        int sum=0;
        int count=qu.size();

        while(count--)
        {

         Node *p=qu.front();
         qu.pop();

         sum+=p->data;
           if(p->left)
              qu.push(p->left);
           if(p->right)
              qu.push(p->right);

        }
        max_sum=max(max_sum,sum);
    }
    return max_sum;
}
int main()
{
    Node *root = newNode(1);
    root->left         = newNode(2);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left  = newNode(6);
    root->right->right->right  = newNode(7);

    cout << "Maximum level sum is "
         << maxLevelSum(root) << endl;
    return 0;
}
