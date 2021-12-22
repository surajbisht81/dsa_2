#include <bits/stdc++.h>
using namespace std;
const int MAX=100;

void dfs(int i, int j, int adj[][MAX], int M, int N, bool visit[][MAX])
{
    visit[i][j]=true;

    //down
    if(adj[i][j]>=adj[i+1][j] && i+1<=N && !visit[i+1][j])
        dfs(i+1, j, adj, M, N, visit);
    // up
    if(adj[i][j]>=adj[i-1][j] && i-1>=0 && !visit[i-1][j])
        dfs(i-1, j, adj, M, N, visit);
    //left
    if(adj[i][j]>=adj[i][j-1] && j-1>=0 && !visit[i][j-1])
        dfs(i, j-1, adj, M, N, visit);
    //right
    if(adj[i][j]>=adj[i][j+1] && j+1<=M && !visit[i][j+1])
        dfs(i, j+1, adj, M, N, visit);
}
void printminSRC(int adj[][MAX], int M, int N)
{
    vector<pair<int, pair<int, int>>>x;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            x.push_back(make_pair(adj[i][j], make_pair(i, j) ) );
        }
    }
    sort(x.begin(), x.end());

    bool visit[N][MAX];
    memset(visit, false, sizeof(visit));

    for(int i=x.size()-1; i>=0; i--)
    {
        if(!visit[x[i].second.first][x[i].second.second])
        {
            cout<<x[i].second.first<<" "<<x[i].second.second<<endl;
            dfs(x[i].second.first, x[i].second.second, adj, M, N, visit);
        }
    }
}
int main()
{
    int N=3, M=3;
    int adj[N][MAX] = {{1, 2, 3},
                      {2,3, 1},
                      {1, 1, 1}};
    printminSRC(adj, M, N);
    return 0;
}
