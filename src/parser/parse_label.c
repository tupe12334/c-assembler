#include "../../include/regex.h"
#include <stdlib.h>
#include <string.h>

#define LABEL_REGEX "^[A-Z]+:"

string parse_label(string line, int *line_cursor) {
  string label_without_colon;
  string label = extract_word(line, LABEL_REGEX);
  if (label == NULL) {
    return NULL;
  }
  label_without_colon = malloc(strlen(label) - sizeof(char));
  strncpy(label_without_colon, label, strlen(label) - 1);
  *line_cursor = strlen(label) + 1;
  return label_without_colon;
}
