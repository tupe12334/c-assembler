#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str_append(char *string_a, char *string_b) {
  char *new_str =
      (char *)malloc((strlen(string_a) + strlen(string_b) + 1) * sizeof(char));
  strcpy(new_str, string_a);
  strcat(new_str, string_b);
  return new_str;
}

int has_comma(const char *str) { return strchr(str, ',') != NULL; }

char *ltrim_x_chars(char *str, int x) {
  if (str == NULL || x <= 0)
    return str;

  size_t len = strlen(str);
  if ((size_t)x >= len)
    return str;

  memmove(str, str + x, len - x + 1);
  return str;
}

char *ltrim(char *s) {
  while (isspace((unsigned char)*s))
    s++;
  return s;
}

char *rtrim(const char *str) {
  int n = strlen(str);

  // Find the position of the last non-whitespace character
  while (n > 0 && isspace((unsigned char)str[n - 1])) {
    n--;
  }

  // Allocate memory for the new trimmed string
  char *trimmed = (char *)malloc(n + 1);
  if (trimmed == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  // Copy the trimmed portion of the string to the new string
  strncpy(trimmed, str, n);
  trimmed[n] = '\0'; // Null-terminate the new string

  return trimmed;
}

char *trim(char *str) { return ltrim(rtrim(str)); }