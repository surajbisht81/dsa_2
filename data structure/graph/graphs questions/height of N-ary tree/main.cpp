#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<list>
using namespace std;

int addEdge(int parent[],vector<int>adj[],int n)
{
    int root_index;
    for(int i=0;i<n;i++)
    {
        if(parent[i]==-1)
            root_index=i;
        else
        { adj[parent[i]].push_back(i);
          adj[i].push_back(parent[i]);
        }
    }
    return root_index;
}
void printlist(vector<int>adj[],int n)
{
    cout<<"\nlist is:\n";
    vector<int>::iterator it;
    for(int i=0;i<n;i++)
    {
        cout<<i;
        for(it=adj[i].begin();it!=adj[i].end();it++)
        {
            cout<<"-->"<<*it;
        }
        cout<<endl;
    }
}
int BFS(vector<int>adj[],int root_index,int n)
{
    int height=1;
    list<int>qu;
    //vector<int>::iterator i;
    qu.push_back(root_index);
    vector<bool> visit(n,false);
    visit[root_index]=true;
    int level[n]={0};
    level[root_index]=1;
    while(!qu.empty())
    {
        int s=qu.front();
        qu.pop_front();
        for(int i=0;i<n;i++)
         {

            for(auto it=adj[s].begin();it!=adj[s].end();it++)
             {
                 if(!visit[*it])
                 {
                     visit[*it]=true;
                     level[*it]=level[s]+1;

                 }
             }
             if(level[i]==height)
             height++;
         }
    }
    return height;
}
int main()
{
    int parent[] = { -1, 0, 1, 2, 3 };
    int n=sizeof(parent)/sizeof(parent[0]);
    vector<int>adj[n];
    int root_index=addEdge(parent,adj,n);
    printlist(adj,n);
    int height=BFS(adj,root_index,n);
    cout<<"\nheight="<<height;
    return 0;
}
