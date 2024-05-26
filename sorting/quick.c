#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap (int *p, int*q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

int partition (int a[], int l, int r) {
    int i, j, pivot;
    pivot = a[l];
    i = l;
    j = r + 1;
    while (i < j) {
        i++;
        while (a[i] < pivot && i < r) {
            i++;
        }
        j--;

        while (a[j] > pivot && j > l) {
            j--;
        }

        swap(&a[i], &a[j]);
    }
    swap(&a[i], &a[j]);
    swap(&a[l], &a[j]);
    return j;
}

void quickSort (int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }    
}

void evaluate() {
    for (int n = 1000; n <= 10000; n += 1000) {
        int *arr = (int *)malloc(n * sizeof(int));

        for (int k = 0; k < n; k++) {
            int r = rand() % 10000;
            arr[k] = r;
        }

        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();
        double total_time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Size: %d, time taken: %lf seconds\n", n, total_time);

        free(arr);
    }
}

int main() {
    srand(time(NULL));
    evaluate();
    return 0;
}

