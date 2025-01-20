#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;

}node;

typedef struct queue_stuc{
    struct node* fornt;
    struct node* rare;
}queue_stuc;
// init quque
queue_stuc* initilize_queue(){
    queue_stuc* prt=(queue_stuc*)malloc(sizeof(queue_stuc));
    prt->fornt=NULL;
    prt->rare=NULL;
    return prt;
}


// create node
node* create_node(int data){
    node *ptr= (node*)malloc(sizeof(node*));
    ptr->data=data;
    ptr->next=NULL;

}

// add element
node* insert_last(node* head, int data){
    node *new_node=create_node(data);
    node* temp=head;
    if(head==NULL) {
        new_node->next =new_node;
        return new_node;}
    else{
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=head;
        return head;

    }

}

node* insert_first(node* head,int data){
    node *new_node=create_node(data);
    
    if(head==NULL) {
        new_node->next =new_node;
        return new_node;}
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    new_node->next=head;
    temp->next=new_node;
    return new_node;

}



node* delete_first(node* head){
    if(head==NULL) return head;
    if (head->next==head) return NULL;
    node* last=head;
    while(last->next!=head){
        last=last->next;
    }
    node* temp=head;
    head=head->next;
    last->next==head;
    return head;
}

// delete lase

node* delete_last(node* head){
    if(head==NULL) return NULL;
    node* temp=head;
    node* prev=NULL;
    while (temp->next!=head)
    {   prev=temp;
        temp=temp->next;

    }
    prev->next=head;
    return head;
    
}
// delete any position

queue_stuc* enque(queue_stuc * queqe,int data){
    if(queqe->fornt==NULL){
        queqe->fornt= insert_last(queqe->fornt,data);
        queqe->rare=queqe->fornt;
    }else{
        queqe->fornt= insert_last(queqe->fornt,data);
        queqe->rare=queqe->rare->next;
        
    }
return queqe;
}

queue_stuc* denque(queue_stuc * queqe){
    if(queqe->rare==queqe->fornt){
        printf("the queue is empty");
    }
    queqe->fornt=queqe->rare->next->next;
    delete_first(queqe->fornt);
    return queqe;
}

int  print_queqe(queue_stuc* queue){
    node* front= queue->fornt;
    node* rare= queue->rare;
    int count=0;
    while(front!=rare){
        printf("%d ",front->data);
        front=front->next;
        count++;
    }
        printf("%d ",front->data);
        count++;
        return count;
}

int main(){
    int arr[]={8,5,1,6,4,9,3};
    int len= sizeof(arr)/sizeof(arr[0]);
    node* head=NULL;
    for (int i=0;i<len; i++){
        head=insert_first(head,arr[i]);
    }

    queue_stuc * queue=initilize_queue();
    for (int i=0;i<len; i++){
        queue=enque(queue,arr[i]);
    }
    queue=denque(queue);
    int count=print_queqe(queue);
    printf("\nno of element is %d",count);
}