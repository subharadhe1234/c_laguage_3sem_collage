#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parrent;
}node;

// create node 
node* create_node( int data){
node * ptr= malloc(sizeof(node));
ptr->data=data;
ptr->left=NULL;
ptr->right=NULL;
}

//  find min
node* find_min(node* root){
    node* prev=NULL;
    while(root != NULL){
        prev=root;
        root= root->left;
    }
    return prev;
}

//  find max
node* find_max(node* root){
    node* prev=NULL;
    while(root != NULL){
        prev=root;
        root= root->right;
    }
    return prev;
}

// find parrnet node of any node
node* find_parrent(node* root,node * f_node){
    node* prev=NULL;
    while(root!=f_node){
        prev= root;
        if(root->data>f_node->data) root=root->left;
        else if(root->data<f_node->data) root=root->right;
    }
    return prev;

}

// find succ
node* find_succ(node* root,node* ptr){
    if(ptr->right!= NULL) return find_min(ptr->right);
    else {
        node* succ=NULL;
        while(root!=ptr){
            if(root->data>ptr->data){
                succ=root;
                root=root->left;
            }else if(root->data<ptr->data) {
                root=root->right;
            }
        }
        return succ;
    }
}

// find pred
node* find_pred(node* root,node* ptr){
    if(ptr->left!= NULL) return find_min(ptr->left);
    else {
        node* pred=NULL;
        while(root!=ptr){
            if(root->data>ptr->data){
                root=root->left;
            }else if(root->data<ptr->data) {
                pred=root;
                root=root->right;
            }
        }
        return pred;
    }
}

// find hight of a node (max no of level form the leaf node )
int find_hight(node* root){
    if(root==NULL) return 0;
    int left_h=find_hight(root->left);
    int right_h=find_hight(root->right);
    if(left_h>right_h) return left_h+1;
    else return right_h+1;

}

// find hight diff left_h-right_h
int find_hight_diff(node* root){
    int l_h= find_hight(root->left);
    int r_h= find_hight(root->right);
    int diff=l_h-r_h;
    return diff;
}

// for avl tree right rotate
node* right_rotate(node* root,node* x){
    node* y=x->left;
    node* x_pa=find_parrent(root,x);
    if(x_pa==NULL) root=y;
    else if (x_pa->left==x) x_pa->left=y;
    else x_pa->right=y;
    x->left=y->right;
    y->right=x;
    return root;
}

// for avl tree left rotate
node* left_rotate(node* root,node* x){
    node* y=x->right;
    node* x_pa=find_parrent(root,x);
    if(x_pa==NULL) root=y;
    else if (x_pa->left==x) x_pa->left=y;
    else x_pa->right=y;
    x->right=y->left;
    y->left=x;
    return root;
}


// print tree inorder
void print_inorder(node* root){
    if(root==NULL) return;
    print_inorder(root->left);
    printf("%d ",root->data);
    print_inorder(root->right);
}

// if this element is alrady is exixt of not
int is_dublicate(node* root,int data){

    while(root!=NULL){
        if(root->data==data) return -1; // it present in the tree
        else if(root->data>data) root=root->left;
        else if(root->data<data) root=root->right;
    }
    return 0; // not find any element 
}

// search element ireturn the node of the search element
node* search(node* root,int data){

    while(root!=NULL){
        if(root->data==data) return root; // if find the element
        else if(root->data>data) root=root->left;
        else if(root->data<data) root=root->right;
    }
    return NULL; // not find any element 
}

// insert node in tree
node* insert(node* root,int data){
node* ptr=create_node(data);
node* curr=root;
node* prev=NULL;
if(root==NULL) return ptr;
else{
    if(is_dublicate(root,data)!=-1){
        while(curr!=NULL){
        prev=curr;
        if(curr->data>data) curr=curr->left;
        else if(curr->data<data) curr=curr->right;
        }
        if(prev->data>data) prev->left=ptr;
        else prev->right=ptr;
    }
    return root;
}
}

// avl_insertion 
// node* avl_insert(node* root,node* data){

// }

// transplant for delete
void transplant(node* root, node* d_node,node* r_node){
    node* parr=find_parrent(root,d_node);
    if(d_node==root) root = r_node;
    else if(d_node==parr->left) parr->left=r_node;
    else if(d_node==parr->right) parr->right=r_node;
}

// delete node
void delete(node* root,node * d_node){
        if(d_node->left==NULL){ transplant(root,d_node,d_node->right); }
        else if(d_node->right==NULL) transplant(root,d_node,d_node->left);
        else{
        node* min=find_min(d_node->right);
        if(find_parrent(root,min)!=d_node){
            transplant(root,min,min->right);
            min->right=d_node->right;
        }
        transplant(root,d_node,min);
        min->left=d_node->left;
        }
}

int main(){
    printf("radhe radhe\n");
    node* root=NULL;
    int arr[]={10,4,12,2,7,11,15,5};
    int len=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len;i++){
    root=insert(root,arr[i]);
    }
    print_inorder(root);
    // delete(root,search(root,4));
    // printf("\n");
    // print_inorder(root);
    // printf("\n%d\n",find_pred(root,search(root,11))->data);
    // printf("\n%d\n",find_parrent(root,search(root,7))->data);
    printf("\n%d ",find_hight_diff(search(root,4)));
    
}