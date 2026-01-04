#include <stdio.h>
#include <stdbool.h>

#define MAX_BITS 8

typedef struct {
    unsigned char field : 8;
} Set;

void initializeSet(Set *set) {
    set->field = 0;
}

void insertSet(Set *set, int element) {
    if (element < 0 || element >= MAX_BITS) {
        printf("Error: Element out of range\n");
        return;
    }
    set->field |= (1 << element);
}

void deleteSet(Set *set, int element) {
    if (element < 0 || element >= MAX_BITS) {
        printf("Error: Element out of range\n");
        return;
    }
    set->field &= ~(1 << element);
}

bool findSet(Set set, int element) {
    if (element < 0 || element >= MAX_BITS) return false;
    return (set.field & (1 << element)) != 0;
}

Set setUnionSet(Set A, Set B) {
    Set result;
    result.field = A.field | B.field;
    return result;
}

Set setIntersectionSet(Set A, Set B) {
    Set result;
    result.field = A.field & B.field;
    return result;
}

Set setDifferenceSet(Set A, Set B) {
    Set result;
    result.field = A.field & (~B.field);
    return result;
}

void displaySet(Set set) {
    printf("{ ");
    for (int i = 0; i < MAX_BITS; i++) {
        if (set.field & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int main() {
    Set A, B;

    initializeSet(&A);
    initializeSet(&B);

    insertSet(&A, 0);
    insertSet(&A, 2);
    insertSet(&A, 7);

    insertSet(&B, 2);
    insertSet(&B, 4);
    insertSet(&B, 7);

    printf("Set A: ");
    displaySet(A);
    printf("Set B: ");
    displaySet(B);

    printf("Union: ");
    displaySet(setUnionSet(A, B));

    printf("Intersection: ");
    displaySet(setIntersectionSet(A, B));

    printf("Difference A-B: ");
    displaySet(setDifferenceSet(A, B));

    return 0;
}
