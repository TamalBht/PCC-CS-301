#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int low,int mid,int high){
    //temporary array in which the elements will be stored in sorted mannerand then it will be copied into the original array
    int b[100];
    int i=low;
    int j=mid+1;
    int k= low;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            b[k++]=arr[i++];
        }else{
            b[k++]=arr[j++];
        }
    }
    //collecting the rest of the elements 
    while(i<=mid){
        b[k++]=arr[i++];
    }
    while(j<=high){
        b[k++]=arr[j++];
    }
    //copying the sorted elements back into the original array
    for(int x=low;x<=high;x++){
        arr[x]=b[x];
    }

}
void mergeSort(int high,int low,int arr[]){
    //if this condition is not given the it will be an infinite recursive loop
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(mid,low,arr);
        mergeSort(high,mid+1,arr);
        merge(arr,low,mid,high);

    }
}
void display(int arr[],int high){
    
    for(int i=0;i<=high;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int size;
    printf("Enter number of elements for the array: ");
    scanf("%d",&size);
    int arr[size-1];
    for(int i=0;i<size;i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    printf("YOur array: ");
    display(arr,size-1);
    mergeSort(size-1,0,arr);
    printf("\nsorted array");
    display(arr,size-1);
    return 0;
}