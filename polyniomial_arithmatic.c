#include <stdio.h>
#include <stdlib.h>

// Structure for a polynomial node
typedef struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode* next;
} PolyNode;

// Avail list for recycling nodes
PolyNode* avail_list = NULL;

// Function to create a new node
PolyNode* create_node(int coeff, int exp) {
    PolyNode* new_node;
    
    // Reuse a node from the avail list if available
    if (avail_list != NULL) {
        new_node = avail_list;
        avail_list = avail_list->next;
    } else {
        new_node = (PolyNode*)malloc(sizeof(PolyNode));
    }
    
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;
    
    return new_node;
}

// Function to add a node to the avail list
void add_to_avail_list(PolyNode* node) {
    node->next = avail_list;
    avail_list = node;
}

// Function to create a polynomial in decreasing order of exponents
PolyNode* create_polynomial() {
    PolyNode* head = NULL;
    PolyNode* temp;
    int coeff, exp;
    
    while (1) {
        printf("Enter coefficient and exponent (Enter 0 0 to stop): ");
        scanf("%d %d", &coeff, &exp);
        
        if (coeff == 0 && exp == 0)
            break;
        
        PolyNode* new_node = create_node(coeff, exp);
        
        if (head == NULL) {
            head = new_node;
            new_node->next = head; // Circular link
        } else {
            temp = head;
            while (temp->next != head && temp->next->exp > exp)
                temp = temp->next;
            // Insert in the correct position
            new_node->next = temp->next;
            temp->next = new_node;
            
            // Maintain circular property
            if (new_node->next == head) {
                head = new_node;
            }
        }
    }
    return head;
}

// Function to display the polynomial
void display_polynomial(PolyNode* head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    
    PolyNode* temp = head;
    do {
        printf("%dx^%d ", temp->coeff, temp->exp);
        if (temp->next != head) {
            printf("+ ");
        }
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to add two polynomials (A + B)
PolyNode* add_polynomials(PolyNode* A, PolyNode* B) {
    PolyNode *head = NULL, *temp = NULL, *new_node;
    PolyNode *ptr1 = A, *ptr2 = B;
    
    while (ptr1 != A || ptr2 != B) {
        if (ptr1->exp == ptr2->exp) {
            int sum = ptr1->coeff + ptr2->coeff;
            if (sum != 0) {
                new_node = create_node(sum, ptr1->exp);
                if (head == NULL) {
                    head = new_node;
                    temp = head;
                } else {
                    temp->next = new_node;
                    temp = temp->next;
                }
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->exp > ptr2->exp) {
            new_node = create_node(ptr1->coeff, ptr1->exp);
            if (head == NULL) {
                head = new_node;
                temp = head;
            } else {
                temp->next = new_node;
                temp = temp->next;
            }
            ptr1 = ptr1->next;
        } else {
            new_node = create_node(ptr2->coeff, ptr2->exp);
            if (head == NULL) {
                head = new_node;
                temp = head;
            } else {
                temp->next = new_node;
                temp = temp->next;
            }
            ptr2 = ptr2->next;
        }
    }

    // Closing the circular link
    if (temp != NULL) temp->next = head;
    return head;
}

// Function to subtract two polynomials (A - B)
PolyNode* subtract_polynomials(PolyNode* A, PolyNode* B) {
    PolyNode *head = NULL, *temp = NULL, *new_node;
    PolyNode *ptr1 = A, *ptr2 = B;
    
    while (ptr1 != A || ptr2 != B) {
        if (ptr1->exp == ptr2->exp) {
            int diff = ptr1->coeff - ptr2->coeff;
            if (diff != 0) {
                new_node = create_node(diff, ptr1->exp);
                if (head == NULL) {
                    head = new_node;
                    temp = head;
                } else {
                    temp->next = new_node;
                    temp = temp->next;
                }
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->exp > ptr2->exp) {
            new_node = create_node(ptr1->coeff, ptr1->exp);
            if (head == NULL) {
                head = new_node;
                temp = head;
            } else {
                temp->next = new_node;
                temp = temp->next;
            }
            ptr1 = ptr1->next;
        } else {
            new_node = create_node(-ptr2->coeff, ptr2->exp);
            if (head == NULL) {
                head = new_node;
                temp = head;
            } else {
                temp->next = new_node;
                temp = temp->next;
            }
            ptr2 = ptr2->next;
        }
    }
    
    // Closing the circular link
    if (temp != NULL) temp->next = head;
    return head;
}

// Function to multiply two polynomials (A * B)
PolyNode* multiply_polynomials(PolyNode* A, PolyNode* B) {
    PolyNode *head = NULL, *temp = NULL, *new_node;
    PolyNode *ptr1 = A, *ptr2 = B;
    
    while (ptr1 != A) {
        ptr2 = B;
        while (ptr2 != B) {
            int coeff = ptr1->coeff * ptr2->coeff;
            int exp = ptr1->exp + ptr2->exp;
            new_node = create_node(coeff, exp);
            
            if (head == NULL) {
                head = new_node;
                temp = head;
            } else {
                temp->next = new_node;
                temp = temp->next;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    
    // Sorting terms in descending order of exponents (may need adjustments)
    // Closing the circular link
    if (temp != NULL) temp->next = head;
    return head;
}

// Function to erase a polynomial (free all nodes)
void erase_polynomial(PolyNode* head) {
    if (head == NULL) return;
    
    PolyNode* temp = head;
    PolyNode* next_node;
    
    do {
        next_node = temp->next;
        add_to_avail_list(temp); // Recycle node
        temp = next_node;
    } while (temp != head);
    
    head = NULL; // Now head is NULL, the polynomial is erased
}

// Main function with menu
int main() {
    PolyNode *A = NULL, *B = NULL;
    int choice;
    
    do {
        printf("\nMenu:\n");
        printf("1. Create Polynomial\n");
        printf("2. Add Polynomials (A + B)\n");
        printf("3. Subtract Polynomials (A - B)\n");
        printf("4. Multiply Polynomials (A * B)\n");
        printf("5. Display Polynomial A\n");
        printf("6. Erase Polynomial A\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Create Polynomial A\n");
                A = create_polynomial();
                break;
            case 2:
                printf("Add Polynomial A and B\n");
                B = create_polynomial();
                A = add_polynomials(A, B);
                break;
            case 3:
                printf("Subtract Polynomial A and B\n");
                B = create_polynomial();
                A = subtract_polynomials(A, B);
                break;
            case 4:
                printf("Multiply Polynomial A and B\n");
                B = create_polynomial();
                A = multiply_polynomials(A, B);
                break;
            case 5:
                printf("Display Polynomial A\n");
                display_polynomial(A);
                break;
            case 6:
                printf("Erase Polynomial A\n");
                erase_polynomial(A);
                A = NULL;
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);
    
    return 0;
}
