#include <stdio.h>

#define MAX 10
#define EMPTY -1

int table[MAX];

int hash(int key) {
    return key % MAX;
}

void initialize() {
    for (int i = 0; i < MAX; i++)
        table[i] = EMPTY;
}

void insert(int value) {
    int index = hash(value);

    while (table[index] != EMPTY) {
        index = (index + 1) % MAX;
    }
    table[index] = value;
}

void display() {
    for (int i = 0; i < MAX; i++) {
        if (table[i] == EMPTY)
            printf("%d: EMPTY\n", i);
        else
            printf("%d: %d\n", i, table[i]);
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
