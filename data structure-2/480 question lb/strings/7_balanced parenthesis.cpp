/*Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in exp.*/

#include <bits/stdc++.h>
using namespace std;

bool areparenthesisbalanced(string str)
{
    stack<char> stk;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            stk.push(str[i]);
        // if string initially contain closing brackets then stack will be empty initially;
        if(stk.empty())
          return false;
        if(str[i]==')')
        {
            char x=stk.top();
            stk.pop();
            if(x=='{' || x=='[')
                return false;
        }
        else if(str[i]=='}')
        {
            char x=stk.top();
            stk.pop();
            if(x=='(' || x=='[')
                return false;
        }

        else if(str[i]==']')
        {
            char x=stk.top();
            stk.pop();
            if(x=='(' || x=='{')
                return false;
        }
    }
    return (stk.size()==0);
}
int main()
{
    string str="(()";
    if(areparenthesisbalanced(str))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
    return 0;
}
