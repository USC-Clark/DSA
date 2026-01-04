#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail; 
} VHeap;

typedef int List;

void initialize(VHeap* V) {
    int i;
    V->avail = MAX - 1; 

    for (i = MAX - 1; i > 0; i--) {
        V->H[i].next = i - 1;
    }
    V->H[0].next = -1;
}

int allocSpace(VHeap* V) {
    int ret = -1;

    if (V->avail != -1) {
        ret = V->avail;
        V->avail = V->H[ret].next;
    }

    return ret;
}

void deallocSpace(VHeap* V, int index) {
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(List* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);

    if (newCell != -1) {
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
        *L = newCell;
    }
}

void insertLast(List* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);
    int trav;

    if (newCell == -1) return;

    V->H[newCell].elem = elem;
    V->H[newCell].next = -1;

    if (*L == -1) {
        *L = newCell;
    } else {
        for (trav = *L; V->H[trav].next != -1; trav = V->H[trav].next) {}
        V->H[trav].next = newCell;
    }
}

void display(List L, VHeap V) {
    int trav = L;
    while (trav != -1) {
        printf("%d ", V.H[trav].elem);
        trav = V.H[trav].next;
    }
    printf("\n");
}

int main() {
    VHeap v;
    List l = -1;

    initialize(&v);

    insertFirst(&l, &v, 5);
    insertFirst(&l, &v, 10);
    insertLast(&l, &v, 20);

    display(l, v);

    return 0;
}
