#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* table[MAX];

int hash(int key) {
    return key % MAX;
}

Node* insertBST(Node* root, int value) {
    if (root == NULL) {
        Node* temp = malloc(sizeof(Node));
        temp->data = value;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (value < root->data)
        root->left = insertBST(root->left, value);
    else
        root->right = insertBST(root->right, value);
    return root;
}

void initialize() {
    for (int i = 0; i < MAX; i++)
        table[i] = NULL;
}

void insert(int value) {
    int index = hash(value);
    table[index] = insertBST(table[index], value);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void display() {
    for (int i = 0; i < MAX; i++) {
        printf("%d: ", i);
        inorder(table[i]);
        printf("\n");
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
