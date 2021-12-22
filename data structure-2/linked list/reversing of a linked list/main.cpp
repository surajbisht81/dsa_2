#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};
Node *head=NULL;
Node *push(int key)
{
    Node *new_node=new Node();
        new_node->data=key;
        new_node->next=NULL;
    return new_node;
}
void printList()
{
    Node *curr=head;
    while(curr!=NULL)
    {
         cout<<curr->data<<" ";
         curr=curr->next;
    }
    cout<<endl;
}
void reverseList()
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
}
int main()
{
    head=push(1);
    head->next=push(2);
    head->next->next=push(3);
    head->next->next->next=push(4);
    head->next->next->next->next=push(5);

    printList();
    reverseList();
    printList();
    return 0;
}
