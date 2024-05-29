#include "../include/dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int hash(const char *key) {
  unsigned int hash = 0;
  while (*key) {
    hash = (hash << 5) + *key++;
  }
  return hash % TABLE_SIZE;
}

Dictionary *create_dictionary(void) {
  int i;
  Dictionary *dict = (Dictionary *)malloc(sizeof(Dictionary));
  if (dict == NULL) {
    fprintf(stderr, "Unable to allocate memory for dictionary.\n");
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < TABLE_SIZE; i++) {
    dict->table[i] = NULL;
  }

  return dict;
}
void insert(Dictionary *dict, const char *key, ParsedLine *values,
            size_t value_count) {
  unsigned int index = hash(key);
  Entry *new_entry = (Entry *)malloc(sizeof(Entry));
  if (new_entry == NULL) {
    fprintf(stderr, "Unable to allocate memory for new entry.\n");
    exit(EXIT_FAILURE);
  }

  new_entry->key = strdup(key);
  new_entry->values = (ParsedLine *)malloc(value_count * sizeof(ParsedLine));
  if (new_entry->values == NULL) {
    fprintf(stderr, "Unable to allocate memory for values.\n");
    exit(EXIT_FAILURE);
  }
  memcpy(new_entry->values, values, value_count * sizeof(ParsedLine));
  new_entry->value_count = value_count;
  new_entry->next = dict->table[index];
  dict->table[index] = new_entry;
}

ParsedLine *lookup(Dictionary *dict, const char *key, size_t *value_count) {
  unsigned int index = hash(key);
  Entry *entry = dict->table[index];

  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      *value_count = entry->value_count;
      return entry->values;
    }
    entry = entry->next;
  }

  *value_count = 0;
  return NULL;
}
void free_dictionary(Dictionary *dict) {
  int i;
  size_t j;
  for (i = 0; i < TABLE_SIZE; i++) {
    Entry *entry = dict->table[i];
    while (entry != NULL) {
      Entry *temp = entry;
      entry = entry->next;
      free(temp->key);
      for (j = 0; j < temp->value_count; j++) {
        free(temp->values[j].label);
        free(temp->values[j].type);
        free(temp->values[j].value);
      }
      free(temp->values);
      free(temp);
    }
  }
  free(dict);
}
