#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*head ,*last;

void createlist(int n);
void display();
void reverselist();

int main()
{
    int n;
    printf("\nenter the no of nodes:");
    scanf("%d",&n);
    createlist(n);
    printf("\ndisplayed list is:");
    display();
    printf("\nreversed list is:");
    reverselist();
    display();
    return 0;
}

void createlist(int n)
{
     struct node *new_node;
     int data,i;
     printf("\nenter the data of 1st node:");
     scanf("%d",&data);
     head=(struct node*)malloc(sizeof(struct node));
     head->data=data;
     head->next=NULL;
     head->prev=NULL;
     last=head;

     for(i=2;i<=n;i++)
     {
         new_node=(struct node*)malloc(sizeof(struct node));
         printf("\nenter the data of %dth node",i);
         scanf("%d",&data);
         new_node->data=data;
         new_node->prev=last;
         new_node->next=NULL;

         last->next=new_node;
         last=new_node;
     }
     printf("\ncreation of doubly linked list is successful");
}

void display()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
        printf("\nlist is empty.");
    else
    {
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
    }
}
void reverselist()
{
    struct node *temp,*current;
    current=head;
    while(current!=NULL)
    {
        temp=current->next;
        current->next=current->prev;
        current->prev=temp;
        current=temp;
    }
    temp=head;
    head=last;
    last=temp;
}
