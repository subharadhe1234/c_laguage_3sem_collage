#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int comparation=0;
void print_arr(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void concure(int *arr,int mid,int left, int right){
    int l=mid+1-left;
    int r=right-mid;
    int *left_arr= malloc(sizeof(int)*l); 
    int *right_arr= malloc(sizeof(int)*r);

    for(int i=0;i<l;i++) left_arr[i]=arr[left+i];
    for(int i=0;i<r;i++) right_arr[i]=arr[1+i+mid];

    int i=0,j=0,k=left;
    while (i<l && j<r){
        if(left_arr[i]<=right_arr[j]){ arr[k++]=left_arr[i++];comparation++;}
        else {arr[k++]=right_arr[j++];comparation++;}
    }
    // for remaning elements
        while (j<r) arr[k++]=right_arr[j++];
        while(i<l) arr[k++]=left_arr[i++];
}
void margeSort(int *arr,int l,int r){
    if(r>l)
    {
    int mid =  (r+l)/2;
        margeSort(arr,l,mid);
        margeSort(arr,mid+1,r);
        concure(arr,mid,l,r);
    }
}

int main(){
    // printf("radhe radhe\n");
    // srand(time(0));
    // int n=10;
    // int *arr= malloc(sizeof(int)*n);
    // for (int i=0;i<n;i++) arr[i]=rand();
    // printf("arry before sort: \n");
    // print_arr(arr,n);
    // margeSort(arr,0,n-1);
    // printf("arry after sort: \n");
    // print_arr(arr,n);
    // printf("no of comparation: %d\n",comparation);
    srand(time(0));
    printf("Radhe Radhe\n");
    FILE * fptr_r, * fptr_w;
    fptr_r=fopen("file.txt","r");
    fptr_w=fopen("file_o.csv","w");
    if(fptr_r==NULL && fptr_w==NULL){ 
        printf("The file is not opened. The program will exit now");
        exit(0);
    }else{
        int n;
        char first[5000]="input",second[5000]="compation";
        fprintf(fptr_w,"%s,%s\n",first,second);
        while (fscanf(fptr_r,"%d,",&n)==1)
        {   comparation=0;
            int *arr= malloc(sizeof(int)*n);
            for (int i=0;i<n;i++)
            {
                arr[i]=rand();
            }
            int p=0;
            int r=n-1;
            margeSort(arr,0,n-1);
            fprintf(fptr_w,"%d, %d\n",n,comparation);
        }
        
    }

}