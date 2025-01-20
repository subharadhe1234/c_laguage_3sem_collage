#include<stdio.h>
#include<stdlib.h>

int l_child(int i){
    return (2*i)+1;
}
int r_child(int i){
    return (2*i)+2;
}
int parent(int i){
    return (i-1)/2;
}

void swap(int* a, int * b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapyfy(int *arr,int n,int i){
    int largest=i;
    int left=l_child(i);
    int right= r_child(i);

    if(n>left && arr[largest]<arr[left]){
        largest=left;
    }
    if(n>right && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);

        heapyfy(arr,n,largest);
    }
}

void Buid_Max_Heap(int *arr,int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapyfy(arr,n,i);
    }
}

int  remove_max(int *arr, int n){
    swap(&arr[0],&arr[n-1]);
    n=n-1;
    heapyfy(arr,n-1,0);
    return n;
}

// heapsort
void heapsort(int *arr, int n ){
    for(int i=n-1;i>=1;i--){
        swap(&arr[0],&arr[i]);
        heapyfy(arr,i,0);
    }
}

void print_heap(int *arr,int n){
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={8,5,1,6,4,9,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int n1=n;
    
    printf("Original array:\n");
    print_heap(arr, n);
    Buid_Max_Heap(arr,n);
    print_heap(arr, n);
    // n1=remove_max(arr,n1);
    heapsort(arr,n);
    print_heap(arr,n);
    
}