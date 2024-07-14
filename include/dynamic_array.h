#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define DYNAMIC_ARRAY_DATA_TYPE int

typedef short int array_data;

typedef struct {
  array_data *data;
  size_t size;
  size_t capacity;
  int data_lines;
  int code_lines;
} DynamicArray;

void darray_init(DynamicArray *list, size_t initialCapacity);
void darray_append(DynamicArray *array, array_data decimal_value, bool is_data);
void darray_free(DynamicArray *list);
void darray_print(DynamicArray *list);
int darray_code_lines(DynamicArray *array);
int darray_data_lines(DynamicArray *array);
