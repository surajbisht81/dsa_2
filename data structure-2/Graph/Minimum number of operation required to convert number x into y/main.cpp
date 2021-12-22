/*Last Updated: 01-11-2019
Given a initial number x and two operations which are given below:

Multiply number by 2.
Subtract 1 from the number.
The task is to find out minimum number of operation required to convert number x into y using only above two operations. We can apply these operations any number
 of times.*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    int level;
};

int minOperations(int x, int y)
{
    set<int> visited;
    queue<node>qu;

    node n = {x, 0};
    qu.push(n);

    while(!qu.empty())
    {
        node p = qu.front();
        qu.pop();

        visited.insert(p.val);
        if(p.val==y)
            return p.level;
        if(p.val*2==y or p.val-1==y)
            return p.level+1;

        if(visited.find(p.val*2)==visited.end())
        {
            n.val=p.val*2;
            n.level = p.level+1;
            qu.push(n);
        }
        if(p.val-1>0 and visited.find(p.val-1)==visited.end())
        {
            n.val = p.val-1;
            n.level=p.level+1;
            qu.push(n);
        }
    }
    return 0;
}

int main()
{
    int x=4, y=7;
    cout<<minOperations(x, y);
    return 0;
}
