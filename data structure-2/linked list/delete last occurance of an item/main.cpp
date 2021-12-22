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

Node *delete_last(Node *head,int key)
{
    Node *curr=head;
    Node *prev;
    int count=0;
    while(curr!=nullptr)
    {
        if(curr->data==key)
            count++;
        curr=curr->next;
    }

    curr=head;
    while(curr!=NULL && count>0)
    {
        if(count==1 && curr->data==key)
        {
            prev->next=curr->next;
            break;
        }
        if(curr->data==key)
            count--;
        prev=curr;
        curr=curr->next;
    }
    return head;
}
int main()
{
    Node *head=NULL;
    //push(&head,1);
    push(&head,10);
    push(&head,2);
    push(&head,5);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    printlist(head);

    head=delete_last(head,2);
    printlist(head);
    return 0;
}
