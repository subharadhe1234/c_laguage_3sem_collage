#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include <limits.h>
// stcture
typedef struct claster
{
    double x;
    double y;
    int id;
    int count;
}point;

// random number 
int random (int min ,int max){
    int ran=rand()%(max-min +1)+min;
    return ran;
}

// distance calculate
double distance(double x1,double y1,double x2,double y2){
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

int main(){
    printf("Radhe Radhe\n");
    srand(time(0));
    int k=5;
    int min=1;
    int max=10000;
    int n=10000;
    // input k random point 
    point * ptr =malloc(sizeof(point)*k);
    point * temp1=ptr;
    for (int i=0;i<k;i++){
        temp1->x=(double)random(min ,max);
        temp1->y=(double)random(min ,max);
        temp1->id=i;
        temp1++;
    }
    // intput n random point
    point *nums=malloc(sizeof(point)*n);
    point * temp2=nums;
    int x=0;

    for (int i=0;i<n;i++){
        temp2->x=(double)random(min ,max);
        temp2->y=(double)random(min ,max);
        temp2->id=-1;
        temp2++;
    }
    while(x<5){
    int  min_prt=-1;
    temp2=nums;
    for(int i=0;i<n;i++){
        temp1=ptr;
        double min_num=INT_MAX;
        for(int j=0;j<k;j++){
            double dis=distance(temp2->x,temp2->y,temp1->x,temp1->y);
            if(dis<min_num){
                min_num=dis;
                min_prt=temp1->id;
            }
            temp1++;
        }
        temp2->id=min_prt;
        temp2++;
    }
    temp1=ptr;
    temp2=nums;
    // cluster center change
    for(int i=0;i<k; i++){
        temp1[i].x=0;
        temp1[i].y=0;
        temp1[i].count=0;
    }
    for(int i=0;i<n;i++){
        
        temp1[temp2->id].x+=temp2->x;
        temp1[temp2->id].y+=temp2->y;
        temp1[temp2->id].count++;
        temp2++;
    }
    for(int i=0;i<k; i++){
        temp1[i].x/=temp1[i].count;
        temp1[i].y/=temp1[i].count;

    }
    
    x++;
    }
    // data added in file
    FILE * fptr;
    fptr=fopen("file.csv","w");
    if(fptr==NULL){ 
        printf("The file is not opened. The program will exit now");
        exit(0);
    }else{
        temp2=nums;
        for(int i=0;i<n;i++){
            fprintf(fptr,"%f, %f, %d\n",temp2->x,temp2->y,temp2->id);
            temp2++;
        }
        printf("The file is created Successfully.");
    }
    fclose(fptr);

}