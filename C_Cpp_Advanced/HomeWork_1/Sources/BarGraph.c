#include "../Headers/BarGraph.h"

int uniqueElementIndex(int element, Vector *vector) {
    for (size_t i = 0; i < vector->sizePointers; ++i) {
        if (element == *vector->arrayPointers[i])
            return (int) i;
    }
    return -1;
}

int ***getBarGraph(int *array, size_t size) {
    Vector *vector = Vector_constructor(0);
    for (size_t i = 0; i < size; ++i) {
        int index = uniqueElementIndex(array[i], vector);
        if (index == -1) {
            Vector_appendPointer(vector, &array[i]);
            Vector_appendCounter(vector, 1);
            continue;
        }
        ++*vector->arrayCounter[index];
    }
    int ***result = malloc(sizeof(int ***) * 2);
    result[0] = vector->arrayCounter;
    result[1] = vector->arrayPointers;
    Vector_destructor(vector);
    return result;
}

void printGraph(int **counter, int **elementsPointer, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("number %d", *elementsPointer[i]);
        printf(" : ");
        printf("%d time(s)", *counter[i]);
        printf("%c", '\n');
    }
}