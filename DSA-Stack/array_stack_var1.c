#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int top;
} Stack;

Stack* initialize() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    s->top = -1;
    return s;
}

bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is Full! %d\n", value);
        return;
    }
    s->top++;
    s->data[s->top] = value;
    printf("%d pushed successfully.\n", value);
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty.\n");
        return -1;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty.\n");
        return -1;
    }
    return s->data[s->top];
}

int top(Stack* s) {
    return s->top;
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty.\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }
}

int main() {
    Stack* s = initialize();

    push(s, 5);
    push(s, 10);
    push(s, 15);
    push(s, 20);
    printf("Popped successfully!\n", pop(s));
    printf("Popped successfully!\n", pop(s));
    push(s, 30);

    display(s);

    printf("Top element: %d\n", peek(s));
    printf("Top index: %d\n", top(s));

    display(s);

    free(s);
    return 0;
}
