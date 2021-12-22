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

void merge_lists(Node *head1,Node **head2)
{
    Node *curr1=head1,*curr2=*head2;
    Node *next1,*next2;
    while(curr1!=NULL)
    {
        next1=curr1->next;
        next2=curr2->next;

        curr1->next=curr2;
        curr2->next=next1;

        curr1=next1;
        curr2=next2;
    }
    *head2=curr2;
}
int main()
{
 Node *p = NULL, *q = NULL;
    push(&p, 3);
    push(&p, 2);
    push(&p, 1);
    cout<<"First Linked List:\n";
    printlist(p);

    push(&q, 8);
    push(&q, 7);
    push(&q, 6);
    push(&q, 5);
    push(&q, 4);
    cout<<"Second Linked List:\n";
    printlist(q);

    merge_lists(p,&q);

    cout<<"Modified First Linked List:\n";
    printlist(p);

    cout<<"Modified Second Linked List:\n";
    printlist(q);

    return 0;
}
