#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

int findloop(Node *head)
{
    Node *curr=head,*prev=head;
    map<Node*,int>mp;

    int pos=0;
    while(curr!=NULL)
    {
        if(mp.find(curr)==mp.end())
        {
            mp[curr]=pos;
            pos++;
        }
        else
        {
           return (mp[prev]-mp[curr]);
        }
        prev=curr;
        curr=curr->next;
    }
    return -1;
}
void removeloop(Node *head)
{
     Node *curr=head,*prev=head;
    map<Node*,int>mp;

    int pos=0;
    while(curr!=NULL)
    {
        if(mp.find(curr)==mp.end())
        {
            mp[curr]=pos;
            pos++;
        }
        else
        {
           prev->next=NULL;
           return;
        }
        prev=curr;
        curr=curr->next;
    }
}
void printloop(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    Node *newnode;

    Node *head=new Node;
    head->data=1;

    newnode=new Node;
    newnode->data=2;
    head->next=newnode;

    newnode=new Node;
    newnode->data=3;
    head->next->next=newnode;

    newnode=new Node;
    newnode->data=4;
    head->next->next->next=newnode;

    newnode=new Node;
    newnode->data=5;
    head->next->next->next->next=newnode;

    head->next->next->next->next->next=head->next;
    cout<<findloop(head)+1<<endl;

    removeloop(head);
    printloop(head);
    return 0;
}
