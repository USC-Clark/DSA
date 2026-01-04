#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* table[MAX];

int hash(int key) {
    return key % MAX;
}

void initialize() {
    for (int i = 0; i < MAX; i++)
        table[i] = NULL;
}

void insert(int value) {
    int index = hash(value);
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = table[index];
    table[index] = newNode;
}

void display() {
    for (int i = 0; i < MAX; i++) {
        printf("%d: ", i);
        Node* trav = table[i];
        while (trav) {
            printf("%d -> ", trav->data);
            trav = trav->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int data[] = {20, 47, 22, 5, 65, 72, 6, 91};
    initialize();

    for (int i = 0; i < 8; i++)
        insert(data[i]);

    display();
    return 0;
}
