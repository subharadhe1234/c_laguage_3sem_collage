#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;

int Partion(int *arr,int p,int r){
    int x=arr[r];
    int i=p-1;
    for (int j = p; j < r; j++)
    {   
        if(arr[j]<=x){
            i=i+1;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            count++;
        }
    }
    int temp=arr[r];
    arr[r]=arr[i+1];
    arr[i+1]=temp;
    return i+1;
    
}

void QuickSort(int *arr,int p,int r){
    if(p<r){
        int q=Partion(arr,p,r);
        QuickSort(arr,p,q-1);
        QuickSort(arr,q+1,r);

    }    
}

int  main(){
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
        {   count=0;
            int *arr= malloc(sizeof(int)*n);
            for (int i=0;i<n;i++)
            {
                arr[i]=rand();
            }
            int p=0;
            int r=n-1;
            QuickSort(arr,p,r);
            fprintf(fptr_w,"%d, %d\n",n,count);
        }
        
    }
}