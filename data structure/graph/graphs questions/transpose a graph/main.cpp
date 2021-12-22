#include <iostream>
#include<list>

using namespace std;
const int v=5;
void addEdge(list<int>adj[],int u,int v)
{
    adj[u].push_back(v);
}
void transpose(list<int>adj[],list<int>reverse[])
{
    list<int>::iterator it;
    for(int i=0;i<v;i++)
    {
        for(it=adj[i].begin();it!=adj[i].end();it++)
        {
            addEdge(reverse,*it,i);
        }
    }
}
void printlist(list<int>adj[])
{
    list<int>::iterator i;
    for(int j=0;j<v;j++)
    {   cout<<j;
        for(i=adj[j].begin();i!=adj[j].end();i++)
        {
            cout<<"-->"<<*i;
        }
        cout<<endl;
    }
}
int main()
{
    list<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);
    cout<<"\nbefore transpose :\n";
    printlist(adj);
    list<int>reverse[v];
    cout<<"\nafter transpose :\n";
    transpose(adj,reverse);
    printlist(reverse);
    return 0;
}
