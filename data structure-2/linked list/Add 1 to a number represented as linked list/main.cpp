#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
void print_list(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void push(Node **head_ref,int key)
{
    Node *new_node=new Node;
    new_node->data=key;
    new_node->next=*head_ref;

    *head_ref=new_node;
}

Node *reverse_list(Node *head)
{
     Node *prev=NULL,*curr=head,*next=NULL;

    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}

Node *Add_one(Node *head)
{
    Node *curr=head;

    Node *temp;
    int carry=1,sum;
    while(curr!=NULL)
    {
         sum=carry+curr->data;
         carry=(sum>=10)?1:0;
         sum=sum%10;
         curr->data=sum;

         temp=curr;
         curr=curr->next;
    }
    if(carry>0)
    {
        Node *newnode=new Node;
        newnode->data=carry;
        newnode->next=NULL;
        temp->next=newnode;
    }
    return head;
}
int main()
{
    Node *head=NULL;
    push(&head,9);
    push(&head,9);
    push(&head,9);
    push(&head,1);

    cout<<"\ninitial list is: ";
    print_list(head);
    head=reverse_list(head);
    head=Add_one(head);
    head=reverse_list(head);

    print_list(head);
    return 0;
}
