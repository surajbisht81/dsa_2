#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void display();
void insertAtbeggining();
void insertAtN();

int main()
{
    int n;
    printf("\nenter the no of nodes:");
    scanf("%d",&n);
    createlist(n);
    printf("\nlist is:\n");
    display();
    printf("\ninsert a new node at beggining:");
    insertAtbeggining();
    printf("\nnew list\n");
    display();
    printf("\ninsert a new node at any place:\n");
    insertAtN();
    printf("\nnew node is:");
    display();
    return 0;
}

void createlist(int n)
{
    int i,data;
    struct node *temp,*new_node;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
        printf("\nmemory is not allocated");
    else
    {
        printf("\nenter data of 1st node");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
    }
    temp=head;
    for(i=2;i<=n;i++)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("\nenter data of %dth node",i);
        scanf("%d",&data);
        new_node->data=data;
        new_node->next=NULL;

        temp->next=new_node;
        temp=new_node;
    }
     temp->next=head;
     printf("\ncircular ll created.");
}

void display()
{
    struct node *temp;
    if(head==NULL)
        printf("\nlist is empty.");
    else
    {
        temp=head;
        do
        {
            printf("data-->%d",temp->data);
            temp=temp->next;
        }while(temp!=head);
    }
}
void insertAtbeggining()
{
    struct node *temp,*new_node;
    temp=head;
    new_node=(struct node*)malloc(sizeof(struct node));
    int data;
    printf("\nenter data of new node:");
    scanf("%d",&data);
    new_node->data=data;
    new_node->next=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    head=new_node;
    printf("\ninsertion at beggining is successful");
}

void insertAtN()
{
    int i,pos,data;
    printf("\nenter the position after which to add node:");
    scanf("%d",&pos);
    struct node *new_node,*temp;
    temp=head;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data of new node:");
    scanf("%d",&data);
    new_node->data=data;
    for(i=1;i<=pos-1;i++)
    {
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    printf("\nnode is added successfully");
}

