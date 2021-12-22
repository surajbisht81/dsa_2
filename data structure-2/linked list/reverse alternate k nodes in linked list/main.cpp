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

Node *reverse_alternate(Node *head,int k,bool flag)
{
    if(head==NULL)
        return NULL;

    Node *curr=head;
    Node *prev=NULL,*next;
    int count=1;
    while(curr!=NULL && count<=k)
    {
        next=curr->next;
        if(flag)
         curr->next=prev;

        prev=curr;
        curr=next;
        count++;
    }
    if(flag)
    {
         head->next=reverse_alternate(curr,k,!flag);
         return prev;
    }

    else
    {
        prev->next=reverse_alternate(curr,k,!flag);
        return head;
    }

}
int main()
{
    Node *head=NULL;
    for(int i=9;i>0;i--)
        push(&head,i);
    int k=3;
    bool flag=1;
    printlist(head);

    head=reverse_alternate(head,k,flag);
    printlist(head);
    return 0;
}
