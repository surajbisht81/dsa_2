#include <bits/stdc++.h>
using namespace std;

string RemoveKDigits(string str, int k)
{
    stack<char>s;

    int n = str.length();

    for(char c:str)
    {
        while(!s.empty() && k>0 && s.top()>c)
        {
            s.pop();
            k -=1;
        }
        if(!s.empty() || c!='0')
            s.push(c);
    }

    while(!s.empty() && k--)
        s.pop();

    if(s.empty())
        return "0";
    while(!s.empty())
    {
        str[n-1] = s.top();
        s.pop();
        n -=1;
    }

   return str.substr(n);
}
int main()
{
    string str = "14301620";
    int k=4;

    cout<<RemoveKDigits(str, k);
    return 0;
}
