#pragma once
#include "line.h"
#include <stddef.h>

#define TABLE_SIZE 100

typedef struct Entry {
  char *key;
  ParsedLine *values;
  size_t value_count;
  struct Entry *next;
} Entry;

typedef struct Dictionary {
  Entry *table[TABLE_SIZE];
} Dictionary;

Dictionary *create_dictionary();
void insert(Dictionary *dict, const char *key, ParsedLine *values,
            size_t value_count);
ParsedLine *lookup(Dictionary *dict, const char *key, size_t *value_count);
void free_dictionary(Dictionary *dict);