#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

bool isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is Full!\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }

    q->data[q->rear] = value;
    printf("%d enqueued successfully.\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty.\n");
        return -1;
    }

    int value = q->data[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

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
    int i = q->front;
    while (1) {
        printf("%d\n", q->data[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
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
