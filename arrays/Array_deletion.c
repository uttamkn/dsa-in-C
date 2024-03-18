#include <stdio.h>

void disp(int arr[],int size);
int indDeletion(int arr[],int size,int index,int capacity);

int main()
{
   int arr[40]={1,2,3,4,5};
   int size=5,index;

   disp(arr,size);

   printf("Enter the index to be deleted: ");
   scanf("%d",&index);

   int res=indDeletion(arr,size,index,100);

   if(res==1){
   size-=1;
   disp(arr,size);
   }
   else{
    printf("Invalid Index!\n");
   }

   return 0;

}

void disp(int arr[],int size)
{
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int indDeletion(int arr[],int size,int index,int capacity)
{
    if(index>capacity-1){
        return -1;
    }
    else {
        int i;
    for(i=index;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    arr[i]=0;
    return 1;
    }
}