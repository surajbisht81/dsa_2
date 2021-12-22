#include <iostream>
#include<list>
#include<iterator>

using namespace std;

class Hashing
{
public:
    int bucket;
    list<int> *table;
public:
    Hashing(int v);
    void insertitem(int data);
    void deleteitem(int data);
    int hashfunction(int data);
    void displayhash();
};
Hashing ::Hashing(int v)
{
    bucket=v;
    table=new list<int>[bucket];
}
int Hashing :: hashfunction(int data)
{
    return (data % bucket);
}

void Hashing ::insertitem(int data)
{
    int item=hashfunction(data);
    table[item].push_back(data);
}

void Hashing::deleteitem(int data)
{
    int item=hashfunction(data);
    list<int>::iterator i;
    for( i=table[item].begin();i!=table[item].end();i++)
    {
        if(*i==data)
            break;
    }
    if(i!=table[item].end())
    {
        table[item].erase(i);
    }
}
void Hashing ::displayhash()
{
    for(int i=0;i<bucket;i++)
     {
        cout<<i;
        for(auto x:table[i])
         cout<<"-->"<<x;
         cout<<endl;
        }
}
int main()
{
   int arr[]={15,11,27,8,12};
   int n=sizeof(arr)/sizeof(arr[0]);
   Hashing h(7);
   for(int i=0;i<n;i++)
   {
       h.insertitem(arr[i]);
   }
   h.displayhash();
   h.deleteitem(11);
   h.displayhash();
   return 0;
}
