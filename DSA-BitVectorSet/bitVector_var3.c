#include <stdio.h>
#include <stdbool.h>

#define MAX 8

typedef bool Set[MAX];

void initialize(Set set){
    int i;
    for(i = 0; i < MAX; i++){
        set[i] = false;
    }
}

void insert(Set set, int element){
    if(element >= 0 && element < MAX){
        set[element] = true;
    }
}


void delete(Set set, int element){
    if(element >= 0 && element < MAX){
        set[element] = false;
    }
}


bool find(Set set, int element){
    if(element >= 0 && element < MAX){
        return set[element];
    }
    return false;
}


void intersection(Set A, Set B, Set C){
    int i;
    for(i = 0; i < MAX; i++){
        C[i] = A[i] && B[i];
    }
}


void difference(Set A, Set B, Set C){
    int i;
    for(i = 0; i < MAX; i++){
        C[i] = A[i] && !B[i];
    }
}


void display(Set set){
    int i;
    printf("{ ");
    for(i = 0; i < MAX; i++){
        if(set[i] == true){
            printf("%d ", i);
        }
    }
    printf("}\n");
}


int main(){
    Set A, B, C;

    initialize(A);
    initialize(B);
    initialize(C);

    insert(A, 1);
    insert(A, 3);
    insert(A, 5);

    insert(B, 3);
    insert(B, 4);
    insert(B, 5);

    printf("Set A: ");
    display(A);

    printf("Set B: ");
    display(B);

    intersection(A, B, C);
    printf("Intersection (A ∩ B): ");
    display(C);

    difference(A, B, C);
    printf("Difference (A - B): ");
    display(C);

    return 0;
}

