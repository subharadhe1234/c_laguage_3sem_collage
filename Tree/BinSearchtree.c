// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int deepth;
typedef  struct node
{
    int data;
    struct node* right;
    struct node* left;
    struct node* parent;
    
} node;
// random number 
int random (int min ,int max){
    int ran=rand()%(max-min +1)+min;
    return ran;
}

void print(int data){
    printf("%d ",data);
}
// print tree
void print_tree(node* root){

    if(root){
        print_tree(root->left);
        printf("%d ",root->data);
        print_tree(root->right);
        // printf("%d ",root->data);
    }    
    
}

// create node
node* create_node(int data){
    node * newnode = malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->parent=NULL;
    return newnode;
}
int search (node* root,int data){
    // node* prev=NULL;
    if(root==NULL|| data==root->data){
        // if(root==NULL) return prev;
        if(root==NULL) return -1;
        else return deepth;
    }
    else if(data > root->data){
        deepth++;
        return search(root->right,data);
    }else{
        deepth++;
        return search(root->left,data);
    }
}
node*  insert(node* root,int data){
    node* temp= root;
    node* newnode=create_node(data);
    if(root==NULL){
        return create_node(data);
    }else{
        if(search(root,data)==-1){
            while (1)
            {
            if(root->left==NULL && root->data>data){
                root->left=newnode;
                newnode->parent=root;
                return temp;
            }else if(root->right==NULL && root->data<data){
                root->right=newnode;
                newnode->parent=root;
                return temp;
            }else{
                if(root->data>data){ root=root->left;
                
                }
                else if(root->data<data){ root=root->right;
                
                }
            }
            }
            
        }else{
            return root;
        }
    }
}
int main() {
    // Write C code here
    int n=10,i=0;
    printf("Radhe Radhe \n");
    // printf("enter the no of element you want: ");
    // scanf("%d",&n);
    srand(time(0));
    node*root=NULL;
    printf("enter Number :");
    int num;
    for(i=0;i<n;i++){
        num=random(1,50);
        print(num);
        root=insert(root,num);
    }
    printf("\nTree is :");
    print_tree(root);
    int element=num;
    printf("\nthe search %d ",element);
    deepth=0;
    print(search(root,element));

    return 0;
}