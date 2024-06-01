#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_value(char *line, int *line_cursor) {
  char *substring = malloc(strlen(line) - sizeof(char) * (*line_cursor));
  skip_white_spaces(line, line_cursor);
  strcpy(substring, line + *line_cursor);

  substring = trim_last_char(substring);

  *line_cursor = *line_cursor + strlen(substring);
  return substring;
}
