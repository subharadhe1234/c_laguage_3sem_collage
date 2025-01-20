#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coff;
    int pow;
    struct node *next;
}node;
void printLinkList(node * head){
    node *temp=head;
    printf("(%d %d), ",temp->coff,temp->pow);
    temp=temp->next;
    while(temp!=head){
    printf("(%d %d), ",temp->coff,temp->pow);
        temp=temp->next;
    }
}
node *creatNode(int coff,int pow){
    node *temp= malloc(sizeof(node));
    temp->coff=coff;
    temp->pow=pow;
    temp->next=temp;
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

node* insert(node *head,int coff,int pow){
    node * curr=head,*np;
    np=creatNode(coff,pow);
    if(head==NULL)
        return np;
    np->coff=head->coff;
    np->pow = head->pow;
    np->next=head->next;
    head->coff=coff;
    head->pow=pow;
    head->next=np;
    return head;
}

void delete(node *head){
    node * tp=head , *prev ;
    while(tp->next!=head){
        prev=tp;
        tp=tp->next;
    }
    prev->next=head;
    free(tp);
}
int main(){
    printf("Radhe Radhe\n");
    node *head=NULL;
    head=insert(head,2,8);
    head=insert(head,2,9);
    head=insert(head,4,79);
    insert(head,6,2);
    delete(head);
    delete(head);
    insert(head,6,3);
    printLinkList(head);

}