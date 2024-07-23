#include "../../include/dictionary.h"
#include "../../include/bool.h"
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
  printf("➕📖 Inserting to key: %s, value: %s\n", key, value);
  unsigned int index = hash(key);
  Entry *new_entry = (Entry *)malloc(sizeof(Entry));
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
  printf("🔍📖 Looking up key: %s\n", key);
  unsigned int index = hash(key);
  Entry *entry = dict->table[index];

  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      printf("🔍📖 Found key: %s, value: %s\n", entry->key, entry->value);
      VALUE_TYPE value = entry->value;
      return value;
    }
    entry = entry->next;
  }

  printf("🔍📖❌ Not found key: %s\n", key);
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
