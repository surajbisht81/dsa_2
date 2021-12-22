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
    void pop();
    int top();
    int size();
};

int Stack :: size()
{
    return curr_size;
}

void Stack :: push(int data)
{
    q1.push(data);
    curr_size++;
}

void Stack :: pop()
{
    if(q1.empty())
    {
        return;
    }
    else
    {
       while(q1.size()>1)
       {
         q2.push(q1.front());
         q1.pop();
       }
       q1.pop();
       curr_size--;

       queue<int> q;
       q = q2;
       q2 = q1;
       q1 = q;
    }
}

int Stack :: top()
{
    if(q1.size()==0)
    {
        return 0;
    }
    else
    {
       while(q1.size()>1)
       {
         q2.push(q1.front());
         q1.pop();
       }
       int temp = q1.front();
       q2.push(temp);
       q1.pop();

       queue<int> q;
       q = q2;
       q2 = q1;
       q1 = q;

       return temp;
    }
}

int main()
{
  Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "current size: " << s.size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "current size: " << s.size()
         << endl;
    return 0;
}
