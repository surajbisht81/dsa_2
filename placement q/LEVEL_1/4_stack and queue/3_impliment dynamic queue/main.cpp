#include <bits/stdc++.h>
using namespace std;

struct node
{
   int data;
   node *next;
};

class Qu
{
    private:
    node *front, *rear;

    public:
     Qu();
    ~Qu();

    void enqueue(int data);
    void dequeue();
    void display();
    void peep();
};

Qu :: Qu()
{
    front = rear = NULL;
}

Qu :: ~Qu()
{
    node *temp;
    while(front!=NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
}

void Qu :: enqueue(int data)
{
    node *temp;
   if(front==NULL and rear==NULL)
   {
       temp = new node;
       temp->data = data;
       temp->next = NULL;
       front = rear = temp;
   }
   else
   {
       temp = new node;
       temp->data = data;
       temp->next = NULL;
       rear->next = temp;
       rear = temp;
   }
}

void Qu :: dequeue()
{
   if((front==NULL and rear==NULL) or front > rear)
   {
       cout<<"queue is empty!";
       return;
   }
   else
   {
       node *temp = front;
       front = front->next;
       cout<<"\ndeleted element is : "<<temp->data;
       delete temp;
   }
}

void Qu :: display()
{
    node *temp = front;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void Qu :: peep()
{
  if((front==NULL and rear==NULL) or front > rear)
   {
       cout<<"queue is empty!";
       return;
   }
   else
   {
       cout<<"\nfront element is : "<<front->data;
   }
}

int main()
{
    int choice,data;
    Qu Q;
    while(1)
    {
        cout<<"\n1.display Qu \n2.add element in Qu \n3.delete element is Qu \n4.peep";
        cout<<"\n\nenter your choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            Q.display();
            break;
        case 2:
            cout<<"\nenter the element to add:";
            cin>>data;
            Q.enqueue(data);
            break;
        case 3:
            Q.dequeue();
            break;
        case 4:
            Q.peep();
            break;
        default:
            cout<<"\nenter the valid option.";
        }
    }
return 0;
}
