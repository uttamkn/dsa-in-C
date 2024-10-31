#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct {
  int *data;
  int size;
  int capacity;
} Priority_queue;

Priority_queue *priority_queue(int capacity);
void free_pq(Priority_queue *pq);
Priority_queue *copy_pq(Priority_queue *pq, int newCapacity);
void print_pq(Priority_queue *pq);
void push_pq(Priority_queue *pq, int val);
void pop_pq(Priority_queue *pq);
int front_pq(Priority_queue *pq);
int size_pq(Priority_queue *pq);
int isEmpty_pq(Priority_queue *pq);

#endif
