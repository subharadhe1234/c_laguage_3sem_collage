#include<stdio.h>
#include<stdlib.h>

// find mejority element
int find_majority_element(int *arr,int n){
    int vote=0,candite=-1;
    for(int i=0;i<n;i++){
        if(vote==0){
            candite=arr[i];
            vote=1;
        }else{
            if(arr[i]==candite)vote++;
            else vote--;
            
        }
    }
    vote=0;
    // count the many time it occure
    for (int i=0;i<n;i++){
        if (arr[i]==candite) vote++;
    }
    if(vote>n/2) return 1; // if 1 the there ara an megority element if 0 there are no mejority element
    return 0; 


}

int main(){
    printf("radhe radhe\n");
    int arr[]={1,2,2,2,3,4,6,2,2,2,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("%d \n",find_majority_element(arr,size));
    
}