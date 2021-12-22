#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};


int countLength(Node *head)
{
    Node *curr=head;
    int cnt=0;
    while(curr!=NULL)
    {
        cnt++;
        curr=curr->next;
    }
    return cnt;
}
int _getintersection(Node *head1 ,Node *head2,int d)
{
    Node *curr1=head1,*curr2=head2;
    for(int i=0;i<d;i++)
    {
        if(curr1==NULL)
            return -1;
        curr1=curr1->next;
    }
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1==curr2)
            return curr1->data;
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return -1;
}
int getintersection1(Node *head1,Node *head2)
{
    int c1=countLength(head1);
    int c2=countLength(head2);
    int d;
    if(c1>c2)
    {
        d=c1-c2;
        return _getintersection(head1,head2,d);
    }
    else
    {
        d=c2-c1;
        return _getintersection(head2,head1,d);
    }
}






// without using length of linked lists

/*int getintersection2(Node *head1,Node *head2)
{
    Node *curr1=head1,*curr2=head2;

    while(curr1!=NULL && curr2!=NULL)
    {
        curr1=curr1->next;
        curr2=curr2->next;

        if(curr1==NULL)
            curr1=head2;
        if(curr2==NULL)
            curr2=head1;
        if(curr1==curr2)
            return curr1->data;
    }
    return -1;
}*/

int main()
{
     Node* newNode;

    // Addition of new nodes
    Node* head1 = new Node();
    head1->data = 10;

    Node* head2 = new Node();
    head2->data = 3;

    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;

    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;

    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    cout<<"\nintersection point using length= "<<getintersection1(head1,head2);
   // cout<<"\nintersection point without using length= "<<getintersection2(head1,head2);
    return 0;
}
