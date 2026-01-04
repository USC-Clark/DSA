#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} Node;

int getBit(int num, int bitPos) {
    return (num >> bitPos) & 1;
}

Node* createNode(int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->key = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* insert(Node* root, int value, int level) {
    if (root == NULL)
        return createNode(value);

    if (getBit(value, level) == 0)
        root->left = insert(root->left, value, level + 1);
    else
        root->right = insert(root->right, value, level + 1);

    return root;
}

bool search(Node* root, int value, int level) {
    if (root == NULL)
        return false;

    if (root->key == value)
        return true;

    if (getBit(value, level) == 0)
        return search(root->left, value, level + 1);
    else
        return search(root->right, value, level + 1);
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

int main() {
    Node* root = NULL;

    root = insert(root, 5, 0);
    insert(root, 9, 0);
    insert(root, 12, 0);
    insert(root, 3, 0);

    printf("Inorder   : ");
    inorder(root);

    printf("\nPreorder  : ");
    preorder(root);

    printf("\nPostorder : ");
    postorder(root);

        printf("\nSearch 9: ");
    if(search(root, 9, 0)==1){
        printf("Found");
    }else{
        printf("Not Found");
    }

    return 0;
}
