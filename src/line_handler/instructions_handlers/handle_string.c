#include "../../../include/dynamic_array.h"
#include "../../../include/line.h"
#include "../../../include/string.h"
#include <stdio.h>
#include <string.h>

void handle_string(DynamicArray *program, ParsedLine *parsed_line) {
  string value = trim(parsed_line->tokens.value);
  int length = strlen(value);
  int i;
  for (i = 1; i < length - 1; i++) {
    darray_append(program, value[i], true);
  }

  darray_append(program, 0, true);
}
