#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int count;
} PriorityQueue;

PriorityQueue* initialize() {
    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    pq->count = 0;
    return pq;
}

bool isFull(PriorityQueue* pq) {
    return pq->count == MAX;
}

bool isEmpty(PriorityQueue* pq) {
    return pq->count == 0;
}

void enqueue(PriorityQueue* pq, int value) {
    if (isFull(pq)) {
        printf("Priority Queue is Full.\n");
        return;
    }
    pq->data[pq->count++] = value;
}

int dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is Empty.\n");
        return -1;
    }

    int maxIndex = 0;
    for (int i = 1; i < pq->count; i++) {
        if (pq->data[i] > pq->data[maxIndex])
            maxIndex = i;
    }

    int value = pq->data[maxIndex];
    pq->data[maxIndex] = pq->data[--pq->count];
    return value;
}

void display(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is Empty.\n");
        return;
    }

    printf("Queue Elements: ");
    for (int i = 0; i < pq->count; i++)
        printf("%d ", pq->data[i]);
    printf("\n");
}

int main() {
    PriorityQueue* pq = initialize();

    enqueue(pq, 10);
    enqueue(pq, 30);
    enqueue(pq, 20);

    display(pq);

    printf("Dequeued: %d\n", dequeue(pq));
    display(pq);

    free(pq);
    return 0;
}
