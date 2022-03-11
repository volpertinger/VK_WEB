//Составить программу расчета гистограммы, отражающей, сколько раз каждое число встречается в заданном массиве целых чисел.
// Расчет оформить в виде функции, получающей на вход массив указателей на целые числа.
// На выход функция должна вернуть массив из двух указателей на массивы указателей (тройной указатель).
// Первый массив должен содержать указатели на встречающиеся во входном массиве числа. Второй — количество повторений числа,
// расположенного в первом массиве под тем же индексом.//

#include <stdio.h>
#include <stdlib.h>
#include "../Headers/BarGraph.h"

int main() {
    /*
    printf("Enter size of array\n");
    int size = 0;
    scanf("%d", &size);
    int *array = malloc(sizeof(int) * size);
    printf("%s", "Enter array numbers\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }

    printf("printing array\n");
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
*/
    const size_t size = 5;
    int array[] = {19, 1, 10, 1, 1};
    int ***result = getBarGraph(array, size);
    printGraph(result[0], result[1], size);
    if (result[0] != NULL)
        free(result[0]);
    if (result[1] != NULL)
        free(result[1]);
    return 0;
}
