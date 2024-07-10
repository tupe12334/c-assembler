#include <stdlib.h>
#include <string.h>

char *str_append(char *string_a, char *string_b) {
  char *new_filename =
      (char *)malloc((strlen(string_a) + strlen(string_b) + 1) * sizeof(char));
  strcpy(new_filename, string_a);
  strcat(new_filename, string_b);
  return new_filename;
}