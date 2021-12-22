#include <bits/stdc++.h>
using namespace std;

//brute force approach
/*bool isSteppingNo(int num)
{
    int prevdigit = -1;

    while(num)
    {
        int currdigit = num%10;

        if(prevdigit==-1)
            prevdigit = currdigit;
        else
        {
            if(abs(prevdigit - currdigit)!=1)
                return false;
        }
        prevdigit = currdigit;
        num /=10;
    }
    return true;
}
void steppingNumber(int n, int m)
{
       for(int i=n; i<=m; i++)
       {
           if(isSteppingNo(i));
             cout<<i<<" ";
       }
}

int main()
{
    int n = 0, m=21;
    steppingNumber(n, m);
    return 0;
}
*/

// using Graph
void BFS(int i, int n, int m)
{
     queue<int> qu;
     qu.push(i);

     while(!qu.empty())
     {
         int p = qu.front();
         qu.pop();

         if(p<=m and p>=n)
            cout<<p<<" ";

         if(i==0 or p>m)
            continue;

         int lastDigit = p%10;

         int lastDigitA = p*10 + (lastDigit - 1);
         int lastDigitB = p*10 + (lastDigit + 1);

         if(lastDigit==0)
            qu.push(lastDigitB);
         else if(lastDigit==9)
            qu.push(lastDigitA);
         else
         {
             qu.push(lastDigitA);
             qu.push(lastDigitB);
         }
     }
}

void SteppingNumber(int n, int m)
{
    for(int i=0; i<=9; i++)
    {
        BFS(i, n, m);
    }
}
int main()
{
    int n=0, m=21;
    SteppingNumber(n, m);
    return 0;
}
