#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
}*head;

void createlist(int n);
void display();
void deletenodeAtbeginning();
void deletenodeAtend();
void deletenodeAtn();

int main()
{
    int choice,n;
    while(choice!=6)
    {
        printf("\n1.create list.");
        printf("\n2.display list.");
        printf("\n3.delete node at beginning of list.");
        printf("\n4.delete node at end of list.");
        printf("\n5.delete node at any position of list.");
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
            deletenodeAtbeginning();
            break;
        case 4:
            deletenodeAtend();
            break;
        case 5:
            deletenodeAtn();
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

void deletenodeAtbeginning()
{
    struct node *temp,*curr;
    curr=head;
    temp=head;
    while(temp->next!=head)
        temp=temp->next;
    head=head->next;
    head->prev=temp;
    temp->next=head;
    free(curr);
    printf("\ndeletion of first node is done.");
}
void deletenodeAtend()
{
    struct node *temp,*pretemp;
    temp=head;
    pretemp=head;
    while(temp->next!=head)
    {
        pretemp=temp;
        temp=temp->next;
    }
    pretemp->next=head;
    head->prev=pretemp;
    free(temp);
    printf("\ndeletion of last node is done.");
}

void deletenodeAtn()
{
    struct node *temp,*pretemp,*postemp;
    temp=head;
    pretemp=head;
    int pos,i;
    printf("\nenter the position where to delete node:");
    scanf("%d",&pos);
    for(i=1;i<pos;i++)
    {
        pretemp=temp;
        temp=temp->next;
        postemp=temp->next;
    }
    pretemp->next=temp->next;
    postemp->prev=pretemp;
    free(temp);
    printf("\nnode at given position is deleted.");
}
