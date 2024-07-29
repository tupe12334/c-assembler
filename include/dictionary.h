#pragma once
#include "line.h"
#include <stddef.h>

#define TABLE_SIZE 100

#define VALUE_TYPE string

typedef struct Entry {
  string key;
  VALUE_TYPE value;
  struct Entry *next;
} Entry;

typedef struct Dictionary {
  Entry *table[TABLE_SIZE];
} Dictionary;

unsigned int hash(const char *key);
Dictionary *create_dictionary(void);
void insert(Dictionary *dict, const string key, const VALUE_TYPE value);
VALUE_TYPE lookup(Dictionary *dict, const string key);
void free_dictionary(Dictionary *dict);
void update(Dictionary *dict, const string key, const VALUE_TYPE new_value);
