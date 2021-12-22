#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
void push(Node **head_ref,int key)
{
    Node *newnode=new Node;
    newnode->data=key;
    newnode->next=*head_ref;

    *head_ref=newnode;
}
void printlist(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void exchange_evenOdd(Node *head)
{
    Node *curr=head;
    stack<Node*>odd;
    stack<Node*>even;
    int i=1;
    while(curr!=NULL)
    {
        if(curr->data%2==0 && i%2!=0)
        {
            even.push(curr);
        }
        else if(curr->data%2!=0 && i%2==0)
        {
            odd.push(curr);
        }
        curr=curr->next;
        i++;
    }
    while(!odd.empty() && !even.empty())
    {
        swap(odd.top()->data,even.top()->data);
        odd.pop(),even.pop();
    }
}
int main()
{
    Node *head=NULL;
    push(&head,8);
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    push(&head,10);
    printlist(head);

    exchange_evenOdd(head);
    printlist(head);
    return 0;
}


/*
//without using extra space
// Cpp program to rearrange nodes 
// as alternate odd even nodes in 
// a Singly Linked List 
#include <bits/stdc++.h> 
using namespace std; 

// Structure node 
struct Node { 
	int data; 
	struct Node* next; 
}; 

// A utility function to print 
// linked list 
void printList(struct Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data << " "; 
		node = node->next; 
	} 
	cout << endl; 
} 

// Function to create newNode 
// in a linkedlist 
Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->data = key; 
	temp->next = NULL; 
	return temp; 
} 

// Function to insert at beginning 
Node* insertBeg(Node* head, int val) 
{ 
	Node* temp = newNode(val); 
	temp->next = head; 
	head = temp; 
	return head; 
} 

// Function to rearrange the 
// odd and even nodes 
void rearrange(Node** head) 
{ 
	// Step 1: Segregate even and odd nodes 
	// Step 2: Split odd and even lists 
	// Step 3: Merge even list into odd list 
	Node* even; 
	Node *temp, *prev_temp; 
	Node *i, *j, *k, *l, *ptr; 

	// Step 1: Segregate Odd and Even Nodes 
	temp = (*head)->next; 
	prev_temp = *head; 

	while (temp != nullptr) { 

		// Backup next pointer of temp 
		Node* x = temp->next; 

		// If temp is odd move the node 
		// to beginning of list 
		if (temp->data % 2 != 0) { 
			prev_temp->next = x; 
			temp->next = (*head); 
			(*head) = temp; 
		} 
		else { 
			prev_temp = temp; 
		} 

		// Advance Temp Pointer 
		temp = x; 
	} 

	// Step 2 
	// Split the List into Odd and even 
	temp = (*head)->next; 
	prev_temp = (*head); 

	while (temp != nullptr && temp->data % 2 != 0) { 
		prev_temp = temp; 
		temp = temp->next; 
	} 

	even = temp; 

	// End the odd List (Make last node null) 
	prev_temp->next = nullptr; 

	// Step 3: 
	// Merge Even List into odd 
	i = *head; 
	j = even; 

	while (j != nullptr && i != nullptr) { 

		// While both lists are not 
		// exhausted Backup next 
		// pointers of i and j 
		k = i->next; 
		l = j->next; 

		i->next = j; 
		j->next = k; 

		// ptr points to the latest node added 
		ptr = j; 

		// Advance i and j pointers 
		i = k; 
		j = l; 
	} 

	if (i == nullptr) { 

		// Odd list exhausts before even, 
		// append remainder of even list to odd. 
		ptr->next = j; 
	} 

	// The case where even list exhausts before 
	// odd list is automatically handled since we 
	// merge the even list into the odd list 
} 

// Driver Code 
int main() 
{ 
	Node* head = newNode(8); 
	head = insertBeg(head, 7); 
	head = insertBeg(head, 6); 
	head = insertBeg(head, 3); 
	head = insertBeg(head, 5); 
	head = insertBeg(head, 1); 
	head = insertBeg(head, 2); 
	head = insertBeg(head, 10); 

	cout << "Linked List:" << endl; 
	printList(head); 
	cout << "Rearranged List" << endl; 
	rearrange(&head); 
	printList(head); 
} 
*/