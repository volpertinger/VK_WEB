#include "../Headers/Vector.h"


Vector *Vector_constructor(size_t size) {
    Vector *result = malloc(sizeof(Vector));
    result->size = 0;
    if (size == 0)
        size = 1;
    result->maxSize = size;
    result->extension = VECTOR_EXTENSION;
    result->arrayPointers = malloc(sizeof(int *) * result->maxSize);
    result->arrayCounter = malloc(sizeof(int) * result->maxSize);
    return result;
}

void Vector_destructor(Vector *vector) {
    //if (vector->array != NULL) {
    //   free(vector->array);
    //   vector->array = NULL;
    //}
    free(vector);
    vector = NULL;
}

void Vector_extend(Vector *vector) {
    vector->maxSize = vector->maxSize * vector->extension;
    int **newArrayPointers = malloc(sizeof(int *) * vector->maxSize);
    int **newArrayCounter = malloc(sizeof(int *) * vector->maxSize);
    for (size_t i = 0; i < vector->size; ++i) {
        newArrayPointers[i] = vector->arrayPointers[i];
        newArrayCounter[i] = vector->arrayCounter[i];
    }
    if (vector->arrayPointers != NULL) {
        free(vector->arrayPointers);
        vector->arrayPointers = NULL;
    }
    if (vector->arrayCounter != NULL) {
        free(vector->arrayCounter);
        vector->arrayCounter = NULL;
    }
    vector->arrayPointers = newArrayPointers;
    vector->arrayCounter = newArrayCounter;
}


void Vector_append(Vector *vector, int *element) {
    if (vector->size >= vector->maxSize) {
        Vector_extend(vector);
    }
    vector->arrayPointers[vector->size] = element;
    int *newElement = malloc(sizeof(int));
    *newElement = 1;
    vector->arrayCounter[vector->size] = newElement; // у только что добавленного элемента счетчик = 1
    ++vector->size;
}
