#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

bool isDivBy3(int arr[], int n) {
    for(int i=0; i<n; i++) {
        if(arr[i]%3==0) return true;
    }
    return false;
}

long int arraySum(int arr[], int n){
    int sum=0;
    for(int i=0; i<n; i++) {
        sum+=arr[i];
    }
    return sum;
}

void decToRevbin(int dec) {
    int* rev_bin = (int*)malloc(32*sizeof(int));
    int i=0;
    while(dec>0) {
        rev_bin[i++]=dec%2;
        dec/=2;
    }

    for(int j=i-1; j>=0; j--) {   //printing the reversed value
        printf("%d", rev_bin[j]);
    }
}

void matrix() {
    int n;
    printf("give size of square matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("give the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand()%1000;
        }
    }

    printf("Even elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] % 2 == 0) {
                printf("%d\n", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void main() {
    int *a, n, r;
    clock_t start, end;
    double total_time;
    printf("n: ");
    scanf("%d", &n);

    a=(int*)malloc(n*sizeof(int));
    for(int k=0; k<n; k++) {
        r=rand()%10000;
        a[k]=r;
    }

    start=clock();
    matrix();
    end=clock();

    total_time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("time taken: %lf", total_time);

    // decToRevbin(153);
}