#pragma once
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#define DYNAMIC_ARRAY_DATA_TYPE int

typedef short int array_data;

typedef struct {
  array_data *data;
  size_t size;
  size_t capacity;
} DynamicArray;

void darray_init(DynamicArray *list, size_t initialCapacity);
void darray_append(DynamicArray *array, array_data decimal_value);
void darray_free(DynamicArray *list);
void darray_print(DynamicArray *list);
