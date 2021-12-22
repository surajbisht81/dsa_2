//push pop and peep operation on stack using arrays;
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int stack[MAX],TOP=-1;
void display();
void push(int);
void pop();
void peek();
int main()
{
    int item,choice;
    while(1)
    {
        printf("\n1.display stack \n2.push item \n3.pop the item \n4.peek \n5.Exit");
        printf("\nenter your  choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            display();
            break;
        case 2:
            printf("\nenter the item to push into the stack:");
            scanf("%d",&item);
            push(item);
            break;
        case 3:
            pop();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nenter the valid option.");
            break;
        }
    }
    return 0;
}

void push(int item)
{
    if(TOP==MAX-1)
       {
           printf("\noverflow condition occurs.");
           return ;
       }
    else
    {
        TOP++;
        stack[TOP]=item;
    }
}
void pop()
{
    int data;
    if(TOP==-1)
       {
        printf("\nstack is empty or underflow condition.");
        return;
       }
    else
    {
        data=stack[TOP];
        TOP--;
        printf("\npoped item is %d:",data);
    }
}
void display()
{
    int i;
    if(TOP==-1)
    {
      printf("\nstack is empty\n");
      return ;
    }
    else
    {
        for(i=0;i<=TOP;i++)
        {
            printf("\nstack[%d]=%d",i,stack[i]);
        }
    }
}
void peek()
{
    int data;
    if(TOP==-1)
    {
        printf("\nstack is empty");
        return;
    }
    else
    {
      data=stack[TOP];
      printf("\ntop element is:%d",data);
    }
}
