#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int heap[MAX];
    int size;
} PriorityQueue;

PriorityQueue* initialize() {
    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}

bool isFull(PriorityQueue* pq) {
    return pq->size == MAX;
}

bool isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue* pq, int index) {
    while (index > 0 && pq->heap[(index - 1) / 2] < pq->heap[index]) {
        swap(&pq->heap[index], &pq->heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(PriorityQueue* pq, int index) {
    int largest = index;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->heap[left] > pq->heap[largest])
        largest = left;

    if (right < pq->size && pq->heap[right] > pq->heap[largest])
        largest = right;

    if (largest != index) {
        swap(&pq->heap[index], &pq->heap[largest]);
        heapifyDown(pq, largest);
    }
}

void enqueue(PriorityQueue* pq, int value) {
    if (isFull(pq)) {
        printf("Priority Queue is Full.\n");
        return;
    }

    pq->heap[pq->size] = value;
    heapifyUp(pq, pq->size);
    pq->size++;
}

int dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is Empty.\n");
        return -1;
    }

    int value = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    heapifyDown(pq, 0);

    return value;
}

int peek(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is Empty.\n");
        return -1;
    }
    return pq->heap[0];
}

void display(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is Empty.\n");
        return;
    }

    printf("Heap Elements: ");
    for (int i = 0; i < pq->size; i++)
        printf("%d ", pq->heap[i]);
    printf("\n");
}

int main() {
    PriorityQueue* pq = initialize();

    enqueue(pq, 15);
    enqueue(pq, 30);
    enqueue(pq, 10);
    enqueue(pq, 25);

    display(pq);

    printf("Dequeued: %d\n", dequeue(pq));
    display(pq);

    free(pq);
    return 0;
}
