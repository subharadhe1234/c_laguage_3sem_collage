#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[]={8,5,1,6,4,9,3};
    int len=sizeof(arr)/sizeof(arr[0]);  
for (int i=1;i<len;i++){
    int j=i-1;
    int key=arr[i];
    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
} 

for (int i = 0; i < len; i++)
{
    printf("%d ", arr[i]);
}

    }