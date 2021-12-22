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
    Node *new_node=new Node;
    new_node->data=key;
    new_node->left=new_node->right=NULL;
    return new_node;
}
int nodesAnd_Size(Node *root,int *Size)
{
    if(root==NULL)
        return 0;

    int left=nodesAnd_Size(root->left,Size);
    int right=nodesAnd_Size(root->right,Size);

    (*Size)++;
    return max(left,right)+1;
}
int main()
{
    Node *root=newNode(10);
      root->left=newNode(20);
      root->right=newNode(30);

    int Size=0;
    int height=nodesAnd_Size(root,&Size);
    float res=(float)Size/(float)height;
    cout<<res;
    return 0;
}


//using lavel order traversal

/*
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
    Node *new_node = new Node;
    new_node->data=key;
    new_node->left=new_node->right=NULL;
    return new_node;
}

float Density(Node *root)
{
    queue<Node*> qu;
    qu.push(root);
    qu.push(NULL);
    
    int size=0, height=1;
    while(!qu.empty())
    {
        Node *t = qu.front();
        qu.pop();
        
        if(t)
         size++;
        else
        {
            if(qu.empty())
             break;
            
            qu.push(NULL);
            height++;
            continue;
        }
        
        if(t->left)
         qu.push(t->left);
        
        if(t->right)
         qu.push(t->right);
    }
    
    return  (float)size/(float)height;
}

int main() 
{
    
    Node *root=newNode(10);
    root->left=newNode(20);
    root->right=newNode(30);
     
    cout<<Density(root);
    return 0;
}
*/