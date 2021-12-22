#include <bits/stdc++.h>
using namespace std;

void print_Strings(int n,int last_digit,string out)
{
    if(n==0)
    {
       cout<<out<<endl;
       return;
    }
    if(last_digit==0)
    {
        print_Strings(n-1,0,out+"0");
        print_Strings(n-1,1,out+"1");
    }
    else
        print_Strings(n-1,0,out+"0");
}
int main()
{
    int n;
    cin>>n;
    string out=" ";
    print_Strings(n,0,out);
    return 0;
}
