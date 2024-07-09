#include "../../include/daynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

DynamicArray *createDynamicArray(size_t initialCapacity) {
  DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
  if (arr == NULL) {
    return NULL;
  }

  arr->array = (int *)malloc(initialCapacity * sizeof(int));
  if (arr->array == NULL) {
    free(arr);
    return NULL;
  }

  arr->size = 0;
  arr->capacity = initialCapacity;
  return arr;
}

void freeDynamicArray(DynamicArray *arr) {
  if (arr) {
    free(arr->array);
    free(arr);
  }
}

int resize(DynamicArray *arr) {
  size_t newCapacity = arr->capacity * 2;
  int *newArray = (int *)realloc(arr->array, newCapacity * sizeof(int));
  if (newArray == NULL) {
    return 0; // Resize failed
  }

  arr->array = newArray;
  arr->capacity = newCapacity;
  return 1; // Resize successful
}

int array_insert(DynamicArray *arr, int element) {
  if (arr->size == arr->capacity) {
    if (!resize(arr)) {
      return 0; // Insert failed
    }
  }

  arr->array[arr->size++] = element;
  return 1; // Insert successful
}

int get(DynamicArray *arr, size_t index, int *element) {
  if (index >= arr->size) {
    return 0; // Invalid index
  }

  *element = arr->array[index];
  return 1; // Get successful
}

void printArray(DynamicArray *arr) {
  printf("Array (size=%zu, capacity=%zu): ", arr->size, arr->capacity);
  for (size_t i = 0; i < arr->size; i++) {
    printf("%d ", arr->array[i]);
  }
  printf("\n");
}