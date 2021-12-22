#include <bits/stdc++.h>
using namespace std;

class SpecialStack
{
private:
       stack<int> alldata;
 public:
   int min=-1;
   void push(int key);
   void pop();
   void get_min();
   void Size();
};

void SpecialStack :: Size()
{
    cout<<alldata.size();
}

void SpecialStack :: push(int key)
{
    if(alldata.size()==0)   // when stack is empty then min and alldata will contain first element
    {
        alldata.push(key);
        min = key;
    }
    else if(key >= min)     // if current value is greater than min then min will not be updated
    {
        alldata.push(key);
    }
    else
    {
       alldata.push(key+key-min);     //encoding , min will get the current value but pushed element will be encoded as
       min = key;                       // key + key -min and this value will be less than min;
    }
}

void SpecialStack :: pop()
{
    if(alldata.size()==0)
    {
        cout<<"\nstack underflow!";
        return;
    }
    else if( alldata.top() >= min)   // if top element is greater than min then nothing will change
    {
        alldata.pop();
    }
    else
    {
        min = 2*min - alldata.top();   // but if top element is less than min then min will decoded
        alldata.pop();  // after updating min, top element will be popped;
    }
}

void SpecialStack :: get_min()
{
    if(alldata.size()==0)
    {
        cout<<"stack underflow!";
        return;
    }
    else
     cout<<"\nmin value is : "<<min;
}

int main()
{
     SpecialStack obj;
     int choice, data;
    while(1)
    {
        cout<<"\n\n1.PUSH"<<endl<<"2.POP"<<endl<<"3.GET_MIN"<<endl<<"4.Size"<<endl<<"----------------------"<<endl;
        int choice, data;
        cout<<"\nenter choice:";
        cin>>choice;

        switch(choice)
        {
        case 1:
           cout<<"\nenter the data :";
           cin>>data;
           obj.push(data);
           break;
        case 2:
            obj.pop();
            break;
        case 3:
            obj.get_min();
            break;
        case 4:
            obj.Size();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout<<"\nenter the valid option.";
            break;
        }
    }
    return 0;
}
