#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(struct node **head,int n);
void display(struct node **head);
void deleteAtfirst(struct node **head);
void deleteAtlast(struct node **head);
void deleteAtN(struct node **head);

int main()
{
    int choice,n;
    struct node *head=NULL;

     while(choice!=6)
    {
    printf("\n1.create list");
    printf("\n2.display");
    printf("\n3.delete first node");
    printf("\n4.delete last node");
    printf("\n5.delete at any position");
    printf("\n6.Exit");
    printf("\nenter your choice:");
    scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("\nenter the no of nodes:");
            scanf("%d",&n);
            createlist(&head,n);
            break;
        case 2:
            display(&head);
            break;
        case 3:
            deleteAtfirst(&head);
            break;
        case 4:
            deleteAtlast(&head);
            break;
        case 5:
            deleteAtN(&head);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nenter valid option.");
            break;
        }
    }
    return 0;
}
void createlist(struct node **head,int n)
{
    struct node *curr=NULL,*new_node;
    int i,data;
    for(i=1;i<=n;i++)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("\nenter the data of %dth node:",i);
        scanf("%d",&data);
        new_node->data=data;
        new_node->next=NULL;

        if(*head==NULL)
            {*head=new_node;
            }
        else
            {
                curr->next=new_node;
                curr=curr->next;
            }
            curr=new_node;
    }
    curr->next=*head;
     printf("\nlist is created successfully");
}

void display(struct node **head)
{
    struct node *curr;
    curr=*head;
    if(*head==NULL)
        printf("\nlist is empty");
    else
    {
        do
        {
            printf("%d-->",curr->data);
            curr=curr->next;
        }while(curr!=*head);
    }
}

void deleteAtfirst(struct node **head)
{
    struct node *curr,*prev;
    curr=*head;
    prev=*head;
    while(prev->next!=*head)
    {
        prev=prev->next;
    }
    prev->next=curr->next;
    *head=curr->next;
    free(curr);
    printf("\nfirst node is deleted ");
}
void deleteAtlast(struct node **head)
{
    struct node *curr,*prev;
    curr=*head;
    prev=*head;
    while(curr->next!=*head)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;

    free(curr);
    printf("\nlast node is deleted");
}

void deleteAtN(struct node **head)
{
    struct node *curr,*prev;
    curr=*head;
    prev=*head;
    int n,i;
    printf("\nenter the position where to delete node:");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    free(curr);
    printf("\nnode at required index is deleted");
}
