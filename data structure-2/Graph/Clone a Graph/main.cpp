#include <bits/stdc++.h>
using namespace std;

struct Graphnode
{
    int val;

    vector<Graphnode*> neighbour;
};

Graphnode *build()
{
    /* 1--2
        | |
        4--3 */
    Graphnode *node1 = new Graphnode;
    node1->val=1;
    Graphnode *node2 = new Graphnode;
    node2->val=2;
    Graphnode *node3 = new Graphnode;
    node3->val=3;
    Graphnode *node4 = new Graphnode;
    node4->val=4;

    vector<Graphnode*> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbour=v;
    v.clear();

    v.push_back(node1);
    v.push_back(node3);
    node2->neighbour=v;
    v.clear();

    v.push_back(node2);
    v.push_back(node4);
    node3->neighbour=v;
    v.clear();

    v.push_back(node1);
    v.push_back(node3);
    node4->neighbour=v;
    v.clear();

    return node1;
}

Graphnode *clone(Graphnode *src)
{
    map<Graphnode*, Graphnode*> mp;

    Graphnode *node = new Graphnode;
    node->val = src->val;
    mp[src] = node;

    queue<Graphnode*> qu;
    qu.push(src);

    while(!qu.empty())
    {
        Graphnode *p = qu.front();
        qu.pop();

        vector<Graphnode*> v = p->neighbour;
        int n = v.size();
        for(int i=0; i<n; i++)
        {
            if(mp[v[i]]==NULL)
            {
                Graphnode *node1 = new Graphnode;
                node1->val = v[i]->val;
                mp[v[i]]=node1;
                qu.push(v[i]);
            }
            mp[p]->neighbour.push_back(mp[v[i]]);
        }
    }
    return mp[src];
}

void BFS(Graphnode *src)
{
    queue<Graphnode*> qu;
    map<Graphnode*, bool> visit;

    qu.push(src);
    visit[src]=true;

    while(!qu.empty())
    {
        Graphnode *p = qu.front();
        cout<<"value of node:"<<p->val<<endl;
        cout<<"value of address:"<<p<<endl;
        qu.pop();

        vector<Graphnode*> v = p->neighbour;
        int n = v.size();
        for(int i=0; i<n; i++)
        {
            if(!visit[v[i]])
            {
                visit[v[i]]=true;
                qu.push(v[i]);
            }
        }
    }
    cout<<endl;
}

int main()
{
   Graphnode *src = build();
   cout<<"\noriginal Graph:\n";
   BFS(src);

   Graphnode *cloneNode = clone(src);

   cout<<"\nclone Graph is :\n";
   BFS(cloneNode);
   return 0;
}
