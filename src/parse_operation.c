#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *parse_operation(char *line, int *line_cursor) {
  char *substring = malloc(strlen(line) - sizeof(char) * (*line_cursor));
  strcpy(substring, line + *line_cursor);

  skip_white_spaces(line, line_cursor);

  printf("\n%d", line[*line_cursor]);
  puts(substring);
}