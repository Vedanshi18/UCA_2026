#include <stdio.h>
#include <stdlib.h>

// Node of the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Stack contains pointer to top node
typedef struct {
    Node *top;
} Stack;

// Initialize stack
void initialize(Stack *s) {
    s->top = NULL;
}

// Check whether stack is empty
int is_empty(Stack *s) {
    return s->top == NULL;
}

// Return number of elements
int size(Stack *s) {
    int count = 0;
    Node *current = s->top;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Push an element
void push(Stack *s, int key) {

    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = key;
    newNode->next = s->top;

    s->top = newNode;
}

// Pop an element
int pop(Stack *s) {

    if (is_empty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }

    Node *temp = s->top;

    int result = temp->data;

    s->top = temp->next;

    free(temp);

    return result;
}

// Display stack
void display(Stack *s) {

    if (is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }

    Node *current = s->top;

    printf("Stack: ");

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {

    Stack s;

    initialize(&s);

    printf("Initial size = %d\n", size(&s));
    printf("Is empty = %d\n\n", is_empty(&s));

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);

    display(&s);

    printf("Size = %d\n", size(&s));
    printf("Is empty = %d\n\n", is_empty(&s));

    printf("Element popped = %d\n", pop(&s));
    printf("Element popped = %d\n", pop(&s));

    display(&s);

    printf("Size = %d\n", size(&s));
    printf("Is empty = %d\n", is_empty(&s));

    return 0;
}