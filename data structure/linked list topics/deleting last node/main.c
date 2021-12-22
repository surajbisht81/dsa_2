/*#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void display();
void deletelastnode();

int main()
{
    int n;
    printf("\nenter the no of nodes:");
    scanf("%d",&n);
    createlist(n);


    printf("\nlist created:\n");
    display();


    printf("\ndeleting last node of list.");
    deletelastnode();

    printf("\nnew list is.");


    display();
    return 0;
}

void createlist(int n)
{
    int i,data;
    struct node *temp,*new_node;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
        printf("\nmemory is not allocated.");
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
        new_node=(struct node*)malloc(sizeof(struct node));
        if(new_node==NULL)
            printf("\nmemory is not allocated.");
        else
        {
            printf("\nenter data of %dth node:",i);
            scanf("%d",&data);
            new_node->data=data;
            new_node->next=NULL;
            temp->next=new_node;
            temp=temp->next;
        }
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
            printf("\ndata=%d",temp->data);
            temp=temp->next;
        }
    }
}

void  deletelastnode()
{
    struct node *temp,*pretemp;
    temp=head;
    pretemp=temp;
    while(temp->next!=NULL)
    {
        pretemp=temp;
        temp=temp->next;
    }
    printf("\ndeleted node is:%d",temp->data);
    pretemp->next=NULL;
    free(temp);
}
