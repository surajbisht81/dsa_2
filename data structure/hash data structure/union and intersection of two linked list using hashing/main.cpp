#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

void push(Node **head_ref, int key)
{
    Node *newnode = new Node;
    newnode->data=key;
    newnode->next=(*head_ref);

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

void fillHash(Node *head1, Node *head2, unordered_map<int, int> &mp)
{
    while(head1!=NULL or head2!=NULL)
    {
        if(head1!=NULL)
        {
            mp[head1->data]++;
            head1=head1->next;
        }

        if(head2!=NULL)
        {
            mp[head2->data]++;
            head2=head2->next;
        }
    }
}

Node *intersection(unordered_map<int, int> &mp)
{
    Node *result =NULL;
    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second==2)
            push(&result, it->first);
    }
    return result;
}

Node *Union(unordered_map<int, int> &mp)
{
    Node *result =NULL;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        push(&result, it->first);
    }
    return result;
}
int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;

    /* create a linked list 11->10->15->4->20 */
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);
    push(&head1, 4);
    push(&head1, 5);

    /* create a linked list 8->4->2->10 */
    push(&head2, 1);
    push(&head2, 3);
    push(&head2, 5);
    push(&head2, 6);

    cout<<"\nfirst linked list is:\n";
    printlist(head1);

    cout<<"\nsecond linked list is:\n";
    printlist(head2);

    unordered_map<int, int> mp;
    fillHash(head1, head2, mp);

    Node *intersection_node = intersection( mp);
    Node *union_node = Union(mp);
    cout<<"\nintersection and union lists are :\n";

    printlist(intersection_node);
    cout<<endl;
    printlist(union_node);
    return 0;
}
