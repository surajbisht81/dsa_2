#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};
int getintersection(Node *head1,Node *head2)
{
    unordered_set<Node*>s;
    while(head1!=NULL)
     {
       s.insert(head1);
       head1=head1->next;
     }
     while(head2!=NULL)
     {
         if(s.find(head2)!=s.end())
            return head2->data;
         head2=head2->next;
     }
     return -1;
}
int main()
{
    //3->6->9->15->30
    //10->15->30
    Node *newnode;

    Node *head1=new Node();
    head1->data=3;

    Node *head2=new Node();
    head2->data=10;

    newnode=new Node();
    newnode->data=6;
    head1->next=newnode;

    newnode=new Node();
    newnode->data=9;
    head1->next->next=newnode;

    newnode=new Node();
    newnode->data=15;
    head1->next->next->next=newnode;
    head2->next=newnode;

    newnode=new Node();
    newnode->data=30;
    head1->next->next->next->next=newnode;
    head2->next->next=newnode;

    head1->next->next->next->next->next=NULL;
    head2->next->next->next=NULL;
    cout<<"\nmerge point of linked list is="<<getintersection(head1,head2);
    return 0;
}
