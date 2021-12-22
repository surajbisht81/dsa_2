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
}

void remove_duplicates(Node *head)
{
   unordered_set<int>s;

   Node *curr=head,*prev;
   while(curr!=NULL)
   {
       if(s.find(curr->data)!=s.end())
       {
           prev->next=curr->next;
           delete curr;
       }
       else
       {
           s.insert(curr->data);
           prev=curr;
       }
        curr=prev->next;
   }
}
int main()
{
   Node *head=NULL;
   push(&head,10);
   push(&head,11);
   push(&head,12);
   push(&head,11);
   push(&head,11);
   push(&head,12);
   push(&head,10);

   printlist(head);

   cout<<"\n\nafter removing duplicates:\n\n";
   remove_duplicates(head);
   printlist(head);
   return 0;
}
