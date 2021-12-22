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

Node *constructBSTutil(int pre[], int *preorder, int low, int high, int size)
{
    if(*preorder>size or low>high)
        return NULL;


    Node *root = newNode(pre[*preorder]);
     *preorder = *preorder+1;

    if(low==high)
        return root;
    int i;
    for(i=low;i<=high;i++)
    {
        if(root->data < pre[i])
            break;
    }

    root->left=constructBSTutil(pre, preorder, *preorder, i-1, size);
    root->right=constructBSTutil(pre, preorder, i, high, size);
    return root;
}
Node *constructBST(int pre[],int size)
{
   int preorder=0;
   return constructBSTutil(pre, &preorder, 0, size-1, size);
}
void Inorder(Node *root)
{
    if(!root)
        return;
   Inorder(root->left);
   cout<<root->data<<" ";
   Inorder(root->right);
}
int main()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size= sizeof(pre)/sizeof(pre[0]);
    Node *root=constructBST(pre,size);
    Inorder(root);
    return 0;
}
