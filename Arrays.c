#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    //allocates the memory for these in stack 
    int total_size;
    int used_size;
    int* ptr;    
};

void createArray(struct myArray *a,int tSize, int uSize)
{
    //(*a).total_size = tSize;
    //(*a).used_size = uSize;
    //(*a).ptr = (int*)malloc(tSize*sizeof(int)); 

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int*)malloc(tSize*sizeof(int));   //allocates memory in heap and stores the address to that in struct
}

void setVal(struct myArray *a)
{
    int n;
    printf("Enter the values: ");

    for(int i=0;i< a->used_size;i++)
    {
        scanf("%d",&n);         //takes the values from the user
        (a->ptr)[i]=n;          //stores it in the array created
    }
}

void show(struct myArray *a)
{
    printf("the values in the array are: ");
    for(int i=0;i< a->used_size;i++)
    {
        printf("%d\t",(a->ptr)[i]);
    }
}

int main()
{
    struct myArray marks;           //creates struct in stack
    createArray(&marks, 10, 2);     //creates an array in heap and stores the pointer to that in struct
    setVal(&marks);                 //takes the input from the user
    show(&marks);                   //shows the values
    return 0;
}