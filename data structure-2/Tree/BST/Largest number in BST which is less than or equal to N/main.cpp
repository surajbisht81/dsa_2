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
    if(root->data>key)
        root->left=insert(root->left,key);
    else if(root->data<key)
        root->right=insert(root->right,key);
    return root;
}

int smaller_no(Node *root, int N,int *min,int val)
{
    if(!root)
        return 0;
    smaller_no(root->left,N,min,val);

    if(root->data<N and root->data!=val)
    {
        *min=root->data;

    }
    else
    { 
        if(root->data == N)
          return root->data;
        else if(root->data==val)
          return val;
        else
         return *min;
    }

    smaller_no(root->right,N,min,val);
}
int main()
{
     int N = 59;

    // creating following BST
    /*
                  5
               /   \
             2     12
           /  \    /  \
          1   3   9   21
                     /   \
                    19   25  */
    Node *root=NULL;
    root = insert(root, 5);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 12);
    insert(root, 9);
    insert(root, 21);
    insert(root, 19);
    insert(root, 25);

    int min=INT_MIN;
    cout<<"\nLargest no in BST smaller than or equal to N is :"<<smaller_no(root, N,&min,25);
    return 0;
}
