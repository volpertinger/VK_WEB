#ifndef UNTITLED_BARGRAPH_H
#define UNTITLED_BARGRAPH_H

#include "Vector.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Получаем индекс элемента (поиск по значению) в массиве уникальных элементов. Если такого нет, то возвращается -1.
int uniqueElementIndex(int element, Vector *vector);

// Получаем по массиву исходных чисел два - один с указателями на уникальные элементы, другой - с их количеством.
int ***getBarGraph(int *array, size_t size);

// Красивый вывод графа в консоль. Для этого на вход подаем указатели на массивы уникальных чисел и счетчик.
void printGraph(int **counter, int **elementsPointer, size_t size);

#endif //UNTITLED_BARGRAPH_H
