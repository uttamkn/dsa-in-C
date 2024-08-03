#include "../analysis.c"

void swap(int *p, int *q) {
  int temp = *p;
  *p = *q;
  *q = temp;
}

int partition(int a[], int l, int r) {
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

void quickSort(int a[], int l, int r) {
  if (l < r) {
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
  }
}

int main() {
  sort_analysis2(quickSort);
  return 0;
}
