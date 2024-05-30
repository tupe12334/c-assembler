#include "../include/dynamic_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initDynamicString(DynamicString *dstr) {
  dstr->size = 1;
  puts("dsaflkhlkadsfhlk0");
  dstr->str = (char *)malloc(dstr->size);
  if (dstr->str == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  dstr->str[0] = '\0';
}

void strcatDynamicString(DynamicString *dstr, const char *newStr) {
  size_t newLen = strlen(newStr);
  dstr->size += newLen;
  dstr->str = (char *)realloc(dstr->str, dstr->size);
  if (dstr->str == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  strcat(dstr->str, newStr);
}

void freeDynamicString(DynamicString *dstr) {
  free(dstr->str);
  dstr->str = NULL;
  dstr->size = 0;
}
