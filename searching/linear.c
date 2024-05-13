#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int linearSearch(int arr[], int n, int key) {
    int i;
    for(i=0; i<n; ++i) {
        if(arr[i]==key) return i;
    }
    return i;
}

void main() {
    int n, *a;
    printf("size: ");
    scanf("%d", &n);
    a=(int*)malloc(n*sizeof(int));
    for(int i=1; i<=n; i++) {
        a[i]=i;
    }

    printf("comparisons if key is approx in middle: %d\n", linearSearch(a, n, n/2));
    printf("comparisons if key not found: %d\n", linearSearch(a, n, n+1));
}