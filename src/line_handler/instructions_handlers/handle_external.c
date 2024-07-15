#include "../../../include/dynamic_array.h"
#include "../../../include/line.h"
#include <stdio.h>

void handle_externals(DynamicArray *program, ParsedLine *parsed_line) {
  puts("Got externals");
  puts(parsed_line->tokens.line);
}
