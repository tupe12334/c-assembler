#include "../../include/dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

// Function to initialize the dynamic list
void darray_init(DynamicArray *list, size_t initialCapacity) {
  list->data = (int *)malloc(initialCapacity * sizeof(int));
  list->size = 0;
  list->capacity = initialCapacity;
}

// Function to append an element to the dynamic list
void darray_append(DynamicArray *list, int value) {
  if (list->size == list->capacity) {
    // Double the capacity if the list is full
    list->capacity *= 2;
    list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
  }
  list->data[list->size++] = value;
}

// Function to free the memory allocated for the dynamic list
void darray_free(DynamicArray *list) {
  free(list->data);
  list->data = NULL;
  list->size = 0;
  list->capacity = 0;
}

// Function to print the dynamic list
void darray_print(DynamicArray *list) {
  for (size_t i = 0; i < list->size; i++) {
    printf("[%zu]: %d\n", i, list->data[i]);
  }
}