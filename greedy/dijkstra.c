#include <stdio.h>
#include <stdlib.h>

#define INFINITY 9999
#define MAX 10

void dijkstra(int **graph, int n, int start) {
  int cost[MAX][MAX], distance[MAX], visited[MAX];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (graph[i][j] == 0) {
        cost[i][j] = INFINITY;
      } else {
        cost[i][j] = graph[i][j];
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    distance[i] = cost[start][i];
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  int count = 1;

  while (count < n - 1) {
    int mindistance = INFINITY, nextNode;

    for (int i = 0; i < n; ++i) {
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextNode = i;
      }
    }

    visited[nextNode] = 1;

    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        if (mindistance + cost[nextNode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextNode][i];
        }
      }
    }
    count++;
  }

  for (int i = 0; i < n; ++i) {
    if (i != start) {
      printf("distance from source to %d: %d\n", i, distance[i]);
    }
  }
}

int main() {
  int **graph, i, j, n, u;

  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  graph = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    graph[i] = (int *)malloc(n * sizeof(int));
  }

  printf("Enter the adjacency matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  u = 0;

  dijkstra(graph, n, u);

  for (i = 0; i < n; i++) {
    free(graph[i]);
  }
  free(graph);

  return 0;
}
