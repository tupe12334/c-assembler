#include "../../include/string.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string get_value(string line, int *line_cursor) {
  string substring = malloc(strlen(line) - sizeof(char) * (*line_cursor));
  skip_white_spaces(line, line_cursor);
  strcpy(substring, line + *line_cursor);
  substring = rtrim(substring);

  *line_cursor = *line_cursor + strlen(substring);
  return substring;
}
