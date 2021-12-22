#include <bits/stdc++.h>
using namespace std;

/*Given tree:
               a
            /     \
           b       c
         /  \     /  \
        d    e    f    g
       / \  / \  / \  / \
       h  i j  k l  m  n  o

Modified tree:
             a
            /     \
           c       b
         /  \     /  \
        d    e    f    g
       / \  / \  / \  / \
      o  n m  l k  j  i  h   */
#define MAX  100
class Node
{
public:
    char data;
    Node *left,*right;
};

Node *newNode(int key)
{
    Node *new_node =new Node;
    new_node->data=key;
    new_node->left=new_node->right=NULL;
    return new_node;
}

void inorder(Node *root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void reverse_array(char arr[],int n)
{
    int l=0,r=n-1;
    while(l<r)
    {
        char temp=arr[r];
        arr[r]=arr[l];
        arr[l]=temp;
        l++;
        r--;
    }
}
void fill_inorder(Node *root, char arr[],int *index,int l)
{
    if(!root)
        return ;

    fill_inorder(root->left,arr,index,l+1);

    if(l%2!=0)
    {
        arr[*index]=root->data;
        (*index)++;
    }

    fill_inorder(root->right,arr,index,l+1);
}

void modify_inorder(Node *root,char arr[],int *index,int l)
{
   if(!root)
        return;
   modify_inorder(root->left,arr,index,l+1);

   if(l%2!=0)
   {
       root->data=arr[*index];
       (*index)++;
   }
   modify_inorder(root->right,arr,index,l+1);
}

void reverse_alternateNode(Node *root)
{
    char *arr=new char[MAX];
    int index=0;
    fill_inorder(root,arr,&index,0);

    reverse_array(arr,index);
    index=0;

    modify_inorder(root,arr,&index,0);
}
int main()
{
    Node *root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->left = newNode('f');
    root->right->right = newNode('g');
    root->left->left->left = newNode('h');
    root->left->left->right = newNode('i');
    root->left->right->left = newNode('j');
    root->left->right->right = newNode('k');
    root->right->left->left = newNode('l');
    root->right->left->right = newNode('m');
    root->right->right->left = newNode('n');
    root->right->right->right = newNode('o');

    cout<<"\ninitial inorder is:\n";
    inorder(root);

    reverse_alternateNode(root);

    cout<<"\nfinal inorder is:\n";
    inorder(root);
    return 0;
}


