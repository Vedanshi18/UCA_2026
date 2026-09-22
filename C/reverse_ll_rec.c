#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* reverse(Node *head) {

    // Base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Reverse the rest of the list
    Node *newHead = reverse(head->next);

    // Put current node after its next node
    head->next->next = head;

    // Remove old connection
    head->next = NULL;

    return newHead;
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {

    Node *head = malloc(sizeof(Node));
    Node *second = malloc(sizeof(Node));
    Node *third = malloc(sizeof(Node));
    Node *fourth = malloc(sizeof(Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    printf("Original list:\n");
    printList(head);

    head = reverse(head);

    printf("Reversed list:\n");
    printList(head);

    return 0;
}