#include <bits/stdc++.h>
using namespace std;

class SpecialStack
{
private:
       stack<int> alldata;
       stack<int> mindata;
 public:
   void push(int key);
   void pop();
   void get_min();
};

void SpecialStack :: push(int key)
{
     alldata.push(key);
     if(mindata.size()==0 or mindata.top() > key)
        mindata.push(key);
}

void SpecialStack :: pop()
{
    int x;
    if(alldata.size()==0)
    {
        cout<<"\nstack underflow!";
        return;
    }
    else{
        x = alldata.top();
        alldata.pop();
        if(mindata.top() == x)
            mindata.pop();
    }
    cout<<"\npopped element is :"<<x;
}

void SpecialStack :: get_min()
{
    if(alldata.size()==0)
    {
        cout<<"\nstack underflow!";
        return;
    }
    else{
        cout<<"\nmin value is : "<<mindata.top();
    }
}
int main()
{
    SpecialStack obj;

    while(1)
    {
        cout<<"\n\n1.PUSH"<<endl<<"2.POP"<<endl<<"3.GET_MIN"<<endl<<"----------------------"<<endl;
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
            exit(0);
            break;
        default:
            cout<<"\nenter the valid option.";
            break;
        }
    }
    return 0;
}
