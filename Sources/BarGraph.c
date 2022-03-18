#include "../Headers/BarGraph.h"

#define BAD_FILE_STREAM_EXIT 1
#define COMMON_RETURN 0

int unique_element_index(int element, Histogram *vector) {
    for (size_t i = 0; i < vector->size; ++i) {
        if (element == (*vector->arrayPointers[i]))
            return (int) i;
    }
    return -1;
}

int ***get_bar_graph(int **array, int *size) {
    if (size < 0 || array == NULL) {
        return NULL;
    }
    Histogram *vector = Histogram_constructor(0);
    for (size_t i = 0; i < *size; ++i) {
        int index = unique_element_index(*array[i], vector);
        if (index == -1) {
            Histogram_append(vector, array[i]);
            continue;
        }
        ++(*vector->arrayCounter[index]);
    }
    int ***result;
    result = malloc(sizeof(int ***) * 2);
    result[1] = vector->arrayCounter;
    result[0] = vector->arrayPointers;
    *size = (int) vector->size;
    free(vector);
    return result;
}

int ***scan_array(FILE *input) {
    if (input == NULL) {
        return NULL;
    }
    int *size;
    size = malloc(sizeof(int));
    if (fscanf(input, "%d", size) == EOF) {
        free(size);
        return NULL;
    }
    int **array = malloc(sizeof(int *) * (*size));
    for (size_t i = 0; i < *size; ++i) {
        int *element;
        element = malloc(sizeof(int));
        if (fscanf(input, "%d", element) == EOF) {
            free(size);
            free(array);
            return NULL;
        }
        array[i] = element;
    }
    int ***result;
    result = malloc(sizeof(int **) * 2);
    result[0] = &size;
    result[1] = array;
    return result;
}

int print_graph(FILE *output, int **counter, int **elementsPointer, int size) {
    if (output == NULL)
        return BAD_FILE_STREAM_EXIT;
    for (size_t i = 0; i < size; ++i) {
        fprintf(output, "number %d", *elementsPointer[i]);
        fprintf(output, " : ");
        fprintf(output, "%d time(s)", *counter[i]);
        fprintf(output, "%c", '\n');
    }
    return COMMON_RETURN;
}
