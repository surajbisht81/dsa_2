#include <iostream>
#include<vector>

using namespace std;
class adj
{
public:
    int vertex;
    vector<int> *arr;
    adj(int v)
    {
        vertex=v;
        arr= new vector<int>[vertex];
    }
    void addlist(int u,int v);
    void displaylist();
};
void adj ::addlist(int u,int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}
void adj ::displaylist()
{
    vector<int>::iterator it;
    for(int i=0;i<vertex;i++)
    {
        cout<<i;
        for(auto x:arr[i])
        {
            cout<<"-->"<<x;
        }
        cout<<endl;
    }
}

int main()
{
    adj ad(4);
    ad.addlist(0, 1);
    ad.addlist(0, 4);
    ad.addlist(1, 2);
    ad.addlist(1, 3);
    ad.addlist(1, 4);
    ad.addlist(2, 3);
    ad.addlist(3, 4);
    ad.displaylist();
    return 0;
}
