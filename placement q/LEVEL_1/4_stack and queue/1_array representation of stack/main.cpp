#include <bits/stdc++.h>
using namespace std;
#define MAX 6
int Stack[MAX], top=-1;

void display()
{
    if(top==-1)
     {
         cout<<"\nstack is empty.";
         return;
     }
     else
     {
       cout<<"\nelements are:"<<endl;
       for(int i=0; i<=top; i++)
         cout<<Stack[i]<<" ";
     }
}

void push(int item)
{
    if(top==MAX-1)
    {
        cout<<"\nstack if full.";
        return;
    }
    else
    {
        top++;
        Stack[top]=item;
    }
}

void pop()
{
    if(top==-1)
    {
        cout<<"\nstack is empty.";
        return;
    }
    else
    {
        int x = Stack[top];
        top--;
        cout<<"\npopped element is: "<<x;
    }
}

void peek()
{
    if(top==-1)
    {
        cout<<"\nstack is empty";
        return;
    }
    else
    {
        cout<<"\ntop element is :"<<Stack[top];
    }
}

int main()
{
   int data, choice;

   while(1)
   {
       cout<<"\n\n1.display"<<endl<<"2.push"<<endl<<"3.pop"<<endl<<"4.peek"<<endl<<"5.break"<<endl<<"-----------------------"<<endl;
       cout<<"\nenter choice: ";
       cin>>choice;
       switch(choice)
       {
           case 1:
            display();
            break;

           case 2:
            cout<<"\nenter your data:";
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
            exit(0);
            break;

           default:
            cout<<"\nenter valid info.!";
            break;
       }
   }
   return 0;
}
