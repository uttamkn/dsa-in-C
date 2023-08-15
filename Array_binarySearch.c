#include <stdio.h>

int binarySearch(int arr[],int size,int element){
    int low=0,high=size-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==element){
            return mid;
        }
        else if(arr[mid]<element){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[]={1,23,45,64,87,122,223,444,654};
    int size=sizeof(arr)/sizeof(int);
    int element =64;                            //element to be found

    int index=binarySearch(arr,size,element);
    printf("%d Found at index %d",element,index);

    return 0;
}