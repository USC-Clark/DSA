#include <stdio.h>
#include <stdlib.h>
#define LENGTH 5

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

void initialize(List *L){

    L->elemPtr =malloc(sizeof(int)*LENGTH);

    if(L->elemPtr == NULL){
        printf("Memory Allocation Failed!");
    }else{

        L->max = LENGTH;
        L->count = 0;

    }  
}

void resize(List *L){

    int newSize = L->max * 2;

    int *newPtr = realloc(L->elemPtr, sizeof(int) * (newSize));

    if(newPtr==NULL){
        printf("Memory reallocation failed!");
        return;
    }

    L->elemPtr = newPtr;
    L->max = newSize;
}

void insertPos(List *L, int data, int position){

    if(L->count==LENGTH){
        resize(L);
    }

    if(position<=L->count){
        if(position==0 && L->count==0){
            L->elemPtr[position] = data;
            L->count++;
        }else if(position==L->count){
            L->elemPtr[position] = data;
            L->count++;
        }else{
            for(int i=L->count;i>position;i--){
                L->elemPtr[i] = L->elemPtr[i-1];
            }
            L->elemPtr[position] = data;
            L->count++;
        }
    }else{
        printf("Invalid Position!");
    }
}

void deletePos(List *L, int position){

    if(position<=L->count){
        for(int i=position;i<L->count;i++){
            L->elemPtr[i] = L->elemPtr[i+1];
        }
        L->count--;
    }
}

int locate(List *L, int data){

    for(int i=0;i<L->count;i++){
        if(L->elemPtr[i]==data){
            return i;
        }
    }
    return -1;
}

int retrieve(List *L, int position){

    if(position<L->count){
        return L->elemPtr[position];
    }else{
        printf("Invalid Position");
        return -1;
    }
}

void insertSorted(List *L, int data){

}

void display(List *L){

    for(int i=0;i<L->count;i++){
        printf("%d\n", L->elemPtr[i]);
    }
}



void makeNULL(List *L){
    free(L);
}

int main(){

    List *L = malloc(sizeof(List));
    int hold;

    initialize(L);
    insertPos(L, 1, 0);
    insertPos(L, 2, 1);
    insertPos(L, 3, 2);
    insertPos(L, 4, 3);
    insertPos(L, 5, 4);
    insertPos(L, 6, 5);
    //deletePos(L, 1);
    display(L);

    // hold = locate(L, 1);
    // hold = retrieve(L, 1);
    // printf("hold = %d", hold);
}