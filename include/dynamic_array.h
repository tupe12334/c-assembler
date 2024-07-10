#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define DYNAMIC_ARRAY_DATA_TYPE int

typedef struct {
  int *data;
  size_t size;
  size_t capacity;
  int data_lines;
} DynamicArray;

void darray_init(DynamicArray *list, size_t initialCapacity);
void darray_append(DynamicArray *array, int value, bool is_data);
void darray_free(DynamicArray *list);
void darray_print(DynamicArray *list);
int darray_code_lines(DynamicArray *array);
int darray_data_lines(DynamicArray *array);
