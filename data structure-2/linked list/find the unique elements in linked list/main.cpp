/*Given a linked list. We need to find unique elements in the linked list i.e, those elements which are not repeated in the linked list or those elements whose
 frequency is 1. If No such elements are present in list so Print ” No Unique Elements”.*/
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

void uniqueElement(Node *head)
{
    unordered_map<int,int> mp;
    Node *curr=head;
    while(curr!=NULL)
    {
        mp[curr->data]++;
        curr=curr->next;
    }
    bool flag=1;
    while(head!=NULL)
    {
        if(mp[head->data]==1)
        {
            cout<<head->data<<" ";
            flag=0;
        }
        head=head->next;
    }
    if(flag==1)
        cout<<"no unique element.";
}
int main()
{
    Node *head=NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 5);
    push(&head, 3);
    push(&head, 2);
    push(&head, 4);
    push(&head, 4);
    push(&head, 1);

    uniqueElement(head);
    return 0;
}
