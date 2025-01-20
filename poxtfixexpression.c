#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the structure for a tree node
typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

// Stack structure for building the tree
typedef struct Stack {
    Node* nodes[100];
    int top;
} Stack;

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Stack operations
void push(Stack *stack, Node* node) {
    stack->nodes[++stack->top] = node;
}

Node* pop(Stack *stack) {
    return stack->nodes[stack->top--];
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to build the expression tree from postfix expression
Node* constructTree(char postfix[]) {
    Stack stack;
    stack.top = -1;
    for (int i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            push(&stack, createNode(c));
        } else if (isOperator(c)) {
            Node* newNode = createNode(c);
            newNode->right = pop(&stack);
            newNode->left = pop(&stack);
            push(&stack, newNode);
        }
    }
    return pop(&stack);
}

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(Node* root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

// Function to evaluate the expression tree
int evaluate(Node* root) {
    if (!root)
        return 0;
    if (!isOperator(root->data))
        return root->data - '0'; // Convert char to int
    
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);
    
    switch (root->data) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
    }
    return 0;
}

// Main function
int main() {
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    
    Node* root = constructTree(postfix);
    
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");
    
    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");
    
    printf("Evaluated Expression Result: %d\n", evaluate(root));
    return 0;
}
