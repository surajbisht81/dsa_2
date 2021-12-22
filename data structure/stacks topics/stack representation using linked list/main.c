#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
}*top,*top1,*temp;

int topelement();
void push(int data);
void pop();
void empty();
void display();
void destroy();
void stack_count();
void create();
int count=0;
int main()
{
    int data,choice;
    create();
    while(1)
    {
        printf("\n1.push \n2.pop \n3.display \n4.count no of elements \n5.destroy \n6.exit");
        printf("\n\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter the data of element for push:");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            stack_count();
            break;
        case 5:
            destroy();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\n invalid option.");
            break;
        }
    }
    return 0;
}

//creating the top element as null;
void create()
{
    top=NULL;
}
void push(int data)
{
    if(top==NULL)
    {
        top=(struct node*)malloc(sizeof(struct node));
        top->data=data;
        top->ptr=NULL;
    }
    else
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->ptr=top;
        top=temp;
    }
    count++;
}
void display()
{
    if(top==NULL)
    {
        printf("\nstack is empty.");
        return;
    }
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("\n%d",temp->data);
            temp=temp->ptr;
        }
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("\nstack is empty");
        return;
    }
    else
    {
    temp=top;
    top=temp->ptr;
    free(temp);
    }
    count--;
}
void stack_count()
{
    printf("\n\n no of elements in stack=%d",count);
}

void destroy()
{

    if(top==NULL)
    {
        printf("\nstack is empty");
        return;
    }
    else
    {
        while(top!=NULL)
        {
         temp=top;
         printf("\ndeleted element is= %d",top->data);
         top=top->ptr;
         free(temp);
        }
    }
    printf("\nall elements are destroyed.");
}
