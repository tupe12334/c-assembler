#include "../../include/string.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string str_append(string string_a, string string_b) {
  string new_str =
      (string)malloc((strlen(string_a) + strlen(string_b) + 1) * sizeof(char));
  strcpy(new_str, string_a);
  strcat(new_str, string_b);
  return new_str;
}

int has_comma(const string str) { return strchr(str, ',') != NULL; }

string ltrim_x_chars(string str, int x) {
  size_t len;
  if (str == NULL || x <= 0)
    return str;

  len = strlen(str);
  if ((size_t)x >= len)
    return str;

  memmove(str, str + x, len - x + 1);
  return str;
}

string ltrim(string s) {
  while (isspace((unsigned char)*s))
    s++;
  return s;
}

string rtrim(const string str) {
  string trimmed;
  int n = strlen(str);

  while (n > 0 && isspace((unsigned char)str[n - 1])) {
    n--;
  }

  trimmed = (string)malloc(n + 1);
  if (trimmed == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  strncpy(trimmed, str, n);
  trimmed[n] = '\0';

  return trimmed;
}

string trim(string str) { return ltrim(rtrim(str)); }
