#include "priority_queue.h"
#include <stdio.h>

int main() {
  Priority_queue *pa = priority_queue(4);
  push_pq(pa, 1);
  push_pq(pa, 2);
  push_pq(pa, 3);
  push_pq(pa, 4);
  print_pq(pa);
  pop_pq(pa);
  print_pq(pa);
  pop_pq(pa);
  print_pq(pa);
  printf("front: %d\n", front_pq(pa));
  printf("size: %d\n", size_pq(pa));
  printf("isEmpty: %d\n", isEmpty_pq(pa));
  pop_pq(pa);
  pop_pq(pa);
  printf("isEmpty: %d\n", isEmpty_pq(pa));
  pop_pq(pa);
  free_pq(pa);
}
