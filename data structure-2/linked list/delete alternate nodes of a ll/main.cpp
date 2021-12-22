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

void delete_alternate(Node *head)
{
    Node *curr,*prev=head;
    curr=prev->next;

    while(curr!=NULL)
    {
        prev->next=curr->next;
        delete curr;
        if(curr->next!=NULL)
        {
            curr=prev->next->next;
            prev=prev->next;
        }
        else
            curr=curr->next;
    }
}
int main()
{
    Node *head=NULL;
    //push(&head,8);
   // push(&head,7);
  //  push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    //push(&head,1);
    printlist(head);

    delete_alternate(head);
    printlist(head);
    return 0;
}
