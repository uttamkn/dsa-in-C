#include <stdio.h>

void disp(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int indInsert(int arr[], int size, int element, int index, int capacity) {
  if (size >= capacity) {
    return -1;
  } else {
    for (int i = size - 1; i >= index; i--) {
      arr[i + 1] = arr[i];
    }
    arr[index] = element;

    return 1;
  }
}

int sortIndex(int arr[], int size, int element) {
  for (int i = 0; i < size; i++) {
    if (arr[i] > element) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[100] = {2, 4, 5, 62, 78};
  int size = 5, index, element;

  disp(arr, size);

  printf("Enter the element to be inserted: ");
  scanf("%d", &element);
  printf(
      "Enter the index at which the element should be inserted: "); // comment
                                                                    // this for
                                                                    // sorted
                                                                    // insertion
  scanf("%d", &index);

  // sorted insertion (array should be sorted)
  //  index=sortIndex(arr,size,element); //uncomment for sorted insertion

  int res = indInsert(arr, size, element, index, 100);
  if (res == 1) {
    size += 1;
    disp(arr, size);
  } else {
    printf("Insertion Failed!\n");
  }

  return 0;
}
