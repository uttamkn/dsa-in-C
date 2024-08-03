#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

struct node {
  int data;
  struct node *next;
};

struct node *createNode(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void addEdge(struct node *adjList[], int u, int v) {
  struct node *newNode = createNode(v);
  newNode->next = adjList[u];
  adjList[u] = newNode;
}

void bfs(struct node *adjList[], int vertices, int source, int visited[]) {
  int queue[MAX_VERTICES];
  int f = 0, r = -1;
  visited[source] = 1;
  queue[++r] = source;

  // while queue is not empty
  while (f <= r) {
    int current = queue[f++];
    printf("%d ", current);

    struct node *temp = adjList[current];
    while (temp) {
      if (!visited[temp->data]) {
        visited[temp->data] = 1;
        queue[++r] = temp->data;
      }
      temp = temp->next;
    }
  }
}

int main() {
  int vertices = 5;
  struct node *adjList[vertices];
  int visited[vertices];
  int source = 0;

  for (int i = 0; i < vertices; i++) {
    visited[i] = 0;
    adjList[i] = NULL;
  }

  addEdge(adjList, 0, 1);
  addEdge(adjList, 0, 2);
  addEdge(adjList, 1, 3);
  addEdge(adjList, 1, 4);
  addEdge(adjList, 2, 4);

  printf("bfs traversal:\n");
  bfs(adjList, vertices, source, visited);
}
