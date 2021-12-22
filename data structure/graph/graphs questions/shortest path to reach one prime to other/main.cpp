#include <iostream>
#include<list>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
class Graph
{
    int V;
    list<int> *l;
public:
    Graph(int v)
    {
        V=v;
        l=new list<int>[V];
    }
    int BFS(int ,int);
    int compare(int,int);
    void addEdge(int u,int v);
};
void Graph::addEdge(int u,int v)
{
    l[u].push_back(v);
    l[v].push_back(u);
}
void sieveoferatosthenes(vector<int> &v)
{
     int n = 9999;
      bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(int p=2; p*p<=n;p++)
    {
        if(prime[p]==true)
        {
            for(int i=2; p*i<=n; i++)
                prime[p*i]=false;
        }
    }
    for(int i=1000;i<=n;i++)
    {
        if(prime[i])
        v.push_back(i);
    }
  }
int Graph::compare(int num1,int num2)
{
    string s1=to_string(num1);
    string s2=to_string(num2);
    int c=0;
    if(s1[0]!=s2[0])
        c++;
    if(s1[1]!=s2[1])
        c++;
    if(s1[2]!=s2[2])
        c++;
    if(s1[3]!=s2[3])
        c++;

    return (c==1);
}
int Graph::BFS(int n1,int n2)
{
    int visited[V];
    memset(visited,0,sizeof(visited));
    visited[n1]=1;
    queue<int>qu;
    qu.push(n1);
    list<int>::iterator i;
    while(!qu.empty())
    {
        int s=qu.front();
        qu.pop();
        for(i=l[s].begin();i!=l[s].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i]=visited[s]+1;
                qu.push(*i);
            }
            if(*i==n2)
                return visited[*i]-1;
        }
    }
}
int shortestpath(int num1,int num2)
{
    vector<int>pset;
    sieveoferatosthenes(pset);

    Graph g(pset.size());

    for(int i=0;i<pset.size();i++)
    {
        for(int j=i+1;j<pset.size();j++)
        {
            if(g.compare(pset[i],pset[j]))
                g.addEdge(i,j);
        }
    }

    int n1,n2;
    for(int i=0;i<pset.size();i++)
    {
        if(pset[i]==num1)
            n1=i;
        if(pset[i]==num2)
            n2=i;
    }
    return g.BFS(n1,n2);
}
int main()
{
    int num1=1033,num2=8179;
    cout<<"\nshortest path is:"<<shortestpath(num1,num2);
    return 0;
}
