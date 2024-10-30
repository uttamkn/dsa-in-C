#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int size;
  int capacity;
} Priority_queue;

// max-heap related functions
void swap(int *node1, int *node2) {
  if (!node1 || !node2)
    return;

  int temp = *node1;
  *node1 = *node2;
  *node2 = temp;
}

void bubbleup_heapify(int *arr, int index) {
  while (index > 0) {
    int parent = (index - 1) / 2;

    if (arr[parent] >= arr[index])
      return;

    swap(arr + index, arr + parent);
    index = parent;
  }
}

// Using recursion (This is less efficient because of more stack space usage)
/* void bubbleup_heapify(int *arr, int index) { */
/*   if (index <= 0) */
/*     return; */
/*   int parent = (index - 1) / 2; */
/**/
/*   if (arr[parent] >= arr[index]) */
/*     return; */
/**/
/*   swap(arr + index, arr + parent); */
/**/
/*   bubbleup_heapify(arr, parent); */
/* } */

// priority queue operations
Priority_queue *priority_queue(int capacity) {
  if (capacity < 0) {
    printf("Capacity cant be negative\n");
    return NULL;
  }

  Priority_queue *newQ = malloc(sizeof(Priority_queue));
  newQ->size = 0;
  newQ->capacity = capacity;
  newQ->data = malloc(capacity * sizeof(int));
  return newQ;
}

void push(Priority_queue *pq, int val) {
  if (!pq) {
    printf("priority_queue was not initialized properly");
    return;
  }

  if (pq->size == pq->capacity) {
    printf("The priority queue is full\n");
    return;
  }

  pq->data[pq->size++] = val;

  bubbleup_heapify(pq->data, pq->size - 1);
}
