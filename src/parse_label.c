#include "../include/regex.h"
#include <stdlib.h>
#include <string.h>

#define LABEL_REGEX "^[A-Z]+:"

char *parse_label(char *line, int *line_cursor) {
  char *label_without_colon;
  char *label = extract_word(line, LABEL_REGEX);
  if (label == NULL) {
    return NULL;
  }
  label_without_colon = malloc(strlen(label) - sizeof(char));
  strncpy(label_without_colon, label, strlen(label) - 1);
  *line_cursor = strlen(label) + 1;
  return label_without_colon;
}
