#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

List initialize(){

    List L;
    L.elemPtr = malloc(sizeof(int)* LENGTH);
    L.count = 0;
    L.max = LENGTH;
    return L;
}

List insertPos(List L, int data, int position){
    
    if(position<=L.count){
        if(position==0){
            L.elemPtr[position] = data;
            L.count++;
        }else if(position==L.count){
            L.elemPtr[position] = data;
            L.count++;
        }else{
            for(int i=L.count;i>position;i--){
                L.elemPtr[i] = L.elemPtr[i-1];
            }
            L.elemPtr[position] = data;
            L.count++;
        }
    }

    return L;
}

List deletePos(List L, int position){

    if(position<=L.count){
        for(int i=position;i<L.count;i++){
            L.elemPtr[i] = L.elemPtr[i+1];
        }
        L.count--;
    }

    return L;
}

int locate(List L, int data){

    for(int i=0;i<L.count;i++){
        if(L.elemPtr[i]==data){
            return i;
        }
    }
    return -1;
}

List  insertSorted(List L, int data){

    for(int i=0;i<L.count;i++){
        if(L.elemPtr[i]<data && L.elemPtr[i+1]>data){
            for(int j=L.count;j>i;j--){
                L.elemPtr[j+1] = L.elemPtr[j];
            }
            L.elemPtr[i+1] = data;
            L.count++;
        }
    }

    return L;
}

void display(List L){

    for(int i=0;i<L.count;i++){
        printf("%d ", L.elemPtr[i]);
    }
}

List resize(List L){
    
    int *newPtr = (int*) malloc(sizeof(int)*(L.max*2));

    if(newPtr==NULL){
        printf("Memory reallocation failed");
        return L;
    }

    L.elemPtr = newPtr;
    L.max *= 2;
    return L;

}

int main(){

    List L = initialize();
    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 5, 2);
    L = insertSorted(L, 2);
    L = insertSorted(L, 4);
    //L = deletePos(L, 1);
    display(L);

    return 0;
}