#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    queue<int> q1, q2;
    int curr_size;
public:
    Stack()
    {
        curr_size = 0;
    }
    void push(int data);
    int pop();
    int top();
    int size();
};

int Stack :: size()
{
    return curr_size;
}

void Stack :: push(int data)
{
     if(curr_size==0)
     {
         q1.push(data);
         curr_size++;
     }
     else
     {
         while(q1.size()!=0)
         {
             q2.push(q1.front());
             q1.pop();
         }
         q1.push(data);

         while(q2.size()!=0)
         {
             q1.push(q2.front());
             q2.pop();
         }
         curr_size++;
     }
     cout<<"\n"<<data <<" is added successfully";
}

int Stack :: pop()
{
   int temp = q1.front();
   q1.pop();
   curr_size--;
   return temp;
}

int Stack :: top()
{
    return q1.front();
}

int main()
{
  Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "current size: " << s.size()<<endl;
    cout <<"\ntop element is :"<< s.top() << endl;
    cout<<"\npopped element is: "<<s.pop();
    cout<<"\ntop element is :" << s.top() << endl;
    cout<<"\npopped element is: "<<s.pop();
   cout<<"\ntop element is :" << s.top() << endl;
    cout << "current size: " << s.size()
         << endl;
    return 0;
}
