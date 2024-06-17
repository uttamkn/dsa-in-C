#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void floyd (int **graph, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j =0; j < n; j++) {
                graph[i][j] = (graph[i][j] < graph[i][k] + graph[k][j]) ? graph[i][j] : (graph[i][k] + graph[k][j]);
            }
        }
    }
}

void printGraph(int **graph, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 3;
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % 10;
        }
    }

    printf("Original graph:\n");
    printGraph(graph, n);

    floyd(graph, n);

    printf("Shortest path:\n");
    printGraph(graph, n);

    return 0;
}