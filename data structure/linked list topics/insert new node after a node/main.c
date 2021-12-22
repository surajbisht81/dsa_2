#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;
void createlist(int n);
void display();
void insertafternode(int data);

int main()
{
    int n,data;
    printf("enter the no of nodes:");
    scanf("%d",&n);
    createlist(n);
    display();
    printf("\nenter the data to add:");
    scanf("%d",&data);
    insertafternode(data);
    display();
    return 0;
}

createlist(int n)
{
    struct node *temp,*new_node;
    int i,data;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
        printf("\nmemory is not allocted.");
    else
    {
        printf("enter the data of 1st node:");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
    }
    temp=head;
    for(i=2;i<=n;i++)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        if(new_node==NULL)
           printf("memory is not allocated");
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

void display()
{

    struct node *temp;
    if(head==NULL)
        printf("\nlist is empty.");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("\nData=%d\n",temp->data);
            temp=temp->next;
        }
    }
}

void insertafternode(int data)
{
    int val;
    struct node *new_node,*temp,*pretemp;
    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
        printf("memory is not allocated");
    else
    {
       temp=head;
       printf("\nenter the value after which node is to be added:");
       scanf("%d",&val);
       new_node->data=data;
       while(temp->data!=val)
       {
           pretemp=temp;
           temp=temp->next;
       }
       pretemp=temp;
       temp=temp->next;

       pretemp->next=new_node;
       new_node->next=temp;
    }

}
