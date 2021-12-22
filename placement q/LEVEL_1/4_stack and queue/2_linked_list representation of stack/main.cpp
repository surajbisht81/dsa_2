#include <bits/stdc++.h>
using namespace std;

class node
{
     public:
    int data;
    node *next;
}*top, *temp;

int count_element = 0;

void create()
{
    top = NULL;
}

void display()
{
    temp = top;
    if(top == nullptr)
    {
        cout<<"\nstack is empty.";
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void push(int data)
{
    if(top == NULL)
    {
        top = new node;
        top->data = data;
        top->next = NULL;
    }
    else{

        temp = new node;
        temp->data = data;
        temp->next = top;
        top = temp;
    }
    count_element++;
}

void pop()
{
    if(top==NULL)
    {
      cout<<"\nstack is empty";
      return;
    }
    else{
       temp = top;
       top = top->next;
       delete temp;
    }
    count_element--;
}

void peek()
{
    if(top==NULL)
    {
        cout<<"\nstack is empty.";
        return;
    }
    else{
        cout<<"\ntop element of stack is: "<<top->data;
    }
}

void Destroy()
{
    if(top == NULL)
    {
        cout<<"\nstack is empty.";
        return;
    }
    else{
        while(top!=NULL)
        {
          temp = top;
          top = top->next;
          delete temp;
          count_element--;
        }
    }
}

void Total_elements()
{
    cout<<"\n total elements are : "<<count_element;
}
int main()
{
    int data, choice;

    create();
    while(1)
    {
        cout<<"\n\n1.display"<<endl<<"2.push"<<endl<<"3.pop"<<endl<<"4.peek"<<endl<<"5.Total_elements"<<endl<<"6.Destroy"<<endl<<"7.break"<<endl<<"--------------"<<endl;

        cout<<"\nenter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            display();
            break;
        case 2:
            cout<<"\nenter the data: ";
            cin>>data;
            push(data);
            break;
        case 3:
            pop();
            break;
        case 4:
            peek();
            break;
        case 5:
            Total_elements();
            break;
        case 6:
            Destroy();
            break;
        case 7:
            exit(0);
            break;
        default:
            cout<<"\nenter valid info!";
            break;
        }
    }
    return 0;
}
