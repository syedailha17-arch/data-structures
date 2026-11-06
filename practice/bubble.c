#include<stdio.h>
/*BUBBLE SORT*/
int bubblesort(int arr[],int n){
    int temp;
    int total=0;
    for(int i=0;i<n-1;i++){
        int swap=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=1;
                total++;
            }
        }
        if(!swap)break;
    }
    return total;
}
/*SELECTION SORT*/
void selection(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIdx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx]){
                minIdx=j;

            }
            }
        if(minIdx!=i){
            int temp=arr[i];
            arr[i]=arr[minIdx];
            arr[minIdx]=temp;    
        }
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("enter no of elements");
    scanf("%d",&n);
    int arr[n];
    int brr[n];
    printf("enter each element");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        brr[i]=arr[i];
    }
    printf("array before sorting:");
    printArray(arr,n);
    int x=bubblesort(arr,n);
    printf("array after sorting");
    printf("no. of swaps:%d\n",x);
    printArray(arr,n);
    selection(brr,n);
    printf("after selection sort:");
    printArray(brr,n);
    return 0;
}