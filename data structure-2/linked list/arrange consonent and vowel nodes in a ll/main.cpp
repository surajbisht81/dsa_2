/*Given a singly linked list, we need to arrange the consonants and vowel nodes of it in such a way that all the vowels nodes come before the consonants while
 maintaining the order of their arrival.*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};
void push(Node **head_ref,char key)
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

Node *reverse_list(Node *head)
{
    Node *curr=head;
    Node *prev=NULL,*next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
    }
    return prev;
}
Node *arrange_consoVowel(Node *head)
{
   stack<Node*>consonent;
   stack<Node*>vowel;

   Node *curr=head;
   while(curr!=NULL)
   {
       if(curr->data=='a' or curr->data=='e' or curr->data=='i' or curr->data=='o' or curr->data=='u')
        vowel.push(curr);
       else
        consonent.push(curr);
       curr=curr->next;
   }

   Node *temp1=vowel.top();
   while(!vowel.empty())
   {
       Node* node=vowel.top();
       vowel.pop();

       if(!vowel.empty())
        node->next=vowel.top();
       else
        node->next=NULL;
   }
   temp1=reverse_list(temp1);
   head=temp1;

   Node *temp2=consonent.top();
   while(!consonent.empty())
   {
       Node *node=consonent.top();
       consonent.pop();

       if(!consonent.empty())
        node->next=consonent.top();
        else
            node->next=NULL;
   }
   temp2=reverse_list(temp2);

   while(temp1->next!=NULL)
   {
       temp1=temp1->next;
   }
   temp1->next=temp2;
   while(temp2->next!=NULL)
   {
       temp2=temp2->next;
   }
   temp2->next=NULL;

   return head;
}
int main()
{
    Node *head=NULL;
    push(&head,'i');
    push(&head,'x');
    push(&head,'o');
    push(&head,'d');
    push(&head,'e');
    push(&head,'c');
    push(&head,'b');
    push(&head,'a');
    printlist(head);

    head=arrange_consoVowel(head);
    printlist(head);
    return 0;
}
