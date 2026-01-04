#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Stack;

Stack* initialize() {
    return NULL;   
}

bool isEmpty(Stack* s) {
    return s == NULL;
}

Stack* push(Stack* s, int value) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return s;
    }

    newNode->data = value;
    newNode->next = s;
    s = newNode;

    printf("%d pushed successfully.\n", value);
    return s;
}

Stack* pop(Stack* s, int* value) {
    if (isEmpty(s)) {
        printf("Stack is Empty.\n");
        return s;
    }

    Stack* temp = s;
    *value = temp->data;
    s = temp->next;
    free(temp);

    return s;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty.\n");
        return -1;
    }
    return s->data;
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty.\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");
    while (s != NULL) {
        printf("%d\n", s->data);
        s = s->next;
    }
}

int main() {
    Stack* s = initialize();
    int popped;

    s = push(s, 5);
    s = push(s, 10);
    s = push(s, 15);
    s = push(s, 20);

    s = pop(s, &popped);
    printf("Popped successfully! %d\n", popped);

    s = pop(s, &popped);
    printf("Popped successfully! %d\n", popped);

    s = push(s, 30);

    display(s);

    printf("Top element: %d\n", peek(s));

    return 0;
}
