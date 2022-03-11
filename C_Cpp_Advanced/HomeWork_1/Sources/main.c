//Составить программу расчета гистограммы, отражающей, сколько раз каждое число встречается в заданном массиве
// целых чисел. Расчет оформить в виде функции, получающей на вход массив указателей на целые числа.
// На выход функция должна вернуть массив из двух указателей на массивы указателей (тройной указатель).
// Первый массив должен содержать указатели на встречающиеся во входном массиве числа. Второй — количество повторений
// числа, расположенного в первом массиве под тем же индексом.

#include <stdio.h>
#include <stdlib.h>
#include "../Headers/BarGraph.h"

int main() {
    char *filenameInput = "/home/killoboker/CLionProjects/untitled/C_Cpp_Advanced/HomeWork_1/IO/Input/input01";
    char *filenameOutput = "/home/killoboker/CLionProjects/untitled/C_Cpp_Advanced/HomeWork_1/IO/Output/output01";
    int **input = scanArray(filenameInput);
    if (input == NULL) {
        fprintf(stderr, "%s : Wrong file data", filenameInput);
        return 1;
    }

    int ***result = getBarGraph(input[1], input[0]);
    printGraph(result[0], result[1], *input[0], filenameOutput);
    for (int i = 0; i < 1; ++i) {
        if (result[i] != NULL)
            free(result[i]);
        if (input[i] != NULL)
            free(input[i]);
    }

    return 0;
}
