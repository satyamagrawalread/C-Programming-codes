#include<stdio.h>
#include<conio.h>

int find_min(int *cost, int *visited, int V)
{
    int index_min=0;
    int cost_copy[V];
    for(int i=0;i<V;i++)
    {
        cost_copy[i]=cost[i];
        if(visited[i]==1)
        {
            cost_copy[i]=1000;
        }
    }
    for(int i=1;i<V;i++)
    {
        if(cost_copy[index_min]>cost_copy[i])
        {
            index_min = i;
        }
    }
    return index_min;
}

void Dijkstra_algo(int V, int Graph[][V], int Weight[][V], int source)
{
    int cost[V];
    int visited[V];
    for(int i=0;i<V;i++)
    {
        cost[i]=1000;
        visited[i]=0;
    }
    cost[source-1]=0;

    for(int i=0;i<V;i++)
    {
        if(Graph[source-1][i]==1)
        {
            if(cost[source-1]+Weight[source-1][i] < cost[i])
            {
                cost[i] = cost[source-1]+Weight[source-1][i];
            }
        }
    }
    printf("Cost of each vertices from source vertex %d during 1st iteration: ", source);
    for(int i=0;i<V;i++)
    {
        printf("%d ", cost[i]);
    }
    printf("\n");
    
    visited[source-1]=1;
    int k=V-1;//For the remaining vertices
    int index_min;
    while(k--)
    {
        index_min = find_min(cost, visited, V);
        visited[index_min]=1;
        for(int i=0;i<V;i++)
        {
            if(Graph[index_min][i]==1)
            {
                if(cost[index_min] + Weight[index_min][i] < cost[i])
                {
                    cost[i] = cost[index_min] + Weight[index_min][i];
                }
            }
        }
        printf("Cost of each vertices from vertex %d during %dst iteration: ", index_min+1, V-k);
        for(int i=0;i<V;i++)
        {
            printf("%d ", cost[i]);
        }
        printf("\n");
    }
}


int main(int argc, char const *argv[])
{
    const int V;
    printf("Enter the no. of vertices: ");
    scanf("%d", &V);
    int Graph[V][V];
    int Weight[V][V];
    int cost;
    int input;

    //Initialization of Graph and Weight element
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            Graph[i][j]=0;
            Weight[i][j]=0;
        }
    }

    int n;

    for(int i=0;i<V;i++)
    {
        printf("Enter the no. of Vertices connected to vertex %d: ", i+1);
        scanf("%d", &n);
        printf("Enter the vertices directed from vextex %d along with their weight\n", i+1);

        while(n--)
        {
            printf("Enter the %dth vertex and its weight: ", n+1);
            scanf("%d", &input);
            scanf("%d", &cost);
            Graph[i][input-1]=1;
            Weight[i][input-1]=cost;
        }
        printf("\n");
    }
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            printf("%d ", Graph[i][j]);
        }
        printf("\t\t\t");
        for(int j=0;j<V;j++)
        {
            printf("%d ", Weight[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    Dijkstra_algo(V, Graph, Weight, source);
    return 0;
}