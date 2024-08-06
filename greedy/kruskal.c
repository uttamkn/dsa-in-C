#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct {
  int u, v, w;
} edge;

typedef struct {
  edge data[MAX];
  int n;
} edge_list;

edge_list elist;
edge_list spanlist;

void kruskal(int **graph, int numVerts);
int find(int belongs[], int vertex);
void applyUnion(int belongs[], int c1, int c2, int n);
void sort();
void print();

void kruskal(int **graph, int numVerts) {
  int belongs[numVerts];
  elist.n = 0;

  for (int i = 1; i < numVerts; i++) {
    for (int j = 0; j < i; j++) {
      if (graph[i][j] != 0) {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = graph[i][j];
        elist.n++;
      }
    }
  }

  sort();

  for (int i = 0; i < numVerts; i++) {
    belongs[i] = i;
  }

  spanlist.n = 0;
  int cno1, cno2;

  for (int i = 0; i < elist.n; i++) {
    cno1 = find(belongs, elist.data[i].u);
    cno2 = find(belongs, elist.data[i].v);

    if (cno1 != cno2) {
      spanlist.data[spanlist.n] = elist.data[i];
      spanlist.n++;
      applyUnion(belongs, cno1, cno2, numVerts);
    }
  }
}

int find(int belongs[], int vertex) { return (belongs[vertex]); }

void applyUnion(int belongs[], int c1, int c2, int n) {
  for (int i = 0; i < n; i++) {
    if (belongs[i] == c2) {
      belongs[i] = c1;
    }
  }
}

void sort() {
  edge temp;
  for (int i = 0; i < elist.n; i++) {
    for (int j = 0; j < elist.n - 1 - i; j++) {
      if (elist.data[j].w > elist.data[j + 1].w) {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
    }
  }
}

void print() {
  int cost = 0;
  for (int i = 0; i < spanlist.n; i++) {
    printf("\n%d-%d:%d", spanlist.data[i].u, spanlist.data[i].v,
           spanlist.data[i].w);
    cost += spanlist.data[i].w;
  }

  printf("\nCost: %d", cost);
}

int main() {
  int numVerts;
  int **graph;
  printf("numverts: ");
  scanf("%d", &numVerts);

  graph = (int **)malloc(numVerts * sizeof(int *));

  for (int i = 0; i < numVerts; i++) {
    graph[i] = (int *)malloc(numVerts * sizeof(int));
  }

  printf("adj mat");
  for (int i = 0; i < numVerts; i++) {
    for (int j = 0; j < numVerts; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  kruskal(graph, numVerts);
  print();
}
