#include <bits/stdc++.h>
using namespace std;

class Edge
{
    public:
    int src, dst, weight;
};

class Graph
{
    public:
    int V, E;

    Edge *edge;
};

class subset
{
    public:
    int parent, rank;
};
Graph* creategraph(int v, int e)
{
    Graph *graph = new Graph;
    graph->E=e;
    graph->V=v;

    graph->edge=new Edge[e];
    return graph;
}

int Find(subset subs[], int i)
{
    if(subs[i].parent==i)
        return subs[i].parent;

    return subs[i].parent=Find(subs, subs[i].parent);
}

void Union(subset subs[], int i, int j)
{
    i = Find(subs, i);
    j = Find(subs, j);

    if(subs[i].rank<subs[j].rank)
        subs[i].parent=j;
    else if(subs[j].rank<subs[i].rank)
        subs[j].parent=i;
    else
    {
        subs[i].parent=j;
        subs[j].rank +=1;
    }
}

int Comp(const void *a, const void *b)
{
    Edge *a1 = (Edge*) a;
    Edge *a2 = (Edge*) b;
    return a1->weight > a2->weight;
}
void KruskalMST(Graph* graph)
{
    int V = graph->V;
    int E = graph->E;
    Edge result[V];
    int e=0, i=0;

    subset *subs = new subset[V*sizeof(subset)];
    for(int i=0; i<V; i++)
    {
        subs[i].parent=i;
        subs[i].rank=0;
    }

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), Comp);

    while(e<V-1 and i<E)
    {
        Edge next_edge = graph->edge[i++];

        int x = Find(subs, next_edge.src);
        int y = Find(subs, next_edge.dst);

        if(x!=y)
        {
            result[e++]=next_edge;
            Union(subs, x, y);
        }
    }

    cout<<"\n edges in MST is:\n";
    for(int i=0; i<e; i++)
    {
        cout<<result[i].src<<"----"<<result[i].dst<<"-->"<<result[i].weight;
        cout<<endl;
    }
}

int main()
{
   int V=4, E=5;

   Graph* graph = creategraph(V, E);

   graph->edge[0].src=0;
   graph->edge[0].dst=1;
   graph->edge[0].weight=10;

    graph->edge[1].src = 0;
    graph->edge[1].dst = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dst = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dst = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dst = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}
