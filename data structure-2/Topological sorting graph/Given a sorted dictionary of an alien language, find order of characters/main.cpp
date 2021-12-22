#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int v);
    void addEdge(int u, int v);
    void TopolocalUtil(stack<int> &st, int u, bool visit[]);
    void Topolocal();
};
Graph::Graph(int v)
{
    V=v;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::TopolocalUtil(stack<int> &st, int u, bool visit[])
{
   visit[u]=true;

   for(auto v=adj[u].begin(); v!=adj[u].end(); v++)
   {
       if(!visit[*v])
        TopolocalUtil(st, *v, visit);
   }
   st.push(u);
}

void Graph::Topolocal()
{
    stack<int> st;
    bool visit[V];
    memset(visit, false, sizeof(visit));

    for(int i=0; i<V; i++)
    {
        if(!visit[i])
            TopolocalUtil(st, i, visit);
    }

    while(!st.empty())
    {
        cout<<((char)('a'+st.top()))<<" ";
        st.pop();
    }
}
void printOrder(string words[], int n, int alpha)
{
    Graph g(alpha);

    for(int i=0; i<n-1; i++)
    {
        string word1=words[i], word2=words[i+1];

        for(int j=0; j<min(word1.length(), word2.length()); j++)
        {
            if(word1[j]!=word2[j])
              {
                g.addEdge(word1[j]-'a', word2[j]-'a');
                break;
              }
        }
    }
    g.Topolocal();
}
int main()
{
      string words[] = {"baa", "abcd", "abca", "cab", "cad"};
      int n=sizeof(words)/sizeof(words[0]);

      printOrder(words, n, 4);    // 4 is for the no of different characters in the words.
      return 0;
}
