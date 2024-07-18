#include <stdio.h>
#include <stdlib.h>

#define INFINITY 9999
#define MAX 10

// Function to implement Dijkstra's algorithm
void Dijkstra(int **Graph, int n, int start)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;

    // Creating cost matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (Graph[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = Graph[i][j];
            }
        }
    }

    // Initializing distance, pred, and visited arrays
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    // Main loop for Dijkstra's algorithm
    while (count < n - 1)
    {
        mindistance = INFINITY;

        // Find the next node with the smallest distance
        for (i = 0; i < n; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        // Update distances of the adjacent nodes
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }

    // Printing the distance from source to each vertex
    for (i = 0; i < n; i++)
    {
        if (i != start)
        {
            printf("\nDistance from source to %d: %d", i, distance[i]);
        }
    }
}

int main()
{
    int **Graph, i, j, n, u;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Allocate memory for the adjacency matrix
    Graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        Graph[i] = (int *)malloc(n * sizeof(int));
    }

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &Graph[i][j]);
        }
    }

    // Starting node for Dijkstra's algorithm
    u = 0;

    // Apply Dijkstra's algorithm
    Dijkstra(Graph, n, u);

    // Free the allocated memory
    for (i = 0; i < n; i++)
    {
        free(Graph[i]);
    }
    free(Graph);

    return 0;
}
