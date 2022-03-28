#ifndef VK_EDUCATION_HISTOGRAM_H
#define VK_EDUCATION_HISTOGRAM_H

#define VECTOR_EXTENSION  2

#include <stdio.h>
#include <stdlib.h>

typedef struct histogram {
    size_t size; // размер массивов указателей на уникальные числа и счетчика
    size_t maxSize; // выделенная память под массив указателей и массив счетчика
    size_t extension; // коэффициент насколько увеличивать выделяемую память при релоцировании
    int **arrayPointers; // массив указателей на уникальные числа
    int **arrayCounter; // массив счетчика количества уникальных чисел
} histogram;

// конструктор, но если size = 0, то создаем с size = 1
histogram *histogram_constructor(size_t size);

// расширение массив указателей
void histogram_extend(histogram *vector);

// добавление указателя на уникальный элемент
void histogram_append(histogram *vector, int *pointer);


#endif
