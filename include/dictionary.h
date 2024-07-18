#pragma once
#include "line.h"
#include <stddef.h>

#define TABLE_SIZE 100

typedef struct Entry {
  string key;
  string value;
  struct Entry *next;
} Entry;

typedef struct Dictionary {
  Entry *table[TABLE_SIZE];
} Dictionary;

unsigned int hash(const char *key);
Dictionary *create_dictionary(void);
void insert(Dictionary *dict, const string key, const string value);
string lookup(Dictionary *dict, const string key);
void free_dictionary(Dictionary *dict);
