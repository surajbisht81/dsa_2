#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *newnode(int key)
{
   Node *new_node=new Node;
   new_node->data=key;
   new_node->next=NULL;
   return new_node;
}
void printlist(Node *head)
{
    if(head==NULL)
        cout<<"no";
    Node *curr=head;
    do
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }while(curr!=head);
    cout<<endl;
}
bool isevenparity(int data)
{
    int cnt=0;
    while(data>0)
    {
        data=data & (data-1);
        cnt++;
    }
    if(cnt%2==0)
        return true;
    else
        return false;
}
Node *remove_evenParitynodes(Node *head)
{
    Node *curr=head;
    Node *prev,*temp=head;
    while(temp->next!=head)
        temp=temp->next;

    while(isevenparity(curr->data))
    {
         curr=curr->next;
         temp->next=curr;
         head=curr;

    }
    prev=curr;
    while(curr->next!=head)
    {
        if(isevenparity(curr->data))
        {
            prev->next=curr->next;
            curr=prev->next;
        }
        else
        {
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}
int main()
{
      //9 -> 11 -> 34 -> 6 -> 13 -> 21
      Node *head=newnode(9);
      head->next=newnode(34);
      head->next->next=newnode(6);
      head->next->next->next=newnode(9);
      head->next->next->next->next=newnode(14);
      head->next->next->next->next->next=newnode(34);
      head->next->next->next->next->next->next=head;


      printlist(head);
      head=remove_evenParitynodes(head);
      printlist(head);
      return 0;
}
