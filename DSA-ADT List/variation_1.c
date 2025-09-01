#include <stdio.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List initialize(List L){
    
    for(int i=0;i<MAX;i++){
        L.elem[i] = -1;
    }
    L.count=0;

    return L;
}

List insertPos(List L, int data, int position){

    for(int i=0;i<MAX;i++){
        //L.elem[i] = data;
        if(i==position){
            L.elem[i] = data;
        }
    }
    L.count++;

    return L;
}

List deletePos(List L, int position){

    for(int i=0;i<MAX;i++){
        if(i==position){
            for(int j=i;j<MAX;j++){
                L.elem[j]=L.elem[j+1];
            }
        }
    }
    L.count--;
    return L;
}

int locate(List L, int data){

    for(int i=0;i<MAX;i++){
        if(L.elem[i]==data){
            return i;
        }
    }
}

List insertSorted(List L, int data){
    
    for(int i=0;i<MAX;i++){
        if(L.elem[i]<data && L.elem[i+1]>data || L.elem[i+1]==-1){
            if(L.elem[i+1]==-1){
                L.elem[i+1] = data;
            }else if(L.elem[i+1]!=-1){
                // for(int j=i;)
            }
        }
    }

    L.count++;

    return L;
}

void display(List L){


    for(int i=0;i<L.count;i++){
        printf("%d ", L.elem[i]);
    }
}

int main(){
    
    int loc = -1;
    List L;
    L.count=0;
    L = initialize(L);
    L = insertPos(L, 10, 0);
    L = insertPos(L, 20, 1);
    L = insertPos(L, 40, 2);
    //L = deletePos(L, 2);
    //loc = locate(L, 20);
    L = insertSorted(L, 30);
    display(L);
    
    //printf("%d", loc);
    // L.elem[0] = 10;
    //printf("%d", L.count);
    // L.elem[1] = 100;
    // L.elem[2] = 200;
}