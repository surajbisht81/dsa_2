#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
}*head;

void createlist(int n)
{
    Node *new_node,*temp;
    head=new Node();
    if(head==NULL)
        cout<<"\nmemory is not allocated.";
    else
    {
        int key;
        cout<<"\nenter data of 1st node:";
        cin>>key;
        head->data=key;
        head->next=NULL;
    }
    temp=head;
    for(int i=2;i<=n;i++)
    {
        new_node=new Node();
        if(new_node==NULL)
            cout<<"\nmemory is not allocated.";
        else
        {
            int key;
            cout<<"\nenter data of "<<i<<"nd node:";
            cin>>key;
            new_node->data=key;
            new_node->next=NULL;
        }
        temp->next=new_node;
        temp=temp->next;
    }
    cout<<"\nlist is created.";
}

int find_length()
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
void printArr(int arr[],int l)
{
    cout<<endl;
    for(int i=0;i<l;i++)
     cout<<arr[i]<<" ";
}
void convert()
{
    int l=find_length();
    int arr[l];

    int idx=0;
    Node *curr=head;

    while(curr!=NULL)
    {
        arr[idx++]=curr->data;
        curr=curr->next;
    }
    printArr(arr,l);
}
int main()
{
    int n;
    cout<<"\nenter no of nodes:";
    cin>>n;
    createlist(n);
    convert();
    return 0;
}
