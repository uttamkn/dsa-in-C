#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, extra=0;
    printf("enter the number of students: ");
    scanf("%d", &n);

    float *students=(float*)malloc(n*sizeof(float));
    for(int i=0; i<n; i++) {
        printf("enter the marks of student %d: ", i+1);
        scanf("%f", students+i);
    }

    char userin;
    printf("\nDo you want to allocate more space? (y/n)\n");
    scanf(" %c", &userin);

    if(userin=='y') {
        printf("\nenter the amount of extra space to be added: ");
        scanf("%d", &extra);
        students=(float*)realloc(students, (n+extra)*sizeof(float));

        for(int i=n; i<n+extra; i++) {
            printf("\nenter the marks of student %d: ", i+1);
            scanf("%f", students+i);
        }
    }

    printf("==========student marks=============\n");

    for(int i=0; i<n+extra; i++) {
        printf("student %d: %.2f\n", i+1, students[i]);
    }
}