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
    Node *temp = new Node;
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}
Node *insert(Node *root, int key)
{
    if(root==NULL)
        return newNode(key);
    if(key<root->data)
        root->left=insert(root->left, key);
    else
        root->right=insert(root->right, key);
        return root;
}

void Treeto_vector(int arr[], Node *root, int *index)
{
    if(!root)
        return;
    Treeto_vector(arr, root->left, index);

    arr[*index]=root->data;
    (*index)++;

    Treeto_vector(arr, root->right, index);
}
bool isTripletPresent(Node *root, int n)
{
    int arr[n];
    int index=0;
    Treeto_vector(arr, root, &index);
    for(int i=0;i<n-2;i++)
    {
        int l=i+1;
        int r=n-1;

        while(l<r)
        {
            if(arr[i]+arr[l]+arr[r]==0)
                return true;
            else if( arr[i]+arr[l]+arr[r]<0 )
                l++;
            else
                r--;
        }
    }
    return false;
}
int main()
{
    Node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);

    if(isTripletPresent(root,7))
        cout<<"yes";
    else
        cout<<"No.";
    return 0;
}


/*
// using DLL in O(n^2) time and O(logn) space, O(logn) is for call stack function for logn time;

// A C++ program to check if there 
// is a triplet with sum equal to 0 in 
// a given BST 
#include <bits/stdc++.h> 
using namespace std; 

// A BST node has key, and left and right pointers 
class node 
{ 
	public: 
	int key; 
	node *left; 
	node *right; 
}; 

// A function to convert given BST to Doubly 
// Linked List. left pointer is used 
// as previous pointer and right pointer 
// is used as next pointer. The function 
// sets *head to point to first and *tail 
// to point to last node of converted DLL 
void convertBSTtoDLL(node* root, node** head, node** tail) 
{ 
	// Base case 
	if (root == NULL) 
		return; 

	// First convert the left subtree 
	if (root->left) 
		convertBSTtoDLL(root->left, head, tail); 

	// Then change left of current root 
	// as last node of left subtree 
	root->left = *tail; 

	// If tail is not NULL, then set right 
	// of tail as root, else current 
	// node is head 
	if (*tail) 
		(*tail)->right = root; 
	else
		*head = root; 

	// Update tail 
	*tail = root; 

	// Finally, convert right subtree 
	if (root->right) 
		convertBSTtoDLL(root->right, head, tail); 
} 

// This function returns true if there 
// is pair in DLL with sum equal to given 
// sum. The algorithm is similar to hasArrayTwoCandidates() 
// in method 1 of http://tinyurl.com/dy6palr 
bool isPresentInDLL(node* head, node* tail, int sum) 
{ 
	while (head != tail) 
	{ 
		int curr = head->key + tail->key; 
		if (curr == sum) 
			return true; 
		else if (curr > sum) 
			tail = tail->left; 
		else
			head = head->right; 
	} 
	return false; 
} 

// The main function that returns 
// true if there is a 0 sum triplet in 
// BST otherwise returns false 
bool isTripletPresent(node *root) 
{ 
	// Check if the given BST is empty 
	if (root == NULL) 
	return false; 

	// Convert given BST to doubly linked list. head and tail store the 
	// pointers to first and last nodes in DLLL 
	node* head = NULL; 
	node* tail = NULL; 
	convertBSTtoDLL(root, &head, &tail); 

	// Now iterate through every node and 
	// find if there is a pair with sum 
	// equal to -1 * heaf->key where head is current node 
	while ((head->right != tail) && (head->key < 0)) 
	{ 
		// If there is a pair with sum 
		// equal to -1*head->key, then return 
		// true else move forward 
		if (isPresentInDLL(head->right, tail, -1*head->key)) 
			return true; 
		else
			head = head->right; 
	}  
	return false; 
} 

node* newNode(int num) 
{ 
	node* temp = new node(); 
	temp->key = num; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

node* insert(node* root, int key) 
{ 
	if (root == NULL) 
	return newNode(key); 
	if (root->key > key) 
		root->left = insert(root->left, key); 
	else
		root->right = insert(root->right, key); 
	return root; 
} 
 
int main() 
{ 
	node* root = NULL; 
	root = insert(root, 6); 
	root = insert(root, -13); 
	root = insert(root, 14); 
	root = insert(root, -8); 
	root = insert(root, 15); 
	root = insert(root, 13); 
	root = insert(root, 7); 
	if (isTripletPresent(root)) 
		cout << "Present"; 
	else
		cout << "Not Present"; 
	return 0; 
} 

*/