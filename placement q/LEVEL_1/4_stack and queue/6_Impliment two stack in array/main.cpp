#include <bits/stdc++.h>
using namespace std;

class TwoStacks
{
private:
    int* arr;
    int Size;
    int tos1, tos2;
public:
    TwoStacks(int n)
    {
        Size = n;
        arr = new int[n];
        tos1 = -1;
        tos2 = n;
    }
    void push1(int item);
    int pop1();
    int get_size1();
    int Top1();

    void push2(int item);
    int pop2();
    int get_size2();
    int Top2();
};

// This is for stack 1-------------------------------
void TwoStacks :: push1(int item)
{
    if(tos1+1 == tos2)
    {
        cout<<"\nStack 1 is overflow.";
        return;
    }
    else
    {
        tos1++;
        arr[tos1] = item;
    }
}

int TwoStacks :: pop1()
{
    if(tos1 == -1)
    {
        cout<<"\nstack 1 is underflow.";
        return -1;
    }
    else
    {
        int temp = arr[tos1];
        tos1--;
        return temp;
    }
}

int TwoStacks :: get_size1()
{
    return tos1+1;
}

int TwoStacks :: Top1()
{
    return arr[tos1];
}



// This is for stack 2 ----------------------------------

void TwoStacks :: push2(int item)
{
    if(tos1+1 == tos2)
    {
        cout<<"\nStack 2 is overflow.";
        return;
    }
    else
    {
        tos2--;
        arr[tos2] = item;
    }
}

int TwoStacks :: pop2()
{
    if(tos2 == Size)
    {
        cout<<"\nstack 2 is underflow.";
        return -1;
    }
    else
    {
        int temp = arr[tos2];
        tos1++;
        return temp;
    }
}

int TwoStacks :: get_size2()
{
    return (Size - tos2);
}

int TwoStacks :: Top2()
{
    return arr[tos2];
}
int main()
{
    TwoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "
         << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ts.pop2();
    return 0;
}
