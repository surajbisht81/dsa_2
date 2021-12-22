#include <bits/stdc++.h>
using namespace std;

int max_rectangle(int hist[],int n)
{
    stack<int>s;
    int i=0;
    int top,maxx=0,area=0;

    while(i<n)
    {
        if(s.empty() || hist[s.top()]<=hist[i])
            s.push(i++);

        else
        {
            top=s.top();
            s.pop();
            area= hist[top]*(s.empty()?i:(i-1-s.top()));

            if(maxx<area)
                maxx=area;
        }
    }

    while(!s.empty())
    {
        top=s.top();
        s.pop();
        area= hist[top]*(s.empty()?i:(i-1-s.top()));

            if(maxx<area)
                maxx=area;
    }
    return maxx;
}
int main()
{
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n=sizeof(hist)/sizeof(hist[0]);
    cout<<"\nmax rectangular area is :"<<max_rectangle(hist,n);
    return 0;
}
