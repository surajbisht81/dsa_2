#include <iostream>
using namespace std;

class hashing
{
public:
    int bucket;
    int arr[7];
public:
    hashing(int v);
    void inserdata(int data);
    void deletedata(int data);
    int hashfunction(int data);
    void display();
};
hashing::hashing(int v)
{
    bucket=v;
    for(int i=0;i<bucket;i++)
    {
        arr[i]=NULL;
    }
}

int hashing::hashfunction(int data)
{
    return (data%bucket);
}
void hashing::inserdata(int data)
{
    int item=hashfunction(data);
    while(1)
    {
        if(arr[item]!=NULL)
            item=(item+1)%bucket;
        if(arr[item]==NULL)
        {
            arr[item]=data;
            break;
        }
    }
}

void hashing::display()
{
    for(int i=0;i<bucket;i++)
    {
        cout<<i<<"-->"<<arr[i]<<endl;
    }
}
int main()
{
   int a[]={15,8,11,17,5};
   int n=sizeof(a)/sizeof(a[0]);
   hashing h(7);
   for(int i=0;i<n;i++)
   {
       h.inserdata(a[i]);
   }
   h.display();
   return 0;
}
