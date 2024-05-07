#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int min=i;
        for(int j=i+1; j<n; j++) {
            if(arr[j]<arr[min]) {
                min=j;
            }
        }
        
        if(min!=i) {
            int temp = arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}

void evaluate() {

    for(int n=1000; n<=10000; n+=1000) {
        int *a=(int*)malloc(n*sizeof(int));
    
        for(int k=0; k<n; k++) {
            int r=rand()%10000;
            a[k]=r;
        }

        clock_t start=clock();
        selectionSort(a, n);
        clock_t end=clock();
        double total_time=(double)(end-start)/CLOCKS_PER_SEC;
        printf("\nSize: %d\ntime taken: %lf\n", n, total_time);
    }
}

void main() {
    evaluate();
}