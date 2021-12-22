/*Given a binary tree and a node, we need to write a program to find inorder successor of this node.

Inorder Successor of a node in binary tree is the next node in Inorder traversal of the Binary Tree. Inorder Successor is NULL for the last node in Inoorder traversal.*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left,*right;
};
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *leftmost_node(Node *x)
{
    while(x!=NULL && x->left!=NULL)
        x=x->left;
    return x;
}
Node *rightmost_node(Node *x)
{
    while(x!=NULL && x->right!=NULL)
     x=x->right;
     return x;
}
Node *temp=new Node;
Node *findInorderRecursive(Node *root,Node *x)
{
    if(!root)
        return NULL;
    if(root->data==x->data or (temp=findInorderRecursive(root->left,x)) or (temp=findInorderRecursive(root->right,x)) )
    {
        if(temp)
        {
            if(root->left==temp)
              {
                cout<<"\ninorder successor of "<<x->data<<" is"<< root->data;
                return NULL;

              }
        }
        return root;
    }
    return NULL;
}
void inorder_successor(Node *root,Node *x)
{
    if(x->right!=NULL)
    {
      Node *leftmost=leftmost_node(x->right);
      cout<<"\ninorder successor of "<<x->data<<" is"<< leftmost->data;
    }

    if(x->right==NULL)
    {
        Node *rightmost=rightmost_node(root);
        if(rightmost==x)
            cout<<"\nno inorder successor found! rightmost node.";
        else
            findInorderRecursive(root,x);
    }
}
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    inorder_successor(root,root->right);
    inorder_successor(root,root->left->left);
    inorder_successor(root,root->right->right);
    return 0;
}


/*// C++ Program to find inorder successor. 
#include<bits/stdc++.h> 
using namespace std; 

// structure of a Binary Node. 
struct Node 
{ 
	int data; 
	Node* left; 
	Node* right; 
}; 

// Function to create a new Node. 
Node* newNode(int val) 
{ 
	Node* temp = new Node; 
	temp->data = val; 
	temp->left = NULL; 
	temp->right = NULL; 
	
	return temp; 
} 

// function that prints the inorder successor 
// of a target node. next will point the last 
// tracked node, which will be the answer. 
void inorderSuccessor(Node* root, 
					Node* target_node, 
					Node* &next) 
{ 
	// if root is null then return 
	if(!root) 
		return; 

	inorderSuccessor(root->right, target_node, next); 
	
	// if target node found then enter this condition 
	if(root->data == target_node->data) 
	{ 
		// this will be true to the last node 
		// in inorder traversal i.e., rightmost node. 
		if(next == NULL) 
			cout << "inorder successor of "
				<< root->data << " is: null\n"; 
		else
			cout << "inorder successor of "
				<< root->data << " is: "
				<< next->data << "\n"; 
	} 
	next = root; 
	inorderSuccessor(root->left, target_node, next); 
} 

// Driver Code 
int main() 
{ 
	
	// Let's construct the binary tree 
	// as shown in above diagram. 
	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->right = newNode(6); 
	
	// Case 1 
	Node* next = NULL; 
	inorderSuccessor(root, root->right, next); 

	// case 2 
	next = NULL; 
	inorderSuccessor(root, root->left->left, next); 

	// case 3 
	next = NULL; 
	inorderSuccessor(root, root->right->right, next); 
	
	return 0; 
} 
*/
