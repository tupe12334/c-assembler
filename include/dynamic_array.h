#pragma once
#include <stdio.h>
#include <stdlib.h>

#define DYNAMIC_ARRAY_DATA_TYPE int

typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} DynamicArray;

void darray_init(DynamicArray *list, size_t initialCapacity);
void darray_append(DynamicArray *list, int value);
void darray_free(DynamicArray *list);
void darray_print(DynamicArray *list);
