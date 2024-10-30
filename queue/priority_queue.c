#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int size;
  int capacity;
} Priority_queue;

// max-heap related functions
void _swap(int *a, int *b) {
  if (a != b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
}

void _bubbleup_heapify(int *arr, int index) {
  while (index > 0) {
    int parent = (index - 1) / 2;

    if (arr[parent] >= arr[index])
      return;

    _swap(arr + index, arr + parent);
    index = parent;
  }
}

// Using recursion (This is less efficient because of more stack space usage)
/* void _bubbleup_heapify(int *arr, int index) { */
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

void _topdown_heapify(int *arr, int size, int root) {
  int largest = root, left = 2 * root + 1, right = 2 * root + 2;

  if (left < size && arr[left] > arr[largest]) {
    largest = left;
  }

  if (right < size && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != root) {
    _swap(arr + root, arr + largest);
    _topdown_heapify(arr, size, largest);
  }
}

// priority queue operations

// priority_queue constructor (for creating a new priority queue)
Priority_queue *priority_queue(int capacity) {
  if (capacity < 0) {
    printf("Capacity cant be negative\n");
    return NULL;
  }

  Priority_queue *newQ = malloc(sizeof(Priority_queue));

  if (!newQ) {
    printf("Memory allocation failed\n");
    return NULL;
  }

  newQ->size = 0;
  newQ->capacity = capacity;
  newQ->data = malloc(capacity * sizeof(int));

  if (!newQ->data) {
    printf("Memory allocation failed while allocating data\n");
    free(newQ);
    return NULL;
  }

  return newQ;
}

// TODO: priority_queue copy constructor (for creating a new priority queue from
// an
//  existing one)
Priority_queue *copy_pq(Priority_queue *pq, int newCapacity) {}

// priority_queue destructor (for freeing the memory)
void free_pq(Priority_queue *pq) {
  if (pq) {
    free(pq->data);
    free(pq);
  }
}

void print_pq(Priority_queue *pq) {
  if (!pq || pq->size == 0) {
    printf("The priority queue is empty\n");
    return;
  }
  for (int i = 0; i < pq->size; i++) {
    printf("%d ", pq->data[i]);
  }
  printf("\n");
}

void push_pq(Priority_queue *pq, int val) {
  if (!pq) {
    printf("priority_queue was not initialized properly\n");
    return;
  }

  if (pq->size == pq->capacity) {
    printf("The priority queue is full\n");
    return;
  }

  pq->data[pq->size++] = val;

  _bubbleup_heapify(pq->data, pq->size - 1);
}

void pop_pq(Priority_queue *pq) {
  if (!pq) {
    printf("priority_queue was not initialized properly\n");
    return;
  }

  if (pq->size == 0) {
    printf("The priority queue is empty\n");
    return;
  }

  pq->data[0] = pq->data[--pq->size];
  _topdown_heapify(pq->data, pq->size, 0);
}

int front_pq(Priority_queue *pq) {
  if (!pq) {
    printf("priority_queue was not initialized properly\n");
    return 0;
  }

  if (pq->size == 0) {
    printf("The priority queue is empty\n");
    return 0;
  }

  return pq->data[0];
}

int size_pq(Priority_queue *pq) {
  if (!pq) {
    printf("priority_queue was not initialized properly\n");
    return 0;
  }

  return pq->size;
}

int isEmpty_pq(Priority_queue *pq) {
  if (!pq) {
    printf("priority_queue was not initialized properly\n");
    return 0;
  }

  return pq->size == 0;
}
