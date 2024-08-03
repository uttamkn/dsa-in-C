#include "../analysis.c"
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int n, int root) {
  int largest = root, left = 2 * root + 1, right = 2 * root + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != root) {
    swap(arr + root, arr + largest);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {

  for (int i = n / 2 - 1; i >= 0; --i)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; --i) {
    // swap the root with the last element
    swap(arr, arr + i);

    // heapify every element except the last one
    heapify(arr, i, 0);
  }
}

void printArr(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[] = {9, 28, 3, 19};
  int n = sizeof(arr) / sizeof(arr[0]);

  sort_analysis(heapSort);
  return 0;
}
