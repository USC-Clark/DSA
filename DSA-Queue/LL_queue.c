#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("%d enqueued successfully.\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty.\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;
    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty.\n");
        return -1;
    }
    return q->front->data;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Queue elements:\n");
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    Queue* q = initialize();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    display(q);

    printf("Front element: %d\n", front(q));

    enqueue(q, 50);
    enqueue(q, 60);

    display(q);

    free(q);
    return 0;
}
