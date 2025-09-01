#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

typedef struct list{
    Node *head;
    int count;
}List;

List* initialize(){

    List *L = malloc(sizeof(List));
    if(L == NULL){
        printf("failed to allocate memory");
    }
    L->head = NULL;
    L->count = 0;

    return L;
}

// void empty(List *list){

// }

void insertFirst(List *list, int data){

    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(list->count==0){
        list->head = newNode;
        list->count++;
    }else{
        Node* current = list->head;

        newNode->next = current;
        list->head = newNode;
        list->count++;
    }
}

void insertLast(List *list, int data){

    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node *current = list->head;

    for(int i=0;i<list->count;i++){
        current = current->next;
    }
}

// void insertPos(List *list, int data, int index){

// }

// void deletePos(List *list, int index){

// }

// int retrieve(List *list, int index){

// }

// int locate(List *list, int data){

// }

void display(List *list){

    Node *current = list->head;

    if(list->count==0){
        printf("List is empty");
    }else{
        for(int i=0;i<list->count;i++){
            printf("%d", current->data);
            current = current->next;
        }
    }
    

    //printf("test");
}

int main(){

    List *L = initialize();

    insertFirst(L, 1);
    insertFirst(L, 2);

    display(L);

    // printf("%d", L->count);

    // printf("\n\nOutput");


    return 0;
}