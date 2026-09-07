#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int a[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initialize(Stack *s) {
    s->top = -1;
}

// Check whether stack is empty
int is_empty(Stack *s) {
    return s->top == -1;
}

// Return number of elements
int size(Stack *s) {
    return s->top + 1;
}

// Push an element
void push(Stack *s, int key) {
    if (size(s) == MAX_SIZE) {
        printf("Stack Overflow\n");
        return;
    }

    s->a[++s->top] = key;
}

// Pop an element
int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }

    return s->a[s->top--];
}

// Display stack
void display(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");

    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->a[i]);
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