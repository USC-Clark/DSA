#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int count;
} Queue;

Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    q->count = 0;
    return q;
}

bool isFull(Queue* q) {
    return q->count == MAX;
}

bool isEmpty(Queue* q) {
    return q->count == 0;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is Full! %d not added.\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }

    q->data[q->rear] = value;
    q->count++;
    printf("%d enqueued successfully.\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty.\n");
        return -1;
    }

    int value = q->data[q->front];

    if (q->count == 1) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    q->count--;
    return value;
}

int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty.\n");
        return -1;
    }
    return q->data[q->front];
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Queue elements:\n");
    int index = q->front;
    for (int i = 0; i < q->count; i++) {
        printf("%d\n", q->data[index]);
        index = (index + 1) % MAX;
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
