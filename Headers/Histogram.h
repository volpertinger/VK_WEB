#ifndef VK_EDUCATION_VECTOR_H
#define VK_EDUCATION_VECTOR_H

#define VECTOR_EXTENSION  2;

#include <stdio.h>
#include <stdlib.h>

typedef struct Histogram {
    size_t size; // размер массивов указателей на уникальные числа и счетчика
    size_t maxSize; // выделенная память под массив указателей и массив счетчика
    size_t extension; // коэффициент насколько увеличивать выделяемую память при релоцировании
    int **arrayPointers; // массив указателей на уникальные числа
    int **arrayCounter; // массив счетчика количества уникальных чисел
} Histogram;

// конструктор, но если size = 0, то создаем с size = 1
Histogram *Histogram_constructor(size_t size);

// расширение массив указателей
void Histogram_extend(Histogram *vector);

// добавление указатель на элемент
void Histogram_append(Histogram *vector, int *pointer);


#endif
