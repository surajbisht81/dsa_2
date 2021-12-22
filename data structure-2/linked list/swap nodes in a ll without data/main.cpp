#include<bits/stdc++.h>
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

void swap_node(Node **head,int key1,int key2)
{
    if(key1==key2)
        return;

    Node *dummy;

    Node *curr1=*head,*prev1=NULL;
    while(curr1!=NULL && curr1->data!=key1)
    {
        prev1=curr1;
        curr1=prev1->next;
    }
    Node *curr2=*head,*prev2=NULL;
    while(curr2!=NULL && curr2->data!=key2)
    {
        prev2=curr2;
        curr2=prev2->next;
    }

    if(curr1==NULL && curr2==NULL)
        return ;

    if(prev1==NULL)
        *head=curr2;
    else
     prev1->next=curr2;


     if(prev2==NULL)
        *head=curr1;
     else
        prev2->next=curr1;

     dummy=curr1->next;
     curr1->next=curr2->next;
     curr2->next=dummy;
}
int main()
{
    Node *head=NULL;
    push(&head,70);
    push(&head,60);
    push(&head,50);
    push(&head,40);
    push(&head,30);
    push(&head,20);
    push(&head,10);
    printlist(head);

    swap_node(&head,10,70);
    cout<<"\n\nafter swapping:\n\n";
    printlist(head);
    return 0;

}
