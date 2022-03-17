//Составить программу расчета гистограммы, отражающей, сколько раз каждое число встречается в заданном массиве
// целых чисел. Расчет оформить в виде функции, получающей на вход массив указателей на целые числа.
// На выход функция должна вернуть массив из двух указателей на массивы указателей (тройной указатель).
// Первый массив должен содержать указатели на встречающиеся во входном массиве числа. Второй — количество повторений
// числа, расположенного в первом массиве под тем же индексом.

#include <stdio.h>
#include <stdlib.h>
#include "Headers/BarGraph.h"

#define MAX_PATH 260

int main() {

    printf("Correct input: {input filename} {output filename}\n "
           "Input file: {array size} {array integer elements}\n");
    char filenameInput[MAX_PATH];
    char filenameOutput[MAX_PATH];
    scanf("%s %s", filenameInput, filenameOutput);


    FILE *inputFile;
    inputFile = fopen(filenameInput, "r");
    int ***input = scanArray(inputFile);
    fclose(inputFile);
    if (input == NULL) {
        fprintf(stderr, "%s : Wrong file data\n", filenameInput);
        return 1;
    }

    int ***result = getBarGraph(input[1], *input[0]);
    FILE *fileOutput;
    fileOutput = fopen(filenameOutput, "w");
    if (printGraph(fileOutput, result[0], result[1], **input[0]) == 1) {
        fprintf(stderr, "%s : Wrong file\n", filenameOutput);
        return 1;
    }
    fclose(filenameOutput);
    for (int i = 0; i < 1; ++i) {
        if (result[i] != NULL)
            free(result[i]);
        if (input[i] != NULL)
            free(input[i]);
    }
    return 0;
}
