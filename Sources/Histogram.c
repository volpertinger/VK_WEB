#include "../Headers/Histogram.h"


Histogram *Histogram_constructor(size_t size) {
    Histogram *result;
    result = malloc(sizeof(Histogram));
    result->size = 0;
    result->maxSize = size;
    result->extension = VECTOR_EXTENSION;
    if (size != 0) {
        result->arrayPointers = malloc(sizeof(int *) * result->maxSize);
        result->arrayCounter = malloc(sizeof(int) * result->maxSize);
    } else {
        result->arrayPointers = NULL;
        result->arrayCounter = NULL;
    }
    return result;
}

void Histogram_extend(Histogram *vector) {
    vector->maxSize = vector->maxSize * vector->extension + 1;
    int **newArrayPointers;
    newArrayPointers = malloc(sizeof(int *) * vector->maxSize);
    int **newArrayCounter;
    newArrayCounter = malloc(sizeof(int *) * vector->maxSize);
    for (size_t i = 0; i < vector->size; ++i) {
        newArrayPointers[i] = vector->arrayPointers[i];
        newArrayCounter[i] = vector->arrayCounter[i];
    }
    free(vector->arrayPointers);
    free(vector->arrayCounter);
    vector->arrayPointers = newArrayPointers;
    vector->arrayCounter = newArrayCounter;
}


void Histogram_append(Histogram *vector, int *pointer) {
    if (vector->size >= vector->maxSize) {
        Histogram_extend(vector);
    }
    vector->arrayPointers[vector->size] = pointer;
    int *newElement;
    newElement = malloc(sizeof(int));
    *newElement = 1;
    vector->arrayCounter[vector->size] = newElement; // у только что добавленного элемента счетчик = 1
    ++(vector->size);
}
