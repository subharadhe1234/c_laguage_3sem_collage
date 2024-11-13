#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coff;
    int pow;
    struct node *next;
}node;
void printLinkList(node * head){
    node *temp=head;
    while(temp!=NULL){
        printf("(%d %d), ",temp->coff,temp->pow);
        temp=temp->next;
    }
}
node *creatNode(int coff,int pow){
    node *temp= malloc(sizeof(node));
    temp->coff=coff;
    temp->pow=pow;
    temp->next=NULL;
    return temp;
}
node * addLast(node* head,int coff,int pow){
    node *nd, *temp=head;
    nd=creatNode(coff,pow);
    if(head==NULL){
        head=nd;
        return head ;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=nd;
    return head;
}
node* addFirst(node * head,int coff,int pow){
    node *np;
    np=creatNode(coff,pow);
    if(head==NULL)
        return np;
    else{
        np->next=head;
        head=np;
        return head;
    }
    return head;
}

node* insert(node *head,int coff,int pow,int pos){
    node * curr=head,*np;
    np=creatNode(coff,pow);
    if(head==NULL)
        return np;
    if (pos<=1) {
        np->next=head;
        head=np;
        return head;
    }
    while (pos!=2)
    {   pos--;
        curr=curr->next;
    }
    np->next=curr->next;
    curr->next=np;
    return head;
}

int main(){
    printf("Radhe Radhe\n");
    node *head=NULL;
    // addFirst(&head,4,1);
    // head =addLast(head,4,5);
    // head=addFirst(head,78,4);
    // head=addFirst(head,7,4);
    // head=addLast(head,55,2);
    head=insert(head,2,8,0);
    head=insert(head,2,9,3);
    printLinkList(head);

}