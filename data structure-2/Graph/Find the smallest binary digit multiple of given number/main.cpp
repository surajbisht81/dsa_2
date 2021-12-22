#include <bits/stdc++.h>
using namespace std;

int rem(string t, int N)
{
    int r=0;
    for(int i=0; i<t.length(); i++)
    {
        r = r*10 + (t[i]-'0');

        r = r%N;
    }
    return r;
}
string smallestBinaryDigit(int N)
{
    queue<string> qu;
    set<int> visit;
    qu.push("1");

    while(!qu.empty())
    {
        string t = qu.front();
        qu.pop();

        int r = rem(t, N);
        if(r==0)
            return t;

        else if(visit.find(r)==visit.end())
        {
            visit.insert(r);
            qu.push(t+"0");
            qu.push(t+"1");
        }
    }
}
int main()
{
    int N = 17;
    cout<<smallestBinaryDigit(N);
    return 0;
}
