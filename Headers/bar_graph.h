#ifndef UNTITLED_BARGRAPH_H
#define UNTITLED_BARGRAPH_H

#include "histogram.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Получаем индекс элемента (поиск по значению) в массиве уникальных элементов.
// Если такого нет, то возвращается -1.
int unique_element_index(int element, histogram *vector);

// Получаем по массиву исходных чисел два - один с указателями на уникальные элементы,
// другой - с их количеством.
// Также значение size меняется на количество исходных элементов
int ***get_bar_graph(int **array, int *size);

// Читает данные из файла, где первый символ - размер массива, остальные - элементы массива.
// Возвращает двойной
// указатель. Первый - на размер массива, второй - на сам массив.
int ***scan_array(FILE *input);

// Красивый вывод графа в файл. Для этого на вход подаем указатели на массивы
// уникальных чисел и счетчик, имя файла вывода
// вывод: 1 - вывод не удался, 0 - все ок
int print_graph(FILE *output, int **counter, int **elementsPointer, int size);

#endif
