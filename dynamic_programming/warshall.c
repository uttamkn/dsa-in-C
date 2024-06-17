#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void warshall(int **graph, int n) {
    for (int k=0; k < n; k++) {
        for (int i=0; i < n; i++) {
            for (int j=0; j < n; j++) {
                if(graph[i][j] || graph[i][k] && graph[k][j]) graph[i][j]=1;
            }
        }
    }
}

int main() {
    int n = 5;
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i=0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    srand(time(0));
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            graph[i][j] = rand() % 2;
        }
    }

    printf("Original graph:\n");
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    warshall(graph, n);

    printf("Transitive closure:\n");
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}