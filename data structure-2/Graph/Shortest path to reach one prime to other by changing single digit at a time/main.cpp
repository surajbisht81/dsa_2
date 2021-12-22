/*Given two four digit prime numbers, suppose 1033 and 8179, we need to find the shortest path from 1033 to 8179 by altering only single digit at a time such
 that every number that we get after changing a digit is prime. For example a solution is 1033, 1733, 3733, 3739, 3779, 8779, 8179*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:

    int V;
    list<int> *adj;
    Graph(int v);
    int DFS(int u, int v);
    void addEdge(int u, int v);
};

Graph::Graph(int v)
{
    V=v;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void sieveofE(vector<int> &v)
{
    int n=9999;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for(int i=2; i*i<=n; i++)
    {
        if(prime[i])
        {
            for(int j=i*i; j<=n; j=j+i)
                prime[j]=false;
        }
    }
    for(int i=1000; i<=n ;i++)
    {
        if(prime[i])
            v.push_back(i);
    }

}
int Graph::DFS(int u, int v)
{
    queue<int>qu;
    int visit[V];
    memset(visit, 0, sizeof(visit));

    visit[u]=1;
    qu.push(u);
    while(!qu.empty())
    {
        int p=qu.front();
        qu.pop();

        for(auto it=adj[p].begin(); it!=adj[p].end(); it++)
        {
            if(!visit[*it])
            {
                visit[*it]=visit[p]+1;
                qu.push(*it);
            }
            if(*it==v)
                return visit[*it]-1;
        }
    }
}
bool compare(int x , int y)
{
    int c=0;
    string s1 = to_string(x);
    string s2 = to_string(y);

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
int shortestPath(int num1, int num2)
{
    vector<int> psum;
    sieveofE(psum);

    Graph g(psum.size());

    for(int i=0;i<psum.size(); i++)
    {
        for(int j=i+1; j<psum.size(); j++)
        {
            if(compare(psum[i], psum[j]))
                g.addEdge(i, j);
        }
    }

    int x, y;
    for(int j=0;j<psum.size(); j++)
        if(psum[j]==num1)
         x=j;
    for(int j=0;j<psum.size(); j++)
        if(psum[j]==num2)
         y=j;
    return g.DFS(x, y);
}
int main()
{
    int num1 = 1033;
    int num2 = 8179;

    cout<<shortestPath(num1, num2);
    return 0;
}
