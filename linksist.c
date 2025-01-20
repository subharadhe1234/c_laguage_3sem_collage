#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;

}node;

// create node
node* create_node(int data){
    node *ptr= malloc(sizeof(node*));
    ptr->data=data;
    ptr->next=NULL;

}
// print linklist

void print_linklist(node* head){
    while(head!=NULL){
        printf("%d -> ",head->data);
        head=head->next;
    }
        printf("NULL\n");

}
// add element
node* insert_last(node* head, int data){
    node *new_node=create_node(data);
    node* temp=head;
    if(head==NULL) return new_node;
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
        return head;

    }

}

node* insert_first(node* head,int data){
    node *new_node=create_node(data);
    new_node->next= head;
    return new_node;
}


node* insert_pos(node* head,int data, int pos){
    node *new_node=create_node(data);
    node* temp=head;
    if(temp==NULL ) return new_node;
    else{
        if(pos==0) return insert_first(head,data);
        else{
            int i=0;
            while(i<pos-1 && temp!=NULL){
                temp=temp->next;
                i++;
            }
            new_node->next=temp->next;
            temp->next=new_node;
        }
    }
    return head;

}

// delet first

node* delete_first(node* head){
    if(head==NULL) return head;
    else if (head->next==NULL) return NULL;
    else head=head->next;
    return head;
}

// delete lase

node* delete_last(node* head){
    if(head==NULL) return NULL;
    node* temp=head;
    node* prev=NULL;
    while (temp->next!=NULL)
    {   prev=temp;
        temp=temp->next;

    }
    if(temp==NULL) return NULL;
    prev->next=NULL;
    return head;
    
}
// delete any position

node* delete_pos(node* head, int pos){
    if(pos==0)  return delete_first(head);
    int i=0;
    node* prev=NULL;
    node* tem=head;
    while(i<pos&& tem!=NULL){
        prev=tem;
        tem=tem->next;
        i++;
    }
    prev->next=tem->next;
    free(tem);
    return head;
}
int main(){
    int arr[]={8,5,1,6,4,9,3};
    int len= sizeof(arr)/sizeof(arr[0]);
    node* head=NULL;
    for (int i=0;i<len; i++){
        head=insert_first(head,arr[i]);

    }
    // head=insert_first(head,85);
    print_linklist(head);
    head=delete_pos(head,1);
    print_linklist(head);
}