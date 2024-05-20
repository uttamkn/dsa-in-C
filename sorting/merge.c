#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high)
        return;
    int mid = ((low + high) / 2);
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void evaluate() {
    for (int n = 100000; n <= 1000000; n += 100000) {
        int *arr = (int *)malloc(n * sizeof(int));

        for (int k = 0; k < n; k++) {
            int r = rand() % 10000;
            arr[k] = r;
        }

        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
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
