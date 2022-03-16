#include "../Headers/BarGraph.h"


int uniqueElementIndex(int element, Vector *vector) {
    for (size_t i = 0; i < vector->size; ++i) {
        if (element == *vector->arrayPointers[i])
            return (int) i;
    }
    return -1;
}

int ***getBarGraph(int **array, int *size) {
    if (size < 0)
        return NULL;
    Vector *vector = Vector_constructor(0);
    for (size_t i = 0; i < *size; ++i) {
        int index = uniqueElementIndex(*array[i], vector);
        if (index == -1) {
            Vector_append(vector, array[i]);
            continue;
        }
        ++(*vector->arrayCounter[index]);
    }
    int ***result = malloc(sizeof(int ***) * 2);
    result[1] = vector->arrayCounter;
    result[0] = vector->arrayPointers;
    *size = (int) vector->size;
    Vector_partDestructor(vector);
    return result;
}

int ***scanArray(FILE *input) {
    if (input == NULL) {
        return NULL;
    }
    int *size = malloc(sizeof(int));
    if (fscanf(input, "%d", size) == EOF)
        return NULL;
    int *array = malloc(sizeof(int) * (*size));
    for (size_t i = 0; i < *size; ++i) {
        if (fscanf(input, "%d", &array[i]) == EOF)
            return NULL;
    }
    fclose(input);
    int ***result = malloc(sizeof(int **) * 2);
    result[0] = &size;
    result[1] = &array;
    return result;
}

int printGraph(FILE *output, int **counter, int **elementsPointer, int size) {
    if (output == NULL)
        return 1;
    for (size_t i = 0; i < size; ++i) {
        fprintf(output, "number %d", *elementsPointer[i]);
        fprintf(output, " : ");
        fprintf(output, "%d time(s)", *counter[i]);
        fprintf(output, "%c", '\n');
    }
    fclose(output);
    return 0;
}
