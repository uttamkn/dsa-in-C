#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARGS 5

void sort_analysis(void (*_some_func)(int *, int)) {

  for (int n = 1000; n <= 10000; n += 1000) {
    int *a = (int *)malloc(n * sizeof(int));

    for (int k = 0; k < n; k++) {
      int r = rand() % 10000;
      a[k] = r;
    }

    clock_t start = clock();
    _some_func(a, n);
    clock_t end = clock();
    double total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nSize: %d\ntime taken: %lf\n", n, total_time);
  }
}

void sort_analysis2(void (*_some_func)(int *, int, int)) {
  for (int n = 100000; n <= 1000000; n += 100000) {
    int *arr = (int *)malloc(n * sizeof(int));

    for (int k = 0; k < n; k++) {
      int r = rand() % 10000;
      arr[k] = r;
    }

    clock_t start = clock();
    _some_func(arr, 0, n - 1);
    clock_t end = clock();
    double total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Size: %d, time taken: %lf seconds\n", n, total_time);

    free(arr);
  }
}
