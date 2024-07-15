
#include "../../include/op_codes.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void skip_white_spaces(char *line, int *line_cursor) {
  while (line[*line_cursor] == ' ' || line[*line_cursor] == '\t') {
    *line_cursor = *line_cursor + 1;
  }
}

int safe_strlen(const char *string) {
  return string != NULL ? strlen(string) : 0;
}

int array_length(char **array) {
  int i = 0;
  while (array[i] != NULL) {
    i++;
  }
  return i;
}

unsigned short int get_operator_index(char *opcode) {
  unsigned short int i, op_code_index;
  for (i = 0; i < get_op_codes_length(); i++) {
    if (strcmp(opcode, get_op_codes()[i]) == 0) {
      op_code_index = i;
    }
  }
  return op_code_index;
}
