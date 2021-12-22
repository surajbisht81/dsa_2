#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next, *random;
};

Node *getnode(int data)
{
    Node *newnode = new Node;
    newnode->data=data;
    newnode->next=newnode->random=NULL;
    return newnode;
}

void printlist(Node *curr)
{
    while(curr)
    {
        cout<<"Data-> "<<curr->data<<", "<<"Random-> "<<curr->random->data<<endl;
        curr=curr->next;
    }
}

Node *clone(Node *start)
{
    Node *curr = start, *temp;

    while(curr)
    {
        temp=curr->next;

        curr->next = getnode(curr->data);

        curr->next->next=temp;
        curr=temp;
    }

    curr=start;

    while(curr)
    {
        if(curr->next)
            curr->next->random = curr->random ? curr->random->next : curr->random;

        curr = curr->next ? curr->next->next : curr->next;
    }

    Node *original= start, *dup=start->next;
    temp = dup;

    while(original and dup)
    {
        original->next = original->next ? original->next->next : original->next;

        dup->next = dup->next ? dup->next->next : dup->next;

        original = original->next;
        dup=dup->next;
    }
    return temp;
}
int main()
{
    Node *start = NULL;
    start = getnode(1);
    start->next = getnode(2);
    start->next->next = getnode(3);
    start->next->next->next = getnode(4);
    start->next->next->next->next = getnode(5);

     // 1's random points to 3
    start->random = start->next->next;

    // 2's random points to 1
    start->next->random = start;

    // 3's and 4's random points to 5
    start->next->next->random =
                    start->next->next->next->next;
    start->next->next->next->random =
                    start->next->next->next->next;

    // 5's random points to 2
    start->next->next->next->next->random =
                                      start->next;

    cout<<"\noriginal list: \n";
    printlist(start);

    Node *newStart = clone(start);

    cout<<"\nnew linked list: \n";
    printlist(newStart);
    return 0;
}
