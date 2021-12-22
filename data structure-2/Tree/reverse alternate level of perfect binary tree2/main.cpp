#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *left,*right;
};

Node *newNode(int key)
{
    Node *new_node=new Node;
    new_node->data=key;
    new_node->left=new_node->right=NULL;
    return new_node;
}

//using one traversal

void reverse_alternateNode(Node *root1,Node *root2,int l)
{
    if(root1==NULL && root2==NULL)
        return;
    if(l%2==0)
        swap(root1->data,root2->data);
    reverse_alternateNode(root1->left,root2->right,l+1);
    reverse_alternateNode(root1->right,root2->left,l+1);
}
void inorder(Node *root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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

    reverse_alternateNode(root->left,root->right,0);

    cout<<"\nfinal inorder is:\n";
    inorder(root);
    return 0;
}


/*
  using stack
// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// A tree node 
struct Node { 
	char key; 
	struct Node *left, *right; 
}; 

// Utility function to create new Node 
Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return (temp); 
} 

// Utility function to perform 
// inorder traversal of the tree 
void inorder(Node* root) 
{ 
	if (root != NULL) { 
		inorder(root->left); 
		cout << root->key << " "; 
		inorder(root->right); 
	} 
} 

// Function to reverse alternate nodes 
void reverseAlternate(Node* root) 
{ 

	// Queue for depth first traversal 
	queue<Node*> q; 
	q.push(root); 
	Node* temp; 

	// Level of root considered to be 1 
	int n, level = 1; 

	// Stack to store nodes of a level 
	stack<int> s; 

	while (!q.empty()) { 
		n = q.size(); 
		while (n--) { 
			temp = q.front(); 
			q.pop(); 

			// If level is odd 
			if (level % 2) { 

				// Store the left and right child 
				// in the stack 
				if (temp->left) { 
					q.push(temp->left); 
					s.push(temp->left->key); 
				} 

				if (temp->right) { 
					q.push(temp->right); 
					s.push(temp->right->key); 
				} 
			} 

			// If level is even 
			else { 

				// Replace the value of node 
				// with top of the stack 
				temp->key = s.top(); 
				s.pop(); 

				if (temp->left) 
					q.push(temp->left); 
				if (temp->right) 
					q.push(temp->right); 
			} 
		} 

		// Increment the level 
		level++; 
	} 
} 

// Driver code 
int main() 
{ 
	struct Node* root = newNode('a'); 
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

	cout << "Inorder Traversal of given tree\n"; 
	inorder(root); 

	reverseAlternate(root); 

	cout << "\nInorder Traversal of modified tree\n"; 
	inorder(root); 

	return 0; 
} 
*/