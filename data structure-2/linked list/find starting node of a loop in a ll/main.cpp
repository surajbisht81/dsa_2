#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *next;
};
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
int startingNode(Node *head)
{
    Node *start_node=head,*finish_node=head;

    while(start_node && finish_node && finish_node->next!=NULL)
    {
        start_node=start_node->next;
        finish_node=finish_node->next->next;
        if(start_node==finish_node)
            break;
    }
    if(start_node!=finish_node)
        return NULL;
    start_node=head;
    while(start_node!=finish_node)
    {
        start_node=start_node->next;
        finish_node=finish_node->next;
    }
    return start_node->key;
}
int main()
{
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    cout<<startingNode(head);
    return 0;
}
