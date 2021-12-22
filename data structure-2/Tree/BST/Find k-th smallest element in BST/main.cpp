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

void Kth_smallestEmt(Node *root, int arr[],int *idx)
{
    if(!root)
        return;

    Kth_smallestEmt(root->left,arr,idx);

    arr[*idx]=root->data;
    (*idx)++;

    Kth_smallestEmt(root->right,arr,idx);
}
int main()
{
   Node *root=newNode(20);
   root->left=newNode(8);
   root->right = newNode(22);
   root->left->left= newNode(4);
   root->left->right= newNode(12);
   root->left->right->left= newNode(10);
   root->left->right->right= newNode(14);

   int k=3;
   int *arr=new int[7];
   int idx=0;
   Kth_smallestEmt(root,arr,&idx);
   cout<<k<<"th smallest element is :"<<arr[k-1];
   return 0;
}


/*
// using morris traversal
#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int key; 
	Node *left, *right; 
}; 

int KSmallestUsingMorris(Node *root, int k) 
{ 
   int k_small;
   Node *curr = root;
   int cnt=0;
   
   while(curr!=NULL)
   {
       if(curr->left==NULL)
       {
          cnt++;
          if(cnt==k)
           k_small = curr->key;
          
          curr = curr->right;
       }
       else
       {
           Node *pre = curr->left;
           while(pre->right!=NULL and pre->right!=curr)
             pre = pre->right;
             
           if(pre->right==NULL)
           {
               pre->right = curr;
               curr=curr->left;
           }
           else
           {
               cnt++;
               if(cnt==k)
                k_small = curr->key;
               
               pre->right = NULL;
               curr= curr->right;
           }
       }
   }
   return k_small;
} 

Node *newNode(int item) 
{ 
	Node *temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

Node* insert(Node* node, int key) 
{ 
	if (node == NULL) return newNode(key); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	return node; 
} 

// Driver Program to test above functions 
int main() 
{ 
	Node *root = NULL; 
	root = insert(root, 50); 
	insert(root, 30); 
	insert(root, 20); 
	insert(root, 40); 
	insert(root, 70); 
	insert(root, 60); 
	insert(root, 80); 

	for (int k=1; k<=7; k++) 
	cout << KSmallestUsingMorris(root, k) << " "; 

	return 0; 
} 
*/