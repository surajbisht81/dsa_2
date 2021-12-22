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

Node *sortedArrayToBST(int arr[], int start, int end)
{
    if(start>end)
        return NULL;

        int mid = (start+end)/2;
        Node *root = newNode(arr[mid]);

        root->left=sortedArrayToBST(arr, start, mid-1);
        root->right=sortedArrayToBST(arr, mid+1, end);

        return root;
}

void printLevelorder(Node *root)
{
    if(root==NULL)
        return;

    queue<Node *> qu;

    qu.push(root);

    while(!qu.empty())
    {
        Node *p=qu.front();
        qu.pop();

        cout<<p->data<<" ";
        if(p->left)
            qu.push(p->left);
        if(p->right)
            qu.push(p->right);
    }
}
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    //first sort the given array
    sort(arr, arr+n);

    Node *root = sortedArrayToBST(arr, 0, n-1);

    printLevelorder(root);
    return 0;
}
