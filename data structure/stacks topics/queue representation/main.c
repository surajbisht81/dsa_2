//array representation of queue;
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int queue[MAX];
int front=-1,rear=-1;

void enqueue(int);
int dequeue();
void display();
void peep();

int main()
{
    int choice,data;
    while(1)
    {
        printf("\n1.insert element \n2.delete element \n3.display queue \n4.peep");
        printf("\n\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter the data to add:");
            scanf("%d",&data);
            enqueue(data);
            break;
        case 2:
            data=dequeue();
            printf("\ndeleted element is=%d",data);
            break;
        case 3:
            display();
            break;
        case 4:
            peep();
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

void enqueue(int data)
{
    if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        queue[front]=data;
    }
    else
    {
        rear++;
        queue[rear]=data;
    }
    printf("\ndata is added successfully.");
}

int dequeue()
{
    int value;
    if(front==-1 || front>rear)
    {
        printf("\nqueue is empty.");
        return ;
    }
    else
    {
       value=queue[front];
       front++;
       return value;
    }
    return;
}

void display()
{
    int i;
    if(front==-1 || front>rear)
    {
        printf("\nqueue is empty.");
        return;
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d--",queue[i]);
        }
    }
}

void peep()
{
    if(front==-1 || front>rear)
    {
        printf("\nqueue is empty.");
        return;
    }
    else
    {
        printf("\nfront value of queue is=%d",queue[front]);
    }
}
