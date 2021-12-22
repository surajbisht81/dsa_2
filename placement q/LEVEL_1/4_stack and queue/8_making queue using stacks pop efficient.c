
#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    stack<int> helper;
    stack<int> main;
    int Size = 0;
public:
    Queue()
    {
        Size = 0;
    }
    void push(int data);
    int pop();
    int peek();
    int get_size();
};

void Queue :: push(int data)
{
    if(size==0)
    {
        main.push(data);
        Size++;
    }
    else
    {
        while(main.size()!=0)
        {
            helper.push(main.top());
            main.pop();
        }
        main.push(data);
        Size++;
        while(helper.size()!=0)
        {
            main.push(helper.top());
            helper.pop();
        }
    }
}

int Queue :: pop()
{
    int temp = main.top();
    main.pop();
    Size--;
    return temp;
}

int Queue :: peek()
{
    main.top();
}

int Queue :: get_size()
{
    return Size;
}

int main()
{
    Queue Q;
    int choice, data;

    while(1)
    {
        cout<<"\n\n1.size"<<"\n2.push"<<"\n3.pop"<<"\n4.peek"<<"\n5.break"<<endl;

        cout<<"enter choice:";
        cin>>choice;

        if(choice==1){
            cout<<"\ncurrent size is : "<<Q.get_size();
        }else if(choice==2){
              cout<<"\nenter data :";
              cin>>data;
              Q.push(data);
        }else if(choice==3){
              cout<<"\npopped element is :" <<Q.pop();
        }else if(choice==4){

             cout<<"\nfront element is :"<<Q.peek();
        }else if(choice==5){

             exit(0);
        }else{
           cout<<"\nenter valid options.";
        }
    }
    return 0;
}
