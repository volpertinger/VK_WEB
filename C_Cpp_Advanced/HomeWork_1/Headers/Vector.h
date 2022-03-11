#ifndef VK_EDUCATION_VECTOR_H
#define VK_EDUCATION_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#define VECTOR_EXTENSION  2;

typedef struct Vector {
    size_t sizePointers; // размер массива указателей на уникальные числа
    size_t sizeCounter; // размер массива счетчика количества уникальных чисел
    size_t maxSizePointers; // выделенная память под массив указателей
    size_t maxSizeCounter;  // выделенная память под массив счетчика
    size_t extension; // коэффициент насколько увеличивать выделяемую память при релоцировании
    int **arrayPointers; // массив указателей на уникальные числа
    int **arrayCounter; // массив счетчика количества уникальных чисел
} Vector;

// конструктор, но если size = 0, то создаем с size = 1
Vector *Vector_constructor(size_t size);

// деструктор
void Vector_destructor(Vector *vector);

// расширение массив указателей
void Vector_extendPointers(Vector *vector);

// расширение массива счетчика
void Vector_counter(Vector *vector);

// добавление указатель на элемент
void Vector_appendPointer(Vector *vector, int *element);

// добавление счетчика с исходным значением = element
void Vector_appendCounter(Vector *vector, int element);


#endif
