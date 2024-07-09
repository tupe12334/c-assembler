#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int *array;
  size_t size;
  size_t capacity;
} DynamicArray;

DynamicArray *createDynamicArray(size_t initialCapacity);
void freeDynamicArray(DynamicArray *arr);
int resize(DynamicArray *arr);
int array_insert(DynamicArray *arr, int element);
int get(DynamicArray *arr, size_t index, int *element);
void printArray(DynamicArray *arr);
