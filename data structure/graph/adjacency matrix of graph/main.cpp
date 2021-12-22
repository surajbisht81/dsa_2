#include <iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

class adj
{
public:
    int num,i,j;
    int graph[10][10];
public:
    void in();
    void out();
};

void adj ::in()
{
    cout<<"\nenter the no of nodes:";
    cin>>num;
    //for undirected graph and no cycle in graph;
  /*  for(i=0;i<num;i++)
    {
        graph[i][i]=0;
        for(j=i+1;j<num;j++)
        {
            cout<<"\nenter the value of edge from node "<<i<<"to"<<j<<"->";
            cin>>graph[i][j];
            graph[j][i]=graph[i][j];
        }
    }*/
    //for directed graph having cycles;
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            cout<<"\nenter the value of edge from node "<<i<<"to"<<j<<"->";
            cin>>graph[i][j];
        }
    }
}
void adj::out()
{
    cout<<"\nadjacency matrix of graph is:\n\n";
    for(i=0;i<num;i++)
    {
        cout<<endl;
        cout<<(char)179;
        for(j=0;j<num;j++)
        {
            cout<<" "<<graph[i][j];
        }
        cout<<" "<<(char)179;
    }
}
int main()
{
    adj ad;
    ad.in();
    ad.out();
    getch();
    return 0;
}
