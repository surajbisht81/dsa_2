// deletion of nodes at beginning , end and at any position.
#include <stdio.h>
#include <stdlib.h>

struct node
{
   struct node *prev;
   int data;
   struct node *next;
}*head;

void createlist(int n);
void deletenodeAtfirst();
void deletenodeAtend();
void deletenodeAtN();
void display();

int main()
{
    int choice=1,n;
    while(choice!=6)
    {
        printf("\n1.createlist.");
        printf("\n2.display list.");
        printf("\n3.delete first node.");
        printf("\n4.delete last node.");
        printf("\n5.delete node at any position.");
        printf("\n6.Exit.");
        printf("\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter the no of nodes:");
            scanf("%d",&n);
            createlist(n);
            break;
        case 2:
            display();
            break;
        case 3:
            deletenodeAtfirst();
            break;
        case 4:
            deletenodeAtend();
            break;
        case 5:
            deletenodeAtN();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nenter valid options.");
            break;

        }
    }
    return 0;
}

void createlist(int n)
{
     struct node *temp,*new_node;
     int data,i;
     printf("\nenter the data of 1st node:");
     scanf("%d",&data);
     head=(struct node*)malloc(sizeof(struct node));
     head->data=data;
     head->next=NULL;
     head->prev=NULL;
     temp=head;

     for(i=2;i<=n;i++)
     {
         new_node=(struct node*)malloc(sizeof(struct node));
         printf("\nenter the data of %dth node",i);
         scanf("%d",&data);
         new_node->data=data;
         new_node->prev=temp;
         new_node->next=NULL;

         temp->next=new_node;
         temp=temp->next;
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

void deletenodeAtfirst()
{
    struct node *temp,*pretemp;
    temp=head;
    pretemp=head;
    temp=temp->next;
    temp->prev=NULL;
    free(pretemp);
    head=temp;
}
void deletenodeAtend()
{
    struct node *temp,*pretemp;
    temp=head;
    pretemp=head;
    while(temp->next!=NULL)
    {
        pretemp=temp;
        temp=temp->next;
    }
    pretemp->next=NULL;
    free(temp);
}
void deletenodeAtN()
{
    struct node *temp,*pretemp,*posttemp;
    temp=head;
    pretemp=head;
    int pos,i;
    printf("\nenter the position at which we want to delete nodeL:");
    scanf("%d",&pos);
    for(i=1;i<pos;i++)
    {
        pretemp=temp;
        temp=temp->next;
        posttemp=temp->next;
    }
    pretemp->next=posttemp;
    posttemp->prev=pretemp;
    free(temp);
}
