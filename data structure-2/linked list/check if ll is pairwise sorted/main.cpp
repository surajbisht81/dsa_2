#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

bool isPairwise_sorted(Node *head)
{
    Node *curr=head;

    bool flag=true;
    while(curr!=NULL && curr->next!=NULL)
    {
        if(curr->data>curr->next->data)
        {
            flag=false;
            return false;
        }
        curr=curr->next->next;
    }
    return flag;
}
void push(Node **head_ref,int key)
{
    Node *newnode=new Node;
    newnode->data=key;
    newnode->next=*head_ref;

    *head_ref=newnode;
}
void printlist(Node *head)
{
    cout<<"\nnew list is:\n";
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
void sortPairwise(Node *head)
{
    Node *curr=head,*next,*prev=head;

    if(head->data>head->next->data)
        head=head->next;

    while(curr!=NULL && curr->next!=NULL)
    {
         next=curr->next;
        if(curr->data>next->data)
        {
            prev->next=next;
            curr->next=next->next;
            next->next=curr;

            prev=curr;
            curr=curr->next;
        }
        else
        {
            prev=curr->next;
            curr=curr->next->next;
        }
    }
    printlist(head);
}
int main()
{
   Node *head=NULL;
   push(&head,5);
   push(&head,1);
   push(&head,8);
   push(&head,9);
   push(&head,10);
   push(&head,15);
   if(isPairwise_sorted(head))
        cout<<"yes"<<endl;
   else
    {
       sortPairwise(head);
    }
   return 0;
}
