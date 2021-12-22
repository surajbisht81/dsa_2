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

Node *rotate_list(Node *head,int k)
{
    Node *curr=head, *k_th;
    int count=1;
    while(curr->next!=NULL)
    {
        curr=curr->next;
        count++;
        if(count==k)
            k_th=curr;
    }
    curr->next=head;
    head=k_th->next;
    k_th->next=NULL;
    return head;
}
int main()
{
    Node *head=NULL;
    push(&head,60);
    push(&head,50);
    push(&head,40);
    push(&head,30);
    push(&head,20);
    push(&head,10);

    int k=4;
    printlist(head);

    head=rotate_list(head,k);
    cout<<"\nrotated linked list is:\n";
    printlist(head);
    return 0;
}
