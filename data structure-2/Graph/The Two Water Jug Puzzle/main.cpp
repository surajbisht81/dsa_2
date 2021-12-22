/*You are on the side of the river. You are given a m liter jug and a n liter jug where 0 < m < n. Both the jugs are initially empty. The jugs don’t have markings 
to allow measuring smaller quantities. You have to use the jugs to measure d liters of water where d < n. Determine the minimum no of operations to be performed
 to obtain d liters of water in one of jug.
The operations you can perform are:

Empty a Jug
Fill a Jug
Pour water from one jug to the other until one of the jugs is either empty or full.*/

#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    if(b==0)
        return a;
    return GCD(b, a%b);
}

int pour(int fromcap, int tocap, int d, vector<pair<int, int>>&v)
{
    v.push_back(make_pair(0,0));

    int from= fromcap;
    int to=0;
    v.push_back(make_pair(from, to));
    int step=1;

    while(from!=d && to!=d)
    {
        int temp = min(from, (tocap-to));

        from-=temp;
        to+=temp;
        v.push_back(make_pair(from, to));
        step++;

        if(from==d or to==d)
            break;

        if(from==0)
        {
            from=fromcap;
            v.push_back(make_pair(from, to));
            step++;
        }

        if(to==tocap)
        {
            to=0;
            v.push_back(make_pair(from, to));
            step++;
        }
    }
    return step;
}
int minSteps(int m, int n, int d)
{
    if(m>n)
        swap(m, n);
    if(d>n)
        return -1;

    if(d % GCD(m,n)!=0)
        return -1;

    vector<pair<int, int>> x, y;
    int res =  min(  pour(m, n, d, x),
                 pour(n, m, d, y));
    if(x.size()<y.size())
     for(int i=0;i<x.size(); i++)
        cout<<x[i].first<<" "<<x[i].second<<endl;
    else
        for(int i=0;i<y.size(); i++)
        cout<<y[i].first<<" "<<y[i].second<<endl;
    return res;
}
int main()
{
     int n = 3, m = 5, d = 4;

    printf("\nMinimum number of steps required is %d",
           minSteps(m, n, d));
           return 0;
}
