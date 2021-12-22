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
    newnode->next=(*head_ref);

    (*head_ref)=newnode;
}
void middlenode(Node *head,Node **a,Node **b)
{
    Node *fast=head->next;
    Node *slow=head;
    while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

    *a=head;
    *b=slow->next;
    slow->next=NULL;
}
Node *mergelist(Node *first,Node *second)
{
    if(first==NULL)
        return second;
    if(second==NULL)
        return first;
        Node *res=NULL;

    if(first->data<=second->data)
    {
        res=first;
        res->next=mergelist(first->next,second);
    }
    else
    {
        res=second;
        res->next=mergelist(first,second->next);
    }
    return res;
    /*Node *head,*temp;
    if(first->data<=second->data)
       {
         temp=first;
         first=temp->next;
       }
    else
    {
       temp=second;
       second=temp->next;
    }
    head=temp;
    while(first!=NULL && second!=NULL)
    {
        if(first->data<=second->data)
        {
            temp->next=first;
            temp=first;
            first=temp->next;
        }
        else
        {
            temp->next=second;
            temp=second;
            second=temp->next;
        }
    }
    if(first==NULL)
        temp->next=second;
    if(second==NULL)
        temp->next=first;
    return head;*/
}
void mergesort(Node **head)
{
    Node *curr=*head;
    Node *a=NULL;
    Node *b=NULL;
    if(curr==NULL or curr->next==NULL)
        return;

    middlenode(curr,&a,&b);
    mergesort(&a);
    mergesort(&b);

    *head=mergelist(a,b);
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
int main()
{
    Node *head=NULL;
    push(&head,13);
    push(&head,17);
    push(&head,10);
    push(&head,6);
    push(&head,7);
    push(&head,1);
    push(&head,4);

    printlist(head);
    mergesort(&head);
    printlist(head);
    return 0;
}
