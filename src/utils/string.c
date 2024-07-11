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