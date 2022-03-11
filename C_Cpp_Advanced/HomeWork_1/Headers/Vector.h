#ifndef VK_EDUCATION_VECTOR_H
#define VK_EDUCATION_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#define VECTOR_EXTENSION  2;

typedef struct Vector {
    size_t size; // размер массивов указателей на уникальные числа и счетчика
    size_t maxSize; // выделенная память под массив указателей и массив счетчика
    size_t extension; // коэффициент насколько увеличивать выделяемую память при релоцировании
    int **arrayPointers; // массив указателей на уникальные числа
    int **arrayCounter; // массив счетчика количества уникальных чисел
} Vector;

// конструктор, но если size = 0, то создаем с size = 1
Vector *Vector_constructor(size_t size);

// деструктор
void Vector_destructor(Vector *vector);

// расширение массив указателей
void Vector_extend(Vector *vector);

// добавление указатель на элемент
void Vector_append(Vector *vector, int *pointer);


#endif
