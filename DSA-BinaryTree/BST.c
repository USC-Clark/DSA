#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

bool search(Node* root, int value) {
    if (root == NULL)
        return false;

    if (root->data == value)
        return true;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    printf("Inorder   : ");
    inorder(root);

    printf("\nPreorder  : ");
    preorder(root);

    printf("\nPostorder : ");
    postorder(root);
    
    printf("\nSearch 40: ");
    if(search(root, 40)==1){
        printf("Found");
    }else{
        printf("Not Found");
    }

    return 0;
}
