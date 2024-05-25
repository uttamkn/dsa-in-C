#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int binarySearch(int arr[], int size, int key) {
    int left = 0, i=0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = (right + left) / 2;
        i++;
        if (arr[mid] == key)
            return i;
        
        if (arr[mid] < key)
            left = mid + 1;
        
        else
            right = mid - 1;
    }
    
    return i;
}

void main() {
    int n, *a;
    printf("size: ");
    scanf("%d", &n);
    a=(int*)malloc(n*sizeof(int));
    for(int i=1; i<n; i++) {
        a[i]=i;
    }
    printf("comparisons if key is the first element: %d\n", binarySearch(a, n, a[0]));
    printf("comparisons if key is approx in middle: %d\n", binarySearch(a, n, a[(n-1)/2]));
    printf("comparisons if key not found: %d\n", binarySearch(a, n, a[n-1]));
}