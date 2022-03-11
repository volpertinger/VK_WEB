#include "../Headers/Vector.h"

Vector *Vector_constructor(size_t size) {
    Vector *result = malloc(sizeof(Vector));
    result->sizePointers = 0;
    result->sizeCounter = 0;
    if (size == 0)
        size = 1;
    result->maxSizePointers = size;
    result->maxSizeCounter = size;
    result->extension = VECTOR_EXTENSION;
    result->arrayPointers = malloc(sizeof(int *) * result->maxSizePointers);
    result->arrayCounter = malloc(sizeof(int) * result->maxSizeCounter);
    return result;
}

void Vector_destructor(Vector *vector) {
    //if (vector->array != NULL) {
    //   free(vector->array);
    //   vector->array = NULL;
    //}
    free(vector);
}

void Vector_extendPointers(Vector *vector) {
    vector->maxSizePointers = vector->maxSizePointers * vector->extension;
    int **newArray = malloc(sizeof(int *) * vector->maxSizePointers);
    for (size_t i = 0; i < vector->sizePointers; ++i) {
        newArray[i] = vector->arrayPointers[i];
    }
    if (vector->arrayPointers != NULL) {
        free(vector->arrayPointers);
        vector->arrayPointers = NULL;
    }
    vector->arrayPointers = newArray;
}

void Vector_counter(Vector *vector) {
    vector->maxSizeCounter = vector->maxSizeCounter * vector->extension;
    int **newArray = malloc(sizeof(int) * vector->maxSizeCounter);
    for (size_t i = 0; i < vector->sizeCounter; ++i) {
        newArray[i] = vector->arrayCounter[i];
    }
    if (vector->arrayCounter != NULL) {
        free(vector->arrayCounter);
        vector->arrayCounter = NULL;
    }
    vector->arrayCounter = newArray;
}

void Vector_appendPointer(Vector *vector, int *element) {
    if (vector->sizePointers >= vector->maxSizePointers) {
        Vector_extendPointers(vector);
    }
    vector->arrayPointers[vector->sizePointers] = element;
    ++vector->sizePointers;
}

void Vector_appendCounter(Vector *vector, int element) {
    if (vector->sizeCounter >= vector->maxSizeCounter) {
        Vector_counter(vector);
    }
    int *newElement = malloc(sizeof(int));
    *newElement = element;
    vector->arrayCounter[vector->sizeCounter] = newElement;
    ++vector->sizeCounter;
}