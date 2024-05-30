#pragma once
#include <stddef.h>

typedef struct {
  char *str;
  size_t size;
} DynamicString;
void initDynamicString(DynamicString *dstr);
void strcatDynamicString(DynamicString *dstr, const char *newStr);
void freeDynamicString(DynamicString *dstr);
