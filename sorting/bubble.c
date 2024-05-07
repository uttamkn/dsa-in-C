#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
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
        bubbleSort(a, n);
        clock_t end=clock();
        double total_time=(double)(end-start)/CLOCKS_PER_SEC;
        printf("\nSize: %d\ntime taken: %lf\n", n, total_time);
    }
}

void main() {
    evaluate();
}