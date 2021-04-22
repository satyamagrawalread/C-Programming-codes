#include <stdio.h>
#define V 9

#include <time.h>

int minDistance(int *dist, int *sptSet)
{
    int min = __INT_MAX__, minIndex;
    for (int v = 0; v < V; v++)
    {
        if (dist[v] < min && !sptSet[v])
        {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printSolution(int *dist, int *sptSet)
{
    printf("Vertex \t minDistance \t sptSet\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t %10d \t %d\n", i, dist[i], sptSet[i]);
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    int sptSet[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = __INT_MAX__;
        sptSet[i] = 0;
    }
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != __INT_MAX__ && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
        printSolution(dist, sptSet);
    }
    printSolution(dist, sptSet);
}

int main(int argc, char const *argv[])
{
    int src, graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                            {4, 0, 8, 0, 0, 0, 0, 11, 0},
                            {0, 8, 0, 7, 0, 4, 0, 0, 2},
                            {0, 0, 7, 0, 9, 14, 0, 0, 0},
                            {0, 0, 0, 9, 0, 10, 0, 0, 0},
                            {0, 0, 4, 14, 10, 0, 2, 0, 0},
                            {0, 0, 0, 0, 0, 2, 0, 1, 6},
                            {8, 11, 0, 0, 0, 0, 1, 0, 7},
                            {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    // int graph[V][V] = {{0, 2, 6, 0, 0, 0, 0},
    //                    {2, 0, 0, 5, 0, 0, 0},
    //                    {6, 0, 0, 8, 0, 0, 0},
    //                    {0, 5, 8, 0, 10, 15, 0},
    //                    {0, 0, 0, 10, 0, 6, 2},
    //                    {0, 0, 0, 15, 6, 0, 6},
    //                    {0, 0, 0, 0, 2, 6, 0}};

    // for (int row = 0; row < V; row++)
    // {
    //     for (int col = 0; col < V; col++)
    //     {
    //         scanf("%d", graph[row][col]);
    //     }
    // }

    printf("Enter Source Vertex : ");
    scanf("%d", &src);
    dijkstra(graph, src);

    return 0;
}
