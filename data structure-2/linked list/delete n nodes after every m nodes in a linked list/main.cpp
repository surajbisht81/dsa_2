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

void delete_m_nodes(Node *head,int m,int n)
{
    Node *curr=head,*temp=head;

    while(curr!=NULL)
    {
        int mm=1,nn=1;
        while(mm<=m && curr!=NULL)
        {
            temp=curr;
             curr=curr->next;
             mm++;
        } 
         if(curr==NULL)
          return;
        while(nn<=n && curr!=NULL)
        {
            Node *temp = curr;
            curr=curr->next;
            free(temp);                // we have to free the memory its is necessary.
            nn++;
        }
        temp->next=curr;
    }
}
int main()
{
    Node *head=NULL;
    push(&head,80);
    push(&head,70);
    push(&head,60);
    push(&head,50);
    push(&head,40);
    push(&head,30);
    push(&head,20);
    push(&head,10);

    int m=0,n=3;
    printlist(head);

    delete_m_nodes(head,m,n);
    cout<<"\nupdated linked list is:\n";
    printlist(head);
    return 0;
}
