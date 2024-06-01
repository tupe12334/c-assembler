#include "../../include/regex.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPERATION_REGEX "^[a-zA-Z_\\.][a-zA-Z0-9_]*"

char *parse_operation(char *line, int *line_cursor) {
  char *type;
  char *substring = malloc(strlen(line) - sizeof(char) * (*line_cursor));
  skip_white_spaces(line, line_cursor);
  strcpy(substring, line + *line_cursor);

  type = extract_word(substring, OPERATION_REGEX);
  *line_cursor = *line_cursor + strlen(type);
  return type;
}
