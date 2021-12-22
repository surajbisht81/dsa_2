#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void createlist(int n);
void insertatbeg(int data);
void display();

int main()
{
    int data,n;
   printf("\nenter the no of nodes:");
   scanf("%d",&n);
   createlist(n);
   display();
   printf("\nenter the data to insert at beggining");
   scanf("%d",&data);
   insertatbeg(data);
   display();
   return 0;
}

createlist(int n)
{
    struct node *new_node,*temp;
    int data,i;
    head=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
        printf("memory is not allocated");
    else
    {
        printf("\nenter data of node 1:");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;

        temp=head;
    }
    for(i=2;i<=n;i++)
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        if(new_node==NULL)
        {
            printf("memory is not allocated");
            break;
        }
        else
        {

            printf("\nenter the data of %d node",i);
            scanf("%d",&data);
            new_node->data=data;
            new_node->next=NULL;
        }
        temp->next=new_node;
        temp=temp->next;
    }
    printf("\n\n list is created successfully");
}
void insertatbeg(int data)
{

    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("\nmemory is not allocated");

    }
    else
    {
        new_node->data=data;
        new_node->next=head;

    }
    head=new_node;
    printf("\n node is inserted successfully");
}
void display()
{

    struct node *temp;
    temp=head;
    if(head==NULL)
        printf("\nlist is not created");
    else
    {
        while(temp!=NULL)
        {
            printf("\ndata=%d\n",temp->data);
            temp=temp->next;
        }
    }
}
