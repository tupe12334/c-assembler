#include "../../include/dynamic_array.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void darray_init(DynamicArray *array, size_t initialCapacity) {
  array->data = (array_data *)malloc(initialCapacity * sizeof(array_data));
  array->size = 0;
  array->capacity = initialCapacity;
}

void darray_inc_size(DynamicArray *array) {
  array->capacity *= 2;
  array->data =
      (array_data *)realloc(array->data, array->capacity * sizeof(array_data));
}

void darray_append(DynamicArray *array, array_data decimal_value,
                   bool is_data) {
  if (array->size == array->capacity) {
    darray_inc_size(array);
  }
  int index = array->size;
  array->data[index] = decimal_value;
  is_data == true ? array->data_lines++ : array->code_lines++;
  array->size++;
}

void darray_free(DynamicArray *array) {
  free(array->data);
  array->data = NULL;
  array->size = 0;
  array->capacity = 0;
}

void darray_print(DynamicArray *array) {
  for (size_t i = 0; i < array->size; i++) {
    printf("[%zu]: %d\n", i, array->data[i]);
  }
  printf("Data lines: %d\n", array->data_lines);
}
int darray_data_lines(DynamicArray *array) { return array->data_lines; }

int darray_code_lines(DynamicArray *array) { return array->code_lines; }
