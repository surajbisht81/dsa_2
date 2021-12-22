/*Given a number K, the task is to print the fibonacci numbers present at Kth level of a Fibonacci Binary Tree.*/

#include <bits/stdc++.h>
using namespace std;
#define max 100005
int fib[max];

void fibonacci()
{
    fib[0]=0,fib[1]=1;
    for(int i=2;i<=max;i++)
        fib[i]=fib[i-1]+fib[i-2];
}
void print_numbers(int k)
{
    int left_index= pow(2,k-1);
    int right_index=pow(2,k)-1;

    for(int i=left_index;i<=right_index;i++)
        cout<<fib[i-1]<<" ";
}
int main()
{
    fibonacci();
    int k=4;
    print_numbers(k);
    return 0;
}
