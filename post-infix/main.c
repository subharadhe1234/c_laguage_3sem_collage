# include<stdio.h>
# include <stdlib.h>
#define size 100
typedef struct data
{
int top;
int val[size];
}data;

// init function
void init(data *stack){
    stack->top=-1;
}

// push
void push(data * stack,int vall){
    if(stack->top >=size){
        printf ("the stack is full \n");
    }else{
        stack->val[++stack->top] = vall;
    }
}

// pop
int pop(data * stack){
    if(stack->top <= -1){
        printf ("the stack is empty \n");
    }
    return stack->val[stack->top--];
}

// pop all the exicting value
void pop_all(data * stack){
    while (stack->top !=-1)
    {
        printf("%c ",stack->val[stack->top--]);
    }
    printf("\n");
}

// print the all stack element
void print(data * stack){
    while (stack->top !=-1)
    {
        printf("%d ",stack->val[stack->top--]);
    }
    printf("\n");
}

// check all braket is corrent or not 
void check_correct_bracket(data * stack,char * s){
    while(*s!='\0'){
        if(*s=='('){
        push(stack,*s);}
        if(*s==')') pop(stack);
        s++;
    }
    if(stack->top==-1){
        printf("all bracker is correct\n");
    }else
    {
        printf(") is not closed\n");
        
    }
}  

// post_index  
char * in_postindex_form(data * stack,char * s){
    char *arr = malloc(sizeof(char)*100);
    int i=0;
    while(*s!='\0'){
        if(*s>41 && *s<48){
            push(stack,*s);
        }else if (*s==')'){
            arr[i++]=pop(stack);
        }else if(*s!='('){
            arr[i++]=*s;
        }
        if(*(s+1)=='\0'){
    while (stack->top !=-1)
    {
        arr[i++]=stack->val[stack->top--];
    }
        }
    s++;
    }
    arr[i]='\0';
    return arr;
}
// post_index  
char * post_not_bracket(data * stack,char * s){
    char *arr = malloc(sizeof(char)*100);
    int i=0;
    while(*s!='\0'){
        if(*s>41 && *s<48){
            push(stack,*s);
        }else if (*s==')'){
            arr[i++]=pop(stack);
        }else if(*s!='('){
            arr[i++]=*s;
        }
        if(*(s+1)=='\0'){
    while (stack->top !=-1)
    {
        arr[i++]=stack->val[stack->top--];
    }
        }
    s++;
    }
    arr[i]='\0';
    return arr;
}

// calculation
void calculation(char *s,data * stack){
    while (*s!='\0')
    {
        if(*s>41 && *s<48){
            int a = pop(stack)-48;
            int b = pop(stack)-48;
            switch (*s)
            {
            case '+':
                push(stack,(b+a)+48);
                break;
            case '-':
                push(stack,(b-a)+48);
                break;
            case '*':
                push(stack,(a*b)+48);
                break;
            case '/':
                push(stack,(b+a)+48);
                break;
            
            default:
                break;
            }
            
        }else {
            push(stack,*s);
        }
        
        s++;
    }
    
}

// main
int main(){
    printf("radhe radhe\n");
    char s []= "((((7*8)+4)-(3*7))-((2*5)*2))";
    data stack;
    init(&stack);
    printf("%s\n",s);
    check_correct_bracket(&stack,s);
    char *arr=in_postindex_form(&stack,s);
    // printf("%s",arr);
    calculation(arr,&stack);
    printf("the ans is: ");
    print(&stack);
    
}