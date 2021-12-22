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
void specific_levelOrder(Node *root)
{
    if(!root)
        return ;
    cout<<root->data<<" ";

    if(root->left!=NULL)
        cout<<root->left->data<<" "<<root->right->data<<" ";

    if(root->left->left==NULL)
        return;
    queue<Node*>qu;
    Node *first,*second;
    qu.push(root->left);
    qu.push(root->right);
    while(!qu.empty())
    {
        first=qu.front();
        qu.pop();
        second=qu.front();
        qu.pop();

        cout<<first->left->data<<" "<<second->right->data<<" ";
        cout<<first->right->data<<" "<<second->left->data<<" ";
        if(first->left->left)
        {
            qu.push(first->left);
            qu.push(second->right);
            qu.push(first->right);
            qu.push(second->left);
        }
    }
}
int main()
{
    Node *root = newNode(1);

    root->left        = newNode(2);
    root->right       = newNode(3);

    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    root->right->right->right  = newNode(15);

    root->left->left->left->left  = newNode(16);
    root->left->left->left->right  = newNode(17);
    root->left->left->right->left  = newNode(18);
    root->left->left->right->right  = newNode(19);
    root->left->right->left->left  = newNode(20);
    root->left->right->left->right  = newNode(21);
    root->left->right->right->left  = newNode(22);
    root->left->right->right->right  = newNode(23);
    root->right->left->left->left  = newNode(24);
    root->right->left->left->right  = newNode(25);
    root->right->left->right->left  = newNode(26);
    root->right->left->right->right  = newNode(27);
    root->right->right->left->left  = newNode(28);
    root->right->right->left->right  = newNode(29);
    root->right->right->right->left  = newNode(30);
    root->right->right->right->right  = newNode(31);

    cout<<"\nspecific level order traversal of tree is:\n";
    specific_levelOrder(root);
    return 0;
}

/*  using vector 

/* C++ program for special order traversal */
#include <iostream> 
#include <queue> 
using namespace std; 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int data; 
	Node *left; 
	Node *right; 
}; 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
Node *newNode(int data) 
{ 
	Node *node = new Node; 
	node->data = data; 
	node->right = node->left = NULL; 
	return node; 
} 

/* Given a perfect binary tree, print its nodes in specific 
level order */
void printSpecificLevelOrder(Node *root) 
{
  if(!root)
     return;
  
  queue<Node*> qu;
  qu.push(root);
  qu.push(NULL);
  
  Node *first;
  vector<int> v;
  cout<<root->data<<" ";
  
  while(!qu.empty())
  {
     first = qu.front();
     qu.pop();
     
     if(first==NULL)
      {
         int i=0, j=v.size()-1;
         while( i<=j and v.size()>1)
         {
           cout<<v[i]<<" ";
           cout<<v[j]<<" ";
                 i++, j--;
         }
         v.clear();
          if(qu.empty())
           break;
         qu.push(NULL);
         continue;
      }
     else
       {
         v.push_back(first->data);
       }
     if(first->left)
         qu.push(first->left);
     if(first->right)
         qu.push(first->right);
  }
} 

/* Driver program to test above functions*/
int main() 
{ 
	//Perfect Binary Tree of Height 4 
	Node *root = newNode(1); 

	root->left	 = newNode(2); 
	root->right	 = newNode(3); 

	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 

	root->left->left->left = newNode(8); 
	root->left->left->right = newNode(9); 
	root->left->right->left = newNode(10); 
	root->left->right->right = newNode(11); 
	root->right->left->left = newNode(12); 
	root->right->left->right = newNode(13); 
	root->right->right->left = newNode(14); 
	root->right->right->right = newNode(15); 

	root->left->left->left->left = newNode(16); 
	root->left->left->left->right = newNode(17); 
	root->left->left->right->left = newNode(18); 
	root->left->left->right->right = newNode(19); 
	root->left->right->left->left = newNode(20); 
	root->left->right->left->right = newNode(21); 
	root->left->right->right->left = newNode(22); 
	root->left->right->right->right = newNode(23); 
	root->right->left->left->left = newNode(24); 
	root->right->left->left->right = newNode(25); 
	root->right->left->right->left = newNode(26); 
	root->right->left->right->right = newNode(27); 
	root->right->right->left->left = newNode(28); 
	root->right->right->left->right = newNode(29); 
	root->right->right->right->left = newNode(30); 
	root->right->right->right->right = newNode(31); 

	cout << "Specific Level Order traversal of binary tree is \n"; 
	printSpecificLevelOrder(root); 

	return 0; 
}
*/