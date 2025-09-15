#include <stdio.h>
#include <stdlib.h>
#define MAX 4

typedef struct {
    int elem;
    int next;
}Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
}VHeap;

typedef int List;

void initialize(VHeap* V){

    V->avail = 0;
    V->H[V->avail].next = V->avail++;
    // if(V->avail == -1){
    //     printf("Initialization Error!");
    // }
}

int allocSpace(VHeap* V){

    int ret;

    if(V->avail!=-1){
        ret = V->avail;
    }
    return ret;
}

void deallocSpace(VHeap* V, int index){

}

void insertFirst(int* L, VHeap* V, int elem){
    
    int newCell = allocSpace(V);

    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
        //printf("%d", V->H[newCell].elem);
    }
    *L = newCell;
}

void insertLast(int* L, VHeap* V, int elem){

}

void display(int L, VHeap V){

    int trav = L;

    while(trav != -1){
        printf("%d ", V.H[trav].elem);
        trav = V.H[trav].next;
    }

    //printf("Working");
}

int main(){

    VHeap v;
    List l = -1;

    initialize(&v);
    insertFirst(&l, &v, 5);
    insertFirst(&l, &v, 10);
    display(l,v);

    //insertFirst()

}