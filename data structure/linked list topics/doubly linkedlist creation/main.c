#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*head;
void createlist(int n);
void displayfromfirst();
void displayfromend();

int main()
{
    int n;
    printf("\nenter the no of nodes:");
    scanf("%d",&n);
    createlist(n);
    printf("\ncreated list is:\n");
    displayfromfirst();
    printf("\ndisplay from end is:\n");
    displayfromend();
    return 0;
}
void createlist(int n)
{
    struct node *new_node,*temp;
    int i,data;
    head=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the data of 1st node:");
    scanf("%d",&data);
    head->data=data;
    head->prev=NULL;
    head->next=NULL;
    temp=head;

    if(head==NULL)
        printf("\nmemory is not allocated");
    else
    {
        for(i=2;i<=n;i++)
        {
            new_node=(struct node*)malloc(sizeof(struct node));
            if(new_node!=NULL)
            {
            printf("\nenter the data of %dth node:",i);
            scanf("%d",&data);
            new_node->data=data;
            new_node->prev=temp;
            new_node->next=NULL;

            temp->next=new_node;
            temp=temp->next;
            }
        }
    }
}

void displayfromfirst()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
        printf("\nmemory is not allocated");
    else
    {
        while(temp!=NULL)
        {
        printf("%d-->",temp->data);
        temp=temp->next;
        }
    }
}

void displayfromend()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
        printf("list is empty");
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->prev;
        }
    }
}
