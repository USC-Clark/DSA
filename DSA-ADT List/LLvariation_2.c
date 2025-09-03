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

void empty(List *list){

    Node* current = list->head;

    for(int i=0;i<list->count;i++){
        free(current);
        current = current->next;
    }
    list->count = 0;
}

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

    // for(int i=0;i<list->count;i++){
    //     current = current->next;
    // }

    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
    list->count++;
    

}

void insertPos(List *list, int data, int index){

    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node* current = list->head;

    if(index > list->count){
        printf("Invalid Index");
    }else if(index==0){
        insertFirst(list, data);
    }else if (index==list->count){
        insertLast(list, data);
    }else{
        for(int i=0;i<index-1;i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        list->count++;
    }
}

void deleteStart(List *list){

    Node* current = list->head;

    list->head = current->next;

    free(current);

    list->count--;
}

void deleteLast(List *list){

    if(list->head->next == NULL){
        list->head = NULL;
        list->count--;
    }

    Node* current = list->head;

    for(int i=0;i<list->count-2;i++){
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    list->count--;
}
void deletePos(List *list, int index){

    if(index==0){
        deleteStart(list);
        list->count--;
    }

    Node* current = list->head;

    for(int i=0;i<index-1;i++){
        current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;

    free(temp);
    list->count--;
}

int retrieve(List *list, int index){

    if(index>list->count){
        printf("Invalid Index");
    }

    Node* current = list->head;

    for(int i=0;i<index;i++){
        current = current->next;
    }

    return current->data;
}

int locate(List *list, int data){

    if(list->head == NULL){
        return -1;
    }

    Node* current = list->head;
    int index = 0;
    int flag = 0;

    while(current->next!=NULL){
        
        if(current->data == data){
            flag = 1;
            return index;
        }else{
            current = current->next;
            index++;
        }
    }

    if(flag==0){
        return -1;
    }
}

void display(List *list){

    Node *current = list->head;

    if(list->count==0){
        printf("List is empty");
    }else{
        for(int i=0;i<list->count;i++){
            printf("%d ", current->data);
            current = current->next;
        }
    }
    

    //printf("test");
}

int main(){

    int hold, loc;
    List *L = initialize();

    insertFirst(L, 1);
    insertFirst(L, 2);
    insertLast(L, 3);
    insertPos(L, 4, 0);
    insertPos(L, 5, 4);
    insertPos(L, 6, 2);
    deleteStart(L);
    deleteLast(L);
    deletePos(L, 1);
    hold = retrieve(L, 1);
    loc = locate(L, 1);
    //empty(L);
    
    //printf("Count = %d ", L->count);

    display(L);

    //printf("\n hold = %d", hold);
    //printf("\n loc = %d", loc);

    // printf("%d", L->count);

    // printf("\n\nOutput");


    return 0;
}