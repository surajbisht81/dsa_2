#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *ptr;
    Node(int d)
    {
        data=d;
    }
};
bool ispalindrome(Node *head)
{
    stack<int>s;
    Node *curr=head;
    while(curr!=NULL)
    {
        s.push(curr->data);
        curr=curr->ptr;
    }
    while(head!=NULL)
    {
        int temp=s.top();
        s.pop();
        if(temp==head->data)
            head=head->ptr;
        else
            return false;
    }
    return true;
}
int main()
{
    Node one =  Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(2);
    Node five = Node(1);
    // Initialize the next pointer
    // of every current pointer
    five.ptr = NULL;
    one.ptr = &two;
    two.ptr = &three;
    three.ptr = &four;
    four.ptr = &five;
    Node* temp = &one;

    if(ispalindrome(&one))
        cout<<"\nis palindrome.";
    else
        cout<<"\nnot palindrome.";
    return 0;
}
