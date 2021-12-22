#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class Qu
{
public:
    node *front,*rear;
public:
    Qu();
    ~Qu();
    void enQu(int data);
    void dequeue();
    void display();
    void peep();
};

Qu::Qu()
{
    front=NULL;
    rear=NULL;
}
void Qu::enQu(int data)
{
    node *temp=new node;
    if(front==NULL && rear==NULL)
    {
        temp->data=data;
        temp->next=NULL;
        front=temp;
        rear=temp;
    }
    else
    {
        temp->data=data;
        temp->next=NULL;
        rear->next=temp;
        rear=temp;
    }
    cout<<"\nnode is added successfully.";
}

void Qu::display()
{
    node *temp;
    temp=front;
    if(front==NULL || front>rear)
    {
        cout<<"\nQu is empty.";
        return;
    }
    else
    {
        while(temp!=NULL)
           {
            cout<<temp->data<<"--";
            temp=temp->next;
           }
    }
}

void Qu::dequeue()
{
    node *temp;
    if(front==NULL || front>rear)
    {
        cout<<"\nqueue is empty.";
        return;
    }
    else
    {
        temp=front;
        front=front->next;
        delete temp;
    }
    cout<<"\nnode is deleted.";
}

void Qu::peep()
{
    if(front==NULL || front>rear)
    {
        cout<<"\nqueue is empty.";
        return;
    }
    else
    {
        cout<<"\nfront value of queue is="<<front->data;
    }
}
Qu::~Qu()
{
    while(front!=NULL)
    {
        node *temp=front;
        front=front->next;
        delete temp;
    }
    rear=NULL;
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
            Q.enQu(data);
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
