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
Node* reverselist(Node *head,int k)
{
    Node *curr=head,*prev=NULL,*next=NULL;
    int count=0;
    while(curr!=NULL && count<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
        head->next=reverselist(next,k);
    return prev;
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
    int k=3;
    Node *head=NULL;
    push(&head,9);
    push(&head,8);
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    cout<<"\ncurrent list is:\n";
    printlist(head);

    head=reverselist(head,k);

    cout<<"\nnew list is:\n";
    printlist(head);
}
