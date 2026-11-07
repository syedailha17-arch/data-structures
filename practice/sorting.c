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


/*INSERTION SORT */
int insertion(int arr[],int n){
    int total=0;
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
            total++;
        }
        arr[j+1]=key;
    }
    return total;
}

/*QUICK SORT */
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high){
    int piv=arr[low];
    int L=low+1;
    int R=high;
    while(L<=R){
        while(L<=high && arr[L]<piv)L++;
        while(R>low && arr[R]>piv)R--;
        if(L<=R){
            swap(&arr[L],&arr[R]);
            L++;
            R--;
        }
    }
    swap(&arr[low],&arr[R]);
    return R;
}
void quick(int arr[],int low,int high){
    if(low<high){
        int x=partition(arr,low,high);
        quick(arr,low,x-1);
        quick(arr,x+1,high);
    }}


/*MERGE SORT */
void merge(int arr[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[ub+1];
    while(i<=mid&& j<=ub){
        if(arr[i]<=arr[j]){
            b[k]=arr[i];
            i++;
        }
        else{
            b[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
              b[k]=arr[i];
              i++;
              k++;
        }      
    }
     for(int i = lb; i <=ub; i++) {
        arr[i] = b[i];
    }
}
void mergesort(int arr[],int lb, int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);        
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
    int crr[n];
    int drr[n];
    int err[n];
    printf("enter each element");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        err[i]=drr[i]=crr[i]=brr[i]=arr[i];
    }
    printf("array before sorting: ");
    printArray(arr,n);
    int x=bubblesort(arr,n);
    printf("array after sorting: ");
    printf("no. of swaps: %d\n",x);
    printArray(arr,n);
    selection(brr,n);
    printf("after selection sort: ");
    printArray(brr,n);
    int y=insertion(crr,n);
    printf("after insertion sort: ");
    printArray(crr,n);
    printf("no of swaps: %d",y);
    quick(drr,0,n-1);
    printf("Array after quick sort:\n ");
    printArray(drr,n);
    mergesort(err,0,n-1);
    printf("Array after merge sort:\n");
    printArray(err,n);

    return 0;
}