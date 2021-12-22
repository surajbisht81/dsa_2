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
void additionAtbeggining();
void additonAtend();
void additionAtN();

int main()
{
    int n;
    printf("\nenter the no of nodes:");
    scanf("%d",&n);
    createlist(n);
    printf("\ncreated list is:\n");
    displayfromfirst();
    printf("\nadd node at beggining:");
    additionAtbeggining();
    displayfromfirst();
    printf("\nadd node at end:");
    additonAtend();
    displayfromfirst();
    printf("\naddition at any position\n");
    additionAtN();
    displayfromfirst();
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

void additionAtbeggining()
{
    struct node *new_node;
    int data;
    printf("\nenter the data of new node:");
    scanf("%d",&data);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->prev=NULL;

    new_node->next=head;
    head=new_node;
    printf("\naddition at first is success");
}
void additonAtend()
{
    struct node *temp,*new_node;

    int data;
    printf("\nenter the data of new node:");
    scanf("%d",&data);
    temp=head;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    while(temp->next!=NULL)
        temp=temp->next;
    new_node->prev=temp;
    temp->next=new_node;
    printf("\naddition is success");

}

void additionAtN()
{
    struct node *temp,*new_node,*pretemp;
    temp=head;
    pretemp=head;
    int i,data,pos;
    printf("enter the data of new node:");
    scanf("%d",&data);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    printf("enter the position to add the node:");
    scanf("%d",&pos);
    for(i=1;i<pos;i++)
    {
        pretemp=temp;
        temp=temp->next;
    }
    new_node->next=pretemp->next;
    new_node->prev=temp->prev;

    pretemp->next=new_node;
    temp->prev=new_node;
}
