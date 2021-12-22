#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int next;
}*head;

void createlist(int n);
void insertatend(int data);
void display();

int main()
{
    int n,data;
    printf("\nenter the no of nodes:");
    scanf("%d",&n);
    createlist(n);
     display();
    printf("\nenter the data to insert at end:");
    scanf("%d",&data);
    insertatend(data);
    display();
    return 0;
}

void createlist(int n)
{
    int i,data;
    struct node *temp,*new_node;
    head=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
        printf("\nmemory is not allocated");
    else
    {
       printf("\nenter the data of 1st node:");
       scanf("%d",&data);
       head->data=data;
       head->next=NULL;
       }
       temp=head;
    for(i=2;i<=n;i++)

     {
         new_node=(struct node *)malloc(sizeof(struct node));
        if(new_node==NULL)
            {   printf("memory is not allocated,");
                break;
             }
       else
       {
        printf("\nenter data of %dth node",i);
        scanf("%d",&data);
        new_node->data=data;
        new_node->next=NULL;
       }
        temp->next=new_node;
        temp=temp->next;

    }
   printf("\nlist is created successfully.");
}

void insertatend(int data)
{
    struct node *temp,*new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
      {
        printf("memory is not allocated");

      }
    else
      {  temp=head;
        new_node->data=data;
        new_node->next=NULL;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=new_node;
      }
    printf("\n node is added successfully.");
}
void display()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
        printf("\nlist is empty");
    else
    {
        while(temp!=NULL)
        {
            printf("\ndata=%d\n",temp->data);
            temp=temp->next;
        }
    }
}
