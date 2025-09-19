#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){

    if(position>L->count){
        printf("Position Invalid");
    }else if(L->count == MAX){
        printf("Array is Full!");
    }else{
        for(int i=L->count-1;i>=position;i--){
            L->elem[i+1] = L->elem[i];
        }
        L->elem[position] = data;
        L->count++;
    }
}

void deletePos(EPtr L, int position){

    if(position>=L->count){
        printf("Invalid Position");
    }else{
        for(int i=position;i<L->count;i++){
            L->elem[i] = L->elem[i+1];
        }
        L->count--;
    }
}

int locate(EPtr L, int data){

    for(int i=0;i<L->count;i++){
        if(L->elem[i]==data){
            return i;
        }
    }
    return -1;
}

int retrieve(EPtr L, int position){

    if(position<=L->count){
        return L->elem[position];
    }else{
        printf("Invalid Position");
    }
}

void insertSorted(EPtr L, int data){

    if(L->count!=MAX){
        for(int i=0;i<L->count;i++){
            if(L->elem[i]<data && L->elem[i+1]>data){
                for(int j=L->count;j>i;j--){
                    L->elem[j] = L->elem[j-1];
                }
                L->elem[i+1] = data;
                L->count++;
                break;
            }
        }
    }
}

void display(EPtr L){

    for(int i=0;i<L->count;i++){
        printf("%d ", L->elem[i]);
    }
}

void makeNull(EPtr L){

    free(L);
}

int main(){

    EPtr L = malloc(sizeof(EPtr));

    int hold;

    initialize(L);
    insertPos(L, 1, 0);
    insertPos(L, 2, 1);
    insertPos(L, 3, 2);
    insertPos(L, 5, 3);
    //deletePos(L, 1);
    // hold = locate(L, 4);
    insertSorted(L, 4);
    // hold = retrieve(L, 2);
    // printf("%d\n", hold);
    display(L);
}