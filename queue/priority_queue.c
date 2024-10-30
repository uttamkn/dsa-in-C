#include <stdio.h>

typedef struct priority_queue {
  int *data;
  int size;
  int capacity;
} priority_queue;

void swap(int *node1, int *node2) {
  if (!node1 || !node2)
    return;

  int temp = *node1;
  *node1 = *node2;
  *node2 = temp;
}

void heapify(int *root) {}

void insert_node(int *root) {}

void push(priority_queue *pq, int val) {
  if (pq->size == pq->capacity) {
    printf("The priority queue is full\n");
    return;
  }
}
