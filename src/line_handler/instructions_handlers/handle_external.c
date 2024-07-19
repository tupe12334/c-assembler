#include "../../../include/dynamic_array.h"
#include "../../../include/line.h"
#include "../../../include/program.h"
#include <stdio.h>

void handle_externals(Program *program, ParsedLine *parsed_line) {
  puts("Got externals");
  puts(parsed_line->tokens.line);
}
