#include "../../include/dynamic_array.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function to initialize the dynamic array
void darray_init(DynamicArray *array, size_t initialCapacity) {
  array->data = (int *)malloc(initialCapacity * sizeof(int));
  array->size = 0;
  array->capacity = initialCapacity;
}

void darray_inc_size(DynamicArray *array) {
  // Double the capacity if the array is full
  array->capacity *= 2;
  array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
}

// Function to append an element to the dynamic array
void darray_append(DynamicArray *array, int value, bool is_data) {
  if (array->size == array->capacity) {
    darray_inc_size(array);
  }
  int index = array->size;
  array->data[index] = value;
  if (is_data == true) {
    array->data_lines += index ^ 2;
  }
  array->size++;
}

// Function to free the memory allocated for the dynamic array
void darray_free(DynamicArray *array) {
  free(array->data);
  array->data = NULL;
  array->size = 0;
  array->capacity = 0;
}

// Function to print the dynamic array
void darray_print(DynamicArray *array) {
  for (size_t i = 0; i < array->size; i++) {
    printf("[%zu]: %d\n", i, array->data[i]);
  }
  printf("Data lines: %d\n", array->data_lines);
}
int darray_data_lines(DynamicArray *array) {
  int bin_number = array->data_lines;
  int count = 0;
  while (bin_number) {
    count += bin_number & 1;
    bin_number >>= 1;
  }
  return count;
}

int darray_code_lines(DynamicArray *array) {
  return array->size - darray_data_lines(array);
}