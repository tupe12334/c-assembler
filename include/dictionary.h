#pragma once
#include "line.h"
#include <stddef.h>

#define TABLE_SIZE 100

typedef struct Entry {
  char *key;
  char *value;
  struct Entry *next;
} Entry;

typedef struct Dictionary {
  Entry *table[TABLE_SIZE];
} Dictionary;

unsigned int hash(const char *key);
Dictionary *create_dictionary();
void insert(Dictionary *dict, const char *key, const char *value);
char *lookup(Dictionary *dict, const char *key);
void free_dictionary(Dictionary *dict);
