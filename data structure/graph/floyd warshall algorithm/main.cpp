#include <iostream>

using namespace std;
const int V=4;
#define INF 99999

void printfloyddist(int dist[V][V])
{
    cout<<"\ndistance of all pair vertices:\n";
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(dist[i][j]==INF)
                 cout<<"\t"<<"INF";
            else
            cout<<"\t"<<dist[i][j];
        }
        cout<<endl;
    }
}
void floydwarshall(int graph[V][V])
{
    int dist[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            dist[i][j]=graph[i][j];
        }
    }

    //update this distance according to the intermediate node or vertex;
    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    printfloyddist(dist);
}

int main()
{

  /*         10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3*/
    int graph[V][V]={   {0,5,INF,10}
                       ,{INF,0,3,INF}
                       ,{INF,INF,0,1}
                       ,{INF,INF,INF,0}};

    floydwarshall(graph);
    return 0;
}
