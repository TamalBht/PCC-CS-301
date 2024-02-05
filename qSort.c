#include<stdio.h>
#include<stdlib.h>
void swap(int* x,int* y){
    int temp= *x;
    *x=*y;
    *y=temp;
}
int place(int arr[],int low,int high){
    int i=low,j=high;
    //the main purpose of this function is to put pivot element into the index where it would be if the array was sorted and then the pivot elemment acts as a wall right to which there numbers that are greater than the pivot and left-><pivot
    //assuming the arr[low] as the index if any element is found to be less than arr[low]then it is swapped
    int pivot=arr[low];
    //there are two pointers :1 pointing at the front and the other pointing at the back
    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }
        while(arr[j]>pivot &&j>low){
            j--;
        }
        //we'll exit this loop only when a number <pivot is present in the right side of the pivot so we swap the pivot and number
        if(i<j){
            swap(&arr[i],&arr[j]);
        }

    }
    //and in the end the final swapping is done
    swap(&arr[low],&arr[j]);
    return j;//returns the index number where the element should exist if it was sorted
}
void qs(int arr[],int low,int high){

    if(low<high){
        int pIndex=place(arr,low,high);//to get the index of the first element in the sorted array

        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);

    }
}
void print(int arr[],int high){
    for(int i=0;i<=high;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={9,8,7,6,5,4,3,2,1,0};
    print(arr,9);
    qs(arr,0,9);
    print(arr,9);
    return 0;
}