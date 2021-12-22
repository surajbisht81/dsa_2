#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};
void push(Node **headd_ref,int key)
{
    Node *newnode=new Node;
    newnode->data=key;
    newnode->next=*headd_ref;

    *headd_ref=newnode;
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
Node *delete_element(Node *head)
{
    unordered_map<int,Node*>mp;
    int psum=0;
    Node *node=head,*start=NULL;
    mp[0]=NULL;

    while(node!=NULL)
    {
        psum+=node->data;
        if(mp.find(psum)==mp.end())
        {
            mp[psum]=node;
            node=node->next;
        }
        else
        {
            start=mp[psum];
            start?start->next=node->next:head=node->next;

            mp={};
            mp[0]=NULL;
            psum=0,node=head;
        }
    }
    return head;
}
int main()
{
    Node *head=NULL;
    push(&head,1);
    push(&head,3);
    push(&head,-3);
    push(&head,-2);
    push(&head,2);

    head=delete_element(head);
    printlist(head);
    return 0;
}
