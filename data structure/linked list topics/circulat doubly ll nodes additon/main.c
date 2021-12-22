#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
}*head;

void createlist(int n);
void display();
void addnodeAtbeginning();
void addnodeAtend();
void addnodeAtn();

int main()
{
    int choice,n;
    while(choice!=6)
    {
        printf("\n1.create list.");
        printf("\n2.display list.");
        printf("\n3.add node at beginning of list.");
        printf("\n4.add node at end of list.");
        printf("\n5.add node at any position of list.");
        printf("\n6.exit.");
        printf("\nenter the choice:");
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
            addnodeAtbeginning();
            break;
        case 4:
            addnodeAtend();
            break;
        case 5:
            addnodeAtn();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nenter the valid option.");
            break;
        }
    }
    return 0;
}
void createlist(int n)
{
    struct node *temp,*newnode;
    int i,data;
    head=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the data of 1st node:");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    head->prev=NULL;
    temp=head;
    if(head==NULL)
        printf("\nmemory is not allocated.");
    else
    {
        for(i=2;i<=n;i++)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nenter the data of %dth node:",i);
            scanf("%d",&data);
            newnode->data=data;
            newnode->next=NULL;
            newnode->prev=temp;

            temp->next=newnode;
            temp=newnode;
        }
        temp->next=head;
        head->prev=temp;
    }
    printf("\ncircular doubly ll is created.");
}

void display()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
        printf("\nlist is empty.");
    else
    {
        do
          {
              printf("%d-->",temp->data);
              temp=temp->next;
          }while(temp!=head);
    }
}

void addnodeAtbeginning()
{
    struct node *temp,*newnode;
    int data;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("\nmemory is not allocated.");
    else
    {
        printf("\nenter the data of new node:");
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=temp;
        temp->prev=newnode;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        newnode->prev=temp;
        temp->next=newnode;
    }
    head=newnode;
}

void addnodeAtend()
{
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    temp=head;
    int data;
    printf("\nenter the data of new node:");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=temp;

    while(temp->next!=head)
    {
        temp=temp->next;
    }
    newnode->prev=temp;
    temp->next=newnode;
    head->prev=newnode;
}

void addnodeAtn()
{
    struct node *temp,*pretemp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int data,pos,i;
    temp=head;
    printf("\nenter the data of new node:");
    scanf("%d",&data);
    newnode->data=data;
    printf("\nenter the position where to add node:");
    scanf("%d",&pos);
    for(i=1;i<pos;i++)
    {
        pretemp=temp;
        temp=temp->next;
    }
    newnode->prev=pretemp;
    newnode->next=temp;
    pretemp->next=newnode;
    temp->prev=newnode;
}
