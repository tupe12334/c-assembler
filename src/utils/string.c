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