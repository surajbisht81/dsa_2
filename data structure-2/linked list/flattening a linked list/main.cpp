#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right,*down;
};
void push(Node **head_ref,int key)
{
    Node *newnode=new Node;
    newnode->data=key;
    newnode->right=NULL;

    newnode->down=(*head_ref);
    (*head_ref)=newnode;
}
void printlist(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->down;
    }
    cout<<endl;
}
Node *mergelist(Node *first,Node *second)
{
    if(first==NULL)
        return second;
    if(second==NULL)
        return first;

    Node *res;
    if(first->data<=second->data)
    {
        res=first;
        res->down=mergelist(first->down,second);
    }
    else
    {
        res=second;
        res->down= mergelist(first,second->down);
    }
    res->right=NULL;
    return res;
}
Node *flattenin(Node *head)
{
    if(head==NULL or head->right==NULL)
        return head;
    return mergelist(head,flattenin(head->right));
}
int main()
{
    Node *head=NULL;
    push(&head,30);
    push(&head,8);
    push(&head,7);
    push(&head,5);

    push(&(head->right),20);
    push(&(head->right),10);

    push(&(head->right->right),50);
    push(&(head->right->right),22);
    push(&(head->right->right),19);

    push(&(head->right->right->right),45);
    push(&(head->right->right->right),40);
    push(&(head->right->right->right),35);
    push(&(head->right->right->right),28);

    head=flattenin(head);
    printlist(head);
    return 0;
}
