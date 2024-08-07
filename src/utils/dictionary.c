#include "../../include/dictionary.h"
#include "../../include/errors.h"
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

void insert(Dictionary *dict, const string key, const VALUE_TYPE value) {
  string current_value;
  unsigned int index;
  Entry *new_entry;
  printf("➕📖 Inserting to key: %s, value: %s\n", key, value);
  current_value = lookup(dict, key);
  if (current_value != NULL) {
    fprintf(stderr, DOUBLE_LABEL_DECLARATION_ERROR);
    exit(DOUBLE_LABEL_DECLARATION_ERROR_CODE);
  }
  free(current_value);
  current_value = NULL;
  index = hash(key);
  new_entry = (Entry *)malloc(sizeof(Entry));
  if (new_entry == NULL) {
    fprintf(stderr, "Unable to allocate memory for new entry.\n");
    exit(EXIT_FAILURE);
  }

  new_entry->key = strdup(key);
  new_entry->value = strdup(value);
  new_entry->next = dict->table[index];
  dict->table[index] = new_entry;
}
VALUE_TYPE lookup(Dictionary *dict, const string key) {
  /*printf("🔍📖 Looking up key: %s\n", key); */
  unsigned int index = hash(key);
  Entry *entry = dict->table[index];

  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      /* printf("🔍📖 Found key: %s, value: %s\n", entry->key, entry->value); */
      VALUE_TYPE value = entry->value;
      return value;
    }
    entry = entry->next;
  }

  /* printf("🔍📖❌ Not found key: %s\n", key); */
  return NULL;
}
void free_dictionary(Dictionary *dict) {
  int i;
  for (i = 0; i < TABLE_SIZE; i++) {
    Entry *entry = dict->table[i];
    while (entry != NULL) {
      Entry *temp = entry;
      entry = entry->next;
      free(temp->key);
      free(temp->value);
      free(temp);
    }
  }
  free(dict);
}

void update(Dictionary *dict, const string key, const VALUE_TYPE new_value) {
  unsigned int index = hash(key);
  Entry *entry = dict->table[index];

  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      char *new_value_copy = strdup(new_value);
      if (new_value_copy == NULL) {
        fprintf(stderr, "Unable to allocate memory for new value.\n");
        exit(EXIT_FAILURE);
      }
      entry->value = new_value_copy;
      return;
    }
    entry = entry->next;
  }

  insert(dict, key, new_value);
}
