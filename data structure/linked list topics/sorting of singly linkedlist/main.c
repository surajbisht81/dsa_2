#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void sortlist();
void display();

int main()
{
    int n;
    printf("\nenter the no of nodes:");
    scanf("%d",&n);
    createlist(n);
    printf("\ncreated list is:\n");
    display();
    printf("\nafter sorting list is:\n");
    sortlist();
    display();
    return 0;
}

void createlist(int n)
{
    struct node *new_node, *temp;
    int data,i;
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
        printf("\nenter data of %dth node:",i);
        scanf("%d",&data);
        new_node->data=data;
        new_node->next=NULL;

        temp->next=new_node;
        temp=temp->next;
    }
    printf("\nlist is created successfully.");
}

void display()
{
    struct node* temp;
    if(head==NULL)
        printf("\nlist is empty.");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
    }
}
void sortlist()
{
    struct node *temp1,*temp2;
    int var;
    temp1=head;
    while(temp1->next!=NULL)
    {
        temp2=temp1->next;
        while(temp2!=NULL)
        {
            if(temp1->data>temp2->data)
            {
                var=temp2->data;
                temp2->data=temp1->data;
                temp1->data=var;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}
