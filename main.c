//Составить программу расчета гистограммы, отражающей, сколько раз каждое число встречается в заданном массиве
// целых чисел. Расчет оформить в виде функции, получающей на вход массив указателей на целые числа.
// На выход функция должна вернуть массив из двух указателей на массивы указателей (тройной указатель).
// Первый массив должен содержать указатели на встречающиеся во входном массиве числа. Второй — количество повторений
// числа, расположенного в первом массиве под тем же индексом.

#include <stdio.h>
#include <stdlib.h>
#include "Headers/bar_graph.h"

#define MAX_PATH 260

int main() {
    printf("Correct input: {input filename} {output filename}\n "
           "Input file: {array size} {array integer elements}\n");
    char filenameInput[MAX_PATH];
    char filenameOutput[MAX_PATH];
    scanf("%s %s", filenameInput, filenameOutput);


    FILE *inputFile;
    if ((inputFile = fopen(filenameInput, "r")) == NULL)
        return 1;
    int ***input = scan_array(inputFile);
    if (input == NULL) {
        fprintf(stderr, "%s : Wrong file data\n", filenameInput);
        return 1;
    }
    int *size = *input[0];
    int **array = input[1];

    int ***result = get_bar_graph(array, size);
    FILE *fileOutput;
    fileOutput = fopen(filenameOutput, "w");
    if (print_graph(fileOutput, result[1], result[0], *size) == 1) {
        fprintf(stderr, "%s : Wrong file\n", filenameOutput);
        return 1;
    }
    for (int i = 0; i < *size; ++i) {
        free(result[0][i]);
        free(result[1][i]);
    }
    free(input[1]);
    free(result[0]);
    free(result[1]);
    free(result);

    fclose(inputFile);
    fclose(fileOutput);
    return 0;
}
